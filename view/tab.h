#ifndef TAB_H
#define TAB_H

//QT
#include<QObject>
#include<QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QMenuBar>
#include<QTabWidget>
#include<QDialog>
#include<QModelIndex>
#include<QTableView>
#include<QKeyEvent>
#include<QTextEdit>
#include<QAction>
#include<QPushButton>
#include<QHeaderView>
#include<QMessageBox>

//VIEW
#include"armortab.h"
#include"ringtab.h"
#include"shieldtab.h"
#include"weapontab.h"
#include"additem.h"

//MODEL
#include"../model/model.h"
#include"proxyarmor.h"


class Tab : public QWidget {
   Q_OBJECT
public:

    //COSTRUTTORE
    Tab(QWidget *parent = nullptr);

private:

    //MODEL
    Model *model;
    QSortFilterProxyModel* proxyModel;
    Proxy* proxy;

    //TABS
    ArmorTab* armorTab;
    RingTab* ringTab;
    ShieldTab* shieldTab;
    WeaponTab* weaponTab;

    //TAB AGGIUNTIVA
    QGroupBox* information;
    QLabel* infPhysDefL;
    QLabel* infPhysDef;
    QLabel* infMagicDefL;
    QLabel* infMagicDef;
    QLabel* infBalanceL;
    QLabel* infBalance;
    QLabel* infFallingL;
    QLabel* infFalling;
    QLabel* infStabL;
    QLabel* infStab;
    QLabel* infstrScalL;
    QLabel* infstrScal;
    QLabel* infPhysDmgL;
    QLabel* infPhysDmg;
    QLabel* infMagicalDmgL;
    QLabel* infMagicalDmg;
    QLabel* infDxtScalL;
    QLabel* infDxtScal;
    QLabel* infPhysResL;
    QLabel* infPhysRes;
    QLabel* infMagicResL;
    QLabel* infMagicRes;
    QLabel* infStatsIncL;
    QLabel* infStatsInc;

    //LAYOUT
    QHBoxLayout *horilayout;
    QTabWidget *usertab;

    //ESTENSIONI
    QTextEdit *informationTab;

public slots:

    void addItem();
    void removeItem();
    void showData(QModelIndex index);
    void keyPressEvent(QKeyEvent *event);
    void updateFilterRows(int);

};

#endif // TAB_H
