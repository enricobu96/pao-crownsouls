#include<QTextEdit>
#include<QAction>
#include<QPushButton>
#include<QHeaderView>
#include<iostream>
#include "tab.h"


Tab::Tab(QWidget *parent)
    : QWidget(parent),
      usertab(new QTabWidget())
{
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



    horilayout->addWidget(usertab);


    //SIGNAL
    //connect(viewArmi,SIGNAL(clicked(QModelIndex)),this,SLOT(ShowData()));
    //connect(viewArmatura,SIGNAL(clicked(QModelIndex)),this,SLOT(ShowData()));
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
