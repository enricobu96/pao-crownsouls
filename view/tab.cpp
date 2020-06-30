#include "tab.h"

//COSTRUTTORE
Tab::Tab(QWidget *parent) : QWidget(parent), usertab(new QTabWidget()) {
    //MODEL
    model = new Model(this);
    proxy = new Proxy(this);

    model->inventory.pushFront(new Ring("Anello anti-covid", 1, "Anello contro il coronavirus")); //TO FIX

    //APPLICAZIONE
    setMinimumSize(1024,720);
    horilayout = new QHBoxLayout(this);

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

    //LAYOUT
    horilayout->addWidget(usertab);

    //CONNECT
    connect(usertab, SIGNAL(currentChanged(int)), this, SLOT(updateFilterRows(int)));
}

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

void Tab::ShowData(){
    informationTab->setHidden(false);
}

void Tab::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        if(!informationTab->isHidden()){
            informationTab->setHidden(true);
        }
    }
}

void Tab::updateFilterRows(int a) { //to be continued
    if(a == 0) {
        proxy->setNomeTipo("armor");
    } else if(a== 1) proxy->setNomeTipo("ring");
    else if(a==2) proxy->setNomeTipo("shield");
    else if(a==3) proxy->setNomeTipo("weapon");

    QRegExp regex(proxy->getNomeTipo(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxy->setFilterRegExp(regex);
    //proxy->filterAcceptsRow();
    //model->filter()
}
