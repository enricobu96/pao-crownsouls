#include<QTextEdit>
#include<QAction>
#include<QPushButton>
#include<QHeaderView>
#include<iostream>
#include "tab.h"
#include<iostream>
using namespace std;


Tab::Tab(QWidget *parent)
    : QWidget(parent),
      usertab(new QTabWidget())
{
    model = new Model(this);
    proxyModel = new QSortFilterProxyModel(this);


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

    proxyModel->setSourceModel(model);
    armorTab->setModel(proxyModel);
    ringTab->setModel(proxyModel);
    shieldTab->setModel(proxyModel);
    weaponTab->setModel(proxyModel);


    horilayout->addWidget(usertab);


    //SIGNAL
    //connect(viewArmi,SIGNAL(clicked(QModelIndex)),this,SLOT(ShowData()));
    //connect(viewArmatura,SIGNAL(clicked(QModelIndex)),this,SLOT(ShowData()));
}

void Tab::addItem()
{
    cout << "OUUUUU" << endl;
    AddItem aItem("Add Item"); //TUTTO MOLTO SKETCHY
    cout << "0";
    if(aItem.exec()) {

        QString name = aItem.namePlaceholder->text();
        cout << "2";
        QString description = aItem.flavourText->toPlainText();
        cout << "3";
        QString il = aItem.itemLevelPlaceholder->text();
        cout << "4";
        InventoryItem* p;
        cout << "5";
        p = new Ring(name.toUtf8().constData(), 0, description.toUtf8().constData()); // 0 è un placeholder
        cout << "6";
        model->insertRows(0, 1, QModelIndex());
        cout << "7";
        QModelIndex i = model->index(0, 0, QModelIndex());
        cout << "qmodelindex = ";
        model->addInventoryItem(i, QVariant::fromValue(p), Qt::EditRole);

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

/*void tab::addEntry()                //test solo su model armi
{
    AddItem aItem("Add Item");
    aItem.exec();

    modelArmi->insertRows(0,1,QModelIndex());
}
*/
