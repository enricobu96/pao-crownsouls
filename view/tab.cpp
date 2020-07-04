#include "tab.h"

#include<QStandardItem>
#include<QListWidgetItem>

#include<iostream>

Tab::Tab(QWidget *parent) :
    QWidget(parent), usertab(new QTabWidget()) {
    setProperty("class", "tab");
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
        setInformation(aItem,true, QModelIndex());
    }
}

//RIMOZIONE DELL'ELEMENTO SELEZIONATO
void Tab::removeItem()
{
    QModelIndexList a = armorTab->selectionModel()->selectedRows();
    QModelIndexList b = ringTab->selectionModel()->selectedRows();
    QModelIndexList c = shieldTab->selectionModel()->selectedRows();
    QModelIndexList d = weaponTab->selectionModel()->selectedRows();

    AddItem mitem("Modifica");

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

void Tab::modifyItem()
{
    QModelIndexList a = armorTab->selectionModel()->selectedRows();
    QModelIndexList b = ringTab->selectionModel()->selectedRows();
    QModelIndexList c = shieldTab->selectionModel()->selectedRows();
    QModelIndexList d = weaponTab->selectionModel()->selectedRows();

    AddItem mItem("Modifica");

    QModelIndex t = QModelIndex();
    if(!a.isEmpty()){
        t = proxy->mapToSource(a[0]);
        Armor* sel = dynamic_cast<Armor*>(model->getInventory()[t.row()]);
        if(model->getInventory()[t.row()]->getType() == "weaponarmor"){
            //VALORI PROPRI DI GLOVES
            mItem.physDmg->setValue(static_cast<Gloves*>(sel)->getPhysicalDmg());
            mItem.magicDmg->setValue(static_cast<Gloves*>(sel)->getMagicalDmg());
            mItem.strScaling->setValue(static_cast<Gloves*>(sel)->getStrScaling());
            mItem.typeItemBox->setCurrentIndex(1);
        }
        else {
            //VALORI PROPRI DI ARMOR
        mItem.fallDef->setValue(static_cast<BodyArmor*>(sel)->getFallingDef());
        mItem.stabDef->setValue(static_cast<BodyArmor*>(sel)->getStabbingDef());
        mItem.typeItemBox->setCurrentIndex(0);
        }
        //VALORI IN COMUNE TRA GLOVES E BODYARMOR
        mItem.physDef->setValue(sel->getPhysicalDef());
        mItem.magicDef->setValue(sel->getMagicalDef());
        mItem.balance->setValue(sel->getBalance());
        mItem.namePlaceholder->setText(QString::fromStdString(sel->getName()));
        mItem.flavourText->setText(QString::fromStdString(sel->getDescription()));
    }
    else if (!b.isEmpty()){
        t = proxy->mapToSource(b[0]);
        Ring* sel = dynamic_cast<Ring*>(model->getInventory()[t.row()]);
        mItem.stsIncreasing->setValue(sel->getStatsIncreasing());
        mItem.namePlaceholder->setText(QString::fromStdString(sel->getName()));
        mItem.flavourText->setText(QString::fromStdString(sel->getDescription()));
        mItem.typeItemBox->setCurrentIndex(5);
    }
    else if (!c.isEmpty()){
        t = proxy->mapToSource(c[0]);
        Shield* sel = dynamic_cast<Shield*>(model->getInventory()[t.row()]);
        if(model->getInventory()[t.row()]->getType() == "weaponshield"){
            mItem.physDmg->setValue(static_cast<AttackShield*>(sel)->getPhysicalDmg());
            mItem.magicDmg->setValue(static_cast<AttackShield*>(sel)->getMagicalDmg());
            mItem.dexScaling->setValue(static_cast<AttackShield*>(sel)->getDexScaling());
            mItem.typeItemBox->setCurrentIndex(3);
        }
        else{
            mItem.typeItemBox->setCurrentIndex(4);
        }
        mItem.physRes->setValue(sel->getPhysicalRed());
        mItem.magicRes->setValue(sel->getMagicalRed());
        mItem.namePlaceholder->setText(QString::fromStdString(sel->getName()));
        mItem.flavourText->setText(QString::fromStdString(sel->getDescription()));
    }
    else if(!d.isEmpty()){
        t = proxy->mapToSource(d[0]);
        Weapon* sel = dynamic_cast<Weapon*>(model->getInventory()[t.row()]);
        if(model->getInventory()[t.row()]->getType() == "weaponshield"){
            mItem.physRes->setValue(static_cast<AttackShield*>(sel)->getPhysicalRed());
            mItem.magicRes->setValue(static_cast<AttackShield*>(sel)->getMagicalRed());
            mItem.dexScaling->setValue(static_cast<AttackShield*>(sel)->getDexScaling());
            mItem.typeItemBox->setCurrentIndex(3);
        }
        else if(model->getInventory()[t.row()]->getType() == "weaponarmor") {
            mItem.physDef->setValue(static_cast<Gloves*>(sel)->getPhysicalDef());
            mItem.magicDef->setValue(static_cast<Gloves*>(sel)->getMagicalDef());
            mItem.balance->setValue(static_cast<Gloves*>(sel)->getBalance());
            mItem.strScaling->setValue(static_cast<Gloves*>(sel)->getStrScaling());
            mItem.typeItemBox->setCurrentIndex(1);

        }
        else{
            mItem.strScaling->setValue(static_cast<AttackWeapon*>(sel)->getStrScaling());
            mItem.dexScaling->setValue(static_cast<AttackWeapon*>(sel)->getDexScaling());
            mItem.typeItemBox->setCurrentIndex(2);
        }
        mItem.physDmg->setValue(sel->getPhysicalDmg());
        mItem.magicDmg->setValue(sel->getPhysicalDmg());
        mItem.namePlaceholder->setText(QString::fromStdString(sel->getName()));
        mItem.flavourText->setText(QString::fromStdString(sel->getDescription()));

    }
    else{
        QMessageBox::warning(this,tr("Error"),tr("Nessun oggetto selezionato"),QMessageBox::Ok);
    }

    if(!(a.isEmpty() && b.isEmpty() && c.isEmpty() && d.isEmpty())) {
        if(mItem.exec())
            setInformation(mItem,false, t);
    }


}

void Tab::setInformation(AddItem &aItem,bool aggiungi, QModelIndex index){

    QString name = aItem.namePlaceholder->text();
    QString description = aItem.flavourText->toPlainText();
    U_INT il = aItem.levelItem->value();
    QString type = aItem.typeItemBox->currentText();
    try {
    InventoryItem* t;
    if(type == "Body Armor") {
        U_INT pdef = aItem.physDef->value();
        U_INT mdef = aItem.magicDef->value();
        U_INT b = aItem.balance->value();
        U_INT fallingDef = aItem.fallDef->value();
        U_INT stabbingDef = aItem.stabDef->value();
        t = new BodyArmor(name.toUtf8().constData(), il, description.toUtf8().constData(), pdef, mdef, b, fallingDef, stabbingDef);
    } else if(type == "Gloves") {
        U_INT pdef = aItem.physDef->value();
        U_INT mdef = aItem.magicDef->value();
        U_INT b = aItem.balance->value();
        U_INT pdmg = aItem.physDmg->value();
        U_INT mdmg = aItem.magicDmg->value();
        U_INT strScaling = aItem.strScaling->value();
        t = new Gloves(name.toUtf8().constData(), il, description.toUtf8().constData(), pdef, mdef, b, pdmg, mdmg, strScaling);
    } else if(type == "Attack Weapon") {
        U_INT pdmg = aItem.physDmg->value();
        U_INT mdmg = aItem.magicDmg->value();
        U_INT strScaling = aItem.strScaling->value();
        U_INT dexScaling = aItem.dexScaling->value();
        t = new AttackWeapon(name.toUtf8().constData(), il, description.toUtf8().constData(), pdmg, mdmg, strScaling, dexScaling);
    }
    else if(type == "Attack Shield") {
        U_INT pdmg = aItem.physDmg->value();
        U_INT mdmg = aItem.magicDmg->value();
        U_INT pred = aItem.physRes->value();
        U_INT mred = aItem.magicRes->value();
        U_INT dexScaling = aItem.dexScaling->value();
        t = new AttackShield(name.toUtf8().constData(), il, description.toUtf8().constData(), pdmg, mdmg, pred, mred, dexScaling);
    } else if(type == "Defense Shield") {
        U_INT pred = aItem.physRes->value();
        U_INT mred = aItem.magicRes->value();
        t = new DefenseShield(name.toUtf8().constData(), il, description.toUtf8().constData(), pred, mred);
    } else if(type == "Ring") {
        U_INT statsIncreasing = aItem.stsIncreasing->value();
        t = new Ring(name.toUtf8().constData(), il, description.toUtf8().constData(), statsIncreasing);
    }
    if(aggiungi){
        model->addInventoryItem(QModelIndex(), QVariant::fromValue(t));
        model->insertRow(0);
    } else { //ramo modifica
        model->setInventoryItem(index, QVariant::fromValue(t));
    }
    } catch(std::exception e) {
        QMessageBox err(QMessageBox::Warning, "Errore aggiunta elemento", "Errore nell'aggiunta dell'elemento", QMessageBox::Ok);
        throw 1;
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

    desctiption = new QLabel();
    desctiption->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Preferred);
    desctiption->setWordWrap(true);
    groupLayout->addWidget(desctiption,6,0,6,3);
    groupLayout->addWidget(blank,7,0);

    //INFORMAZIONI AGGIUNTIVE PER ALCUNI TIPI DI OGGETTO (METODI PROPRI)
    infadditionalL = new QLabel();
    infadditionl = new QLabel();
    infadditional2L = new QLabel();
    infadditional2 = new QLabel();

    groupLayout->addWidget(infadditional2L,8,0);
    groupLayout->addWidget(infadditional2,8,1);
    groupLayout->addWidget(infadditionalL,9,0);
    groupLayout->addWidget(infadditionl,9,1);
}

//RESET VALUE
void Tab::resetInformation(){
    infadditionalL->clear();
    infadditionl->clear();
    infadditional2->clear();
    infadditional2L->clear();
}

//POP-UP LATERALE
void Tab::showData(QModelIndex index){
    index = proxy->mapToSource(index);
    resetInformation();
    string t = model->getInventory()[index.row()]->getType();
    //VALORI PER ARMOR
    if(t == "armor") {
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
        QString show = QString::fromStdString( s->getDescription());
        desctiption->setText(show);
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
        QString show = QString::fromStdString( s->getDescription());
        desctiption->setText(show);
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
        QString show = QString::fromStdString( s->getDescription());
        desctiption->setText(show);
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
        QString show = QString::fromStdString((dynamic_cast<Ring*>(model->getInventory()[index.row()])->getDescription()));
        desctiption->setText(show);
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

        infadditionl->setNum(s->getTotalDmg());
        infadditionalL->setText("Total damage: ");
        infadditional2->setNum(s->getTotalDef());
        infadditional2L->setText("Total defense: ");
        QString show = QString::fromStdString( s->getDescription());
        desctiption->setText(show);
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

        infadditionl->setNum(s->getTotalDmg());
        infadditionalL->setText("Total damage: ");
        infadditional2->setNum(s->getTotalRed());
        infadditional2L->setText("Total damage reduction: ");
        QString show = QString::fromStdString( s->getDescription());
        desctiption->setText(show);
    }
    //APPARE LA BARRA LATERALE
    information->setHidden(false);
}

//SIGNAL ON ESC
void Tab::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape) {
        if(!information->isHidden()) {
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

    //PATTERN MATCHING SUL TIPO DI OGGETTO (PER QUELLI CHE EREDITANO DA DUE CLASSI)
    QRegExp regex("*"+proxy->getNomeTipo()+"*",Qt::CaseInsensitive, QRegExp::Wildcard);
    proxy->setFilterRegExp(regex);
}

void Tab::loadFileDialog()
{
    loadDialog = new QFileDialog(this, tr("Load inventory"), QDir::home().path(), tr("XML file (*.xml)"));
    if(loadDialog->exec()) {
        QString path = loadDialog->selectedFiles()[0];
        IO input(path);
        Inventory<InventoryItem*> t = input.readFile();
        Inventory<InventoryItem*>::Iterator it;
        for(it=t.begin(); !it.hasFinished(); ++it) {
            model->addInventoryItem(QModelIndex(), QVariant::fromValue(*it));
            model->insertRow(0);
        }
    }
}

void Tab::saveFileDialog() {
        saveDialog = new QFileDialog(this);
        QString path = saveDialog->getSaveFileName(this, tr("Save inventory"), QDir::home().path().append("/untitledInventory.xml"), tr("XML file (.xml)"));
        IO input(path);
        input.write(model->getInventory());
}

void Tab::destroyInventory() {
    model->removeRows(0, model->getInventory().getSize(), QModelIndex());
}
