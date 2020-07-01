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
#include<QFileDialog>

//VIEW
#include"armortab.h"
#include"ringtab.h"
#include"shieldtab.h"
#include"weapontab.h"
#include"additem.h"

//MODEL
#include"../model/model.h"
#include"proxyarmor.h"

#include"../model/io.h"


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
    QSpacerItem* spacer;
    QGridLayout* groupLayout;
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
    //INFORMAZIONI AGGIUNTIVE IN TAB AGGIUNTIVA
    QLabel* infTotalDefL;
    QLabel* infTotalDef;
    QLabel* infTotalRedL;
    QLabel* infTotalRed;
    QLabel* infTotalDmgL;
    QLabel* infTotalDmg;
    QLabel* infLevelDmgL;
    QLabel* infLevelDmg;

    QFileDialog* loadDialog;
    QFileDialog* saveDialog;

    //LAYOUT
    QHBoxLayout *horilayout;
    QTabWidget *usertab;

    //ESTENSIONI
    QTextEdit *informationTab;

public slots:

    void addItem();
    void removeItem();
    void createinformation();
    void showData(QModelIndex index);
    //void resetInformation();
    void keyPressEvent(QKeyEvent *event);
    void updateFilterRows(int);
    void loadFileDialog();
    void saveFileDialog();

};

#endif // TAB_H
