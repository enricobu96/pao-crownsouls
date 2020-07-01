#include "tab.h"


#include<iostream>
using std::cout;
using std::endl;

//COSTRUTTORE
Tab::Tab(QWidget *parent) : QWidget(parent), usertab(new QTabWidget()) {
    //MODEL
    model = new Model(this);
    proxy = new Proxy(this);


    //APPLICAZIONE
    horilayout = new QHBoxLayout(this);

    //BARRA LATERALE
    groupLayout = new QGridLayout;
    information = new QGroupBox("Information");
    information->setLayout(groupLayout);
    information->setHidden(true);
    createinformation();

    //LAYOUT
    horilayout->addWidget(usertab);
    horilayout->addWidget(information);

    //TABS
    armorTab = new ArmorTab(this);
    ringTab = new RingTab(this);
    shieldTab = new ShieldTab(this);
    weaponTab = new WeaponTab(this);
    usertab->addTab(armorTab,"Armors");
    usertab->addTab(ringTab, "Rings");
    usertab->addTab(shieldTab, "Shields");
    usertab->addTab(weaponTab,"Weapons");
    proxy->setSourceModel(model);
    armorTab->setModel(proxy);
    ringTab->setModel(proxy);
    shieldTab->setModel(proxy);
    weaponTab->setModel(proxy);

    updateFilterRows(0);

    //CONNECT
    connect(usertab, SIGNAL(currentChanged(int)), this, SLOT(updateFilterRows(int)));

    connect(armorTab,SIGNAL(clicked(QModelIndex)),this,SLOT(showData(QModelIndex)));
    connect(ringTab,SIGNAL(clicked(QModelIndex)),this,SLOT(showData(QModelIndex)));
    connect(shieldTab,SIGNAL(clicked(QModelIndex)),this,SLOT(showData(QModelIndex)));
    connect(weaponTab,SIGNAL(clicked(QModelIndex)),this,SLOT(showData(QModelIndex)));
}

//AGGIUNTA DI ELEMENTI
void Tab::addItem() {
    AddItem aItem("Add Item");
    if(aItem.exec()) {
        QString name = aItem.namePlaceholder->text();
        QString description = aItem.flavourText->toPlainText();
        U_INT il = aItem.levelItem->value();
        QString type = aItem.typeItemBox->currentText();

        InventoryItem* t;

        if(type == "Body Armor") {
            U_INT pdef = aItem.physDef->value();
            U_INT mdef = aItem.magicDef->value();
            U_SHORT b = aItem.balance->value();
            U_INT fallingDef = aItem.fallDef->value();
            U_INT stabbingDef = aItem.stabDef->value();
            t = new BodyArmor(name.toUtf8().constData(), il, description.toUtf8().constData(), pdef, mdef, b, fallingDef, stabbingDef);
        }
        else if(type == "Gloves") {
            U_INT pdef = aItem.physDef->value();
            U_INT mdef = aItem.magicDef->value();
            U_SHORT b = aItem.balance->value();
            U_INT pdmg = aItem.physDmg->value();
            U_INT mdmg = aItem.magicDmg->value();
            U_SHORT strScaling = aItem.strScaling->value();
            t = new Gloves(name.toUtf8().constData(), il, description.toUtf8().constData(), pdef, mdef, b, pdmg, mdmg, strScaling);
        }
        else if(type == "Attack Weapon") {
            U_INT pdmg = aItem.physDmg->value();
            U_INT mdmg = aItem.magicDmg->value();
            U_SHORT strScaling = aItem.strScaling->value();
            U_SHORT dexScaling = aItem.dexScaling->value();
            t = new AttackWeapon(name.toUtf8().constData(), il, description.toUtf8().constData(), pdmg, mdmg, strScaling, dexScaling);
        }
        else if(type == "Attack Shield") {
            U_INT pdmg = aItem.physDmg->value();
            U_INT mdmg = aItem.magicDmg->value();
            U_INT pred = aItem.physRes->value();
            U_INT mred = aItem.magicRes->value();
            U_SHORT dexScaling = aItem.dexScaling->value();
            t = new AttackShield(name.toUtf8().constData(), il, description.toUtf8().constData(), pdmg, mdmg, pred, mred, dexScaling);
        }
        else if(type == "Defense Shield") {
            U_INT pred = aItem.physRes->value();
            U_INT mred = aItem.magicRes->value();
            t = new DefenseShield(name.toUtf8().constData(), il, description.toUtf8().constData(), pred, mred);
        }
        else if(type == "Ring") {
            U_INT statsIncreasing = aItem.stsIncreasing->value();
            t = new Ring(name.toUtf8().constData(), il, description.toUtf8().constData(), statsIncreasing);
        }
        model->insertRows(0, 1, QModelIndex());
        QModelIndex i = model->index(0, 0, QModelIndex());
        model->addInventoryItem(i, QVariant::fromValue(t), Qt::EditRole);
    }
}

//RIMOZIONE DELL'ELEMENTO SELEZIONATO (Non funziona con oggetti di base)
void Tab::removeItem()
{
   //QItemSelectionModel* s = armorTab->selectionModel();

    QModelIndexList a = armorTab->selectionModel()->selectedRows();
    QModelIndexList b = ringTab->selectionModel()->selectedRows();
    QModelIndexList c = shieldTab->selectionModel()->selectedRows();
    QModelIndexList d = weaponTab->selectionModel()->selectedRows();

    if(!a.isEmpty()) {
        QModelIndex t = proxy->mapToSource(a[0]);
        model->removeRows(t.row(), 1, QModelIndex());
    }
    else if(!b.isEmpty()) {
        QModelIndex t = proxy->mapToSource(b[0]);
        model->removeRows(t.row(), 1, QModelIndex());
    }
    else if(!c.isEmpty()) {
        QModelIndex t = proxy->mapToSource(c[0]);
        model->removeRows(t.row(), 1, QModelIndex());
    }
    else if(!d.isEmpty()) {
        QModelIndex t = proxy->mapToSource(d[0]);
        model->removeRows(t.row(), 1, QModelIndex());
    }
    else {
        QMessageBox::warning(this,tr("Error"),tr("Nessun oggetto selezionato"),QMessageBox::Ok);
    }
}


//SIDE INFORMATION
void Tab::createinformation(){

    //ELEMENTI NECESSARI PER INFORMAZIONI AGGIUNTIVE
    infPhysDefL = new QLabel("Physical Defense: ");
    infPhysDef = new QLabel("N/A");
    infMagicDefL = new QLabel("Magic Defense: ");
    infMagicDef = new QLabel("N/A");
    //
    infBalanceL = new QLabel("Balance: ");
    infBalance = new QLabel("N/A");
    infFallingL = new QLabel("Falling defense: ");
    infFalling = new QLabel("N/A");
    //
    infStabL = new QLabel("Stabbing defense: ");
    infStab = new QLabel("N/A");
    infstrScalL = new QLabel("Strenght scaling: ");
    infstrScal = new QLabel("N/A");
    //
    infPhysDmgL = new QLabel("Physical damage: ");
    infPhysDmg = new QLabel("N/A");
    infMagicalDmgL = new QLabel("Magical damage: ");
    infMagicalDmg = new QLabel("N/A");
    //
    infDxtScalL = new QLabel("Dexterity scaling: ");
    infDxtScal = new QLabel("N/A");
    infPhysResL = new QLabel("Physical resistance: ");
    infPhysRes = new QLabel("N/A");
    //
    infMagicResL = new QLabel("Magical resistance: ");
    infMagicRes = new QLabel("N/A");
    infStatsIncL = new QLabel("Stats increased: ");
    infStatsInc = new QLabel("N/A");

    //E INSERIMENTO NEL LAYOUT DEL BOX (Divisi per row)
    groupLayout->addWidget(infPhysDefL,0,0);
    groupLayout->addWidget(infPhysDef,0,1);
    groupLayout->addWidget(infMagicDefL,0,2);
    groupLayout->addWidget(infMagicDef,0,3);
    //
    groupLayout->addWidget(infBalanceL,1,0);
    groupLayout->addWidget(infBalance,1,1);
    groupLayout->addWidget(infFallingL,1,2);
    groupLayout->addWidget(infFalling,1,3);
    //
    groupLayout->addWidget(infStabL,2,0);
    groupLayout->addWidget(infStab,2,1);
    groupLayout->addWidget(infstrScalL,2,2);
    groupLayout->addWidget(infstrScal,2,3);
    //
    groupLayout->addWidget(infPhysDmgL,3,0);
    groupLayout->addWidget(infPhysDmg,3,1);
    groupLayout->addWidget(infMagicalDmgL,3,2);
    groupLayout->addWidget(infMagicalDmg,3,3);
    //
    groupLayout->addWidget(infDxtScalL,4,0);
    groupLayout->addWidget(infDxtScal,4,1);
    groupLayout->addWidget(infPhysResL,4,2);
    groupLayout->addWidget(infPhysRes,4,3);
    //
    groupLayout->addWidget(infMagicResL,5,0);
    groupLayout->addWidget(infMagicRes,5,1);
    groupLayout->addWidget(infStatsIncL,5,2);
    groupLayout->addWidget(infStatsInc,5,3);

    //QWIDGET COMPLETAMENTE BIANCO PER MATENERE LA SPAZIATURA
    QWidget* blank = new QWidget();
    blank->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    groupLayout->addWidget(blank,6,0);


    //INFORMAZIONI AGGIUNTIVE PER ALCUNI TIPI DI OGGETTO (METODI PROPRI)
    infadditionalL = new QLabel();
    infadditionl = new QLabel();

    groupLayout->addWidget(infadditionalL,7,0);
    groupLayout->addWidget(infadditionl,7,1);
}
//RESET VALUE "Complessi"
void Tab::resetInformation(){
    infadditionalL->clear();
    infadditionl->clear();
}

//POP-UP LATERALE
void Tab::showData(QModelIndex index){
    index = proxy->mapToSource(index);
    std::cout << "index =" << model->getInventory()[index.row()]->getType() << std::endl ;
    std::cout << "Nome =" << model->getInventory()[index.row()]->getName() << std::endl;
    resetInformation();
    string t = model->getInventory()[index.row()]->getType();
    //VALORI PER ARMOR
    if(t == "armor"){
        Armor* s  = dynamic_cast<Armor*>(model->getInventory()[index.row()]);
        infPhysDef->setNum(static_cast<int>(s->getPhysicalDef()));
        infMagicDef->setNum(static_cast<int>(s->getMagicalDef()));
        infBalance->setNum(static_cast<int>(s->getBalance()));
        infFalling->setNum(static_cast<int>(static_cast<BodyArmor*>(s)->getFallingDef()));
        infStab->setNum(static_cast<int>(static_cast<BodyArmor*>(s)->getStabbingDef()));
        infstrScal->setText("N/A");
        infPhysDmg->setText("N/A");
        infMagicalDmg->setText("N/A");
        infDxtScal->setText("N/A");
        infPhysRes->setText("N/A");
        infMagicRes->setText("N/A");
        infStatsInc->setText("N/A");

        infadditionl->setNum(static_cast<BodyArmor*>(s)->getTotalDef());
        infadditionalL->setText("Total defense: ");
    }
    //VALORI PER WEAPON
    else if (t == "weapon") {
        Weapon* s = dynamic_cast<Weapon*>(model->getInventory()[index.row()]);
        infPhysDef->setText("N/A");
        infMagicDef->setText("N/A");
        infBalance->setText("N/A");
        infFalling->setText("N/A");
        infStab->setText("N/A");
        infstrScal->setNum(static_cast<int>(static_cast<AttackWeapon*>(s)->getStrScaling()));
        infPhysDmg->setNum(static_cast<int>(s->getPhysicalDmg()));
        infMagicalDmg->setNum(static_cast<int>(s->getMagicalDmg()));
        infDxtScal->setNum(static_cast<int>(static_cast<AttackWeapon*>(s)->getDexScaling()));
        infPhysRes->setText("N/A");
        infMagicRes->setText("N/A");
        infStatsInc->setText("N/A");

        infadditionl->setNum(s->getTotalDmg());
        infadditionalL->setText("Total damage: ");
    }
    //VALORI PER SHIELD
    else if (t == "shield"){
        Shield* s = dynamic_cast<Shield*>(model->getInventory()[index.row()]);
        infPhysDef->setText("N/A");
        infMagicDef->setText("N/A");
        infBalance->setText("N/A");
        infFalling->setText("N/A");
        infStab->setText("N/A");
        infstrScal->setText("N/A");
        infPhysDmg->setText("N/A");
        infMagicalDmg->setText("N/A");
        infDxtScal->setText("N/A");
        infPhysRes->setNum(static_cast<int>(s->getPhysicalRed()));
        infMagicRes->setNum(static_cast<int>(s->getPhysicalRed()));
        infStatsInc->setText("N/A");

        infadditionl->setNum(s->getTotalRed());
        infadditionalL->setText("Total damage reduction: ");
    }
    //VALORI PER RING
    else if (t == "ring"){
        infPhysDef->setText("N/A");
        infMagicDef->setText("N/A");
        infBalance->setText("N/A");
        infFalling->setText("N/A");
        infStab->setText("N/A");
        infstrScal->setText("N/A");
        infPhysDmg->setText("N/A");
        infMagicalDmg->setText("N/A");
        infDxtScal->setText("N/A");
        infPhysRes->setText("N/A");
        infMagicRes->setText("N/A");
        infStatsInc->setNum(static_cast<int>((dynamic_cast<Ring*>(model->getInventory()[index.row()]))->getStatsIncreasing()));
    }
    //VALORI PER GLOVES
    else if (t == "weaponarmor"){
        Gloves* s = dynamic_cast<Gloves*>(model->getInventory()[index.row()]);
        infPhysDef->setNum(static_cast<int>(s->getPhysicalDef()));
        infMagicDef->setNum(static_cast<int>(s->getMagicalDef()));
        infBalance->setText("N/A");
        infFalling->setText("N/A");
        infStab->setText("N/A");
        infstrScal->setNum(static_cast<int>(s->getStrScaling()));
        infPhysDmg->setNum(static_cast<int>(s->getPhysicalDmg()));
        infMagicalDmg->setNum(static_cast<int>(s->getMagicalDmg()));
        infDxtScal->setText("N/A");
        infPhysRes->setText("N/A");
        infMagicRes->setText("N/A");
        infStatsInc->setText("N/A");
    }
    //VALORI ATTACK SHIELD
    else if (t == "weaponshield"){
        WeaponShield* s = dynamic_cast<WeaponShield*>(model->getInventory()[index.row()]);
        infPhysDef->setText("N/A");
        infMagicDef->setText("N/A");
        infBalance->setText("N/A");
        infFalling->setText("N/A");
        infStab->setText("N/A");
        infstrScal->setText("N/A");
        infPhysDmg->setNum(static_cast<int>(s->getPhysicalDmg()));
        infMagicalDmg->setNum(static_cast<int>(s->getMagicalDmg()));
        infDxtScal->setNum(static_cast<int>(static_cast<AttackShield*>(s)->getDexScaling()));
        infPhysRes->setNum(static_cast<int>(s->getPhysicalRed()));
        infMagicRes->setNum(static_cast<int>(s->getMagicalRed()));
        infStatsInc->setText("N/A");
    }
    //APPARE LA BARRA LATERALE
    information->setHidden(false);
}

//SIGNAL ON ESC
void Tab::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        if(!information->isHidden()){
            information->setHidden(true);
        }
    }
}

//DIVSIONE CORRETTA NELLE DIVERSE TAB
void Tab::updateFilterRows(int a) {
    if(a == 0)
        proxy->setNomeTipo("armor");
    else if(a == 1)
        proxy->setNomeTipo("ring");
    else if(a==2)
        proxy->setNomeTipo("shield");
    else if(a==3)
        proxy->setNomeTipo("weapon");

    QRegExp regex(proxy->getNomeTipo(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxy->setFilterRegExp(regex);
}

void Tab::loadFileDialog()
{
    loadDialog = new QFileDialog(this);
    if(loadDialog->exec()) {
        QString path = loadDialog->selectedFiles()[0];
        IO input(path);
        //model->setInventory(input.readFile());
        Inventory<InventoryItem*> t = input.readFile();
        Inventory<InventoryItem*>::Iterator it;
        for(it=t.begin(); it!=t.end(); ++it) {
            model->insertRows(0, 1, QModelIndex());
            QModelIndex i = model->index(0,0, QModelIndex());
            model->addInventoryItem(i, QVariant::fromValue(*it), Qt::EditRole);
        }
    }
}

void Tab::saveFileDialog() {
        saveDialog = new QFileDialog(this);
        QString path = saveDialog->getSaveFileName(this, tr("Save File"), "/home/untitled.xml", tr(".xml"));
        IO input(path);
        input.write(Inventory<InventoryItem*>(model->getInventory()));
}

