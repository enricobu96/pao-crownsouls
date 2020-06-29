#ifndef TAB_H
#define TAB_H
// #include"mymodel.h"
// #include"additem.h"

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
//Test
#include<QTextEdit>
#include"armortab.h"
#include"ringtab.h"
#include"shieldtab.h"
#include"weapontab.h"


class Tab : public  QWidget
{
   Q_OBJECT
public:
    Tab(QWidget *parent = nullptr);
    //Model *modelArmi;

private:

    //Model *modelArmatura;

    //TABS
    ArmorTab* armorTab;
    RingTab* ringTab;
    ShieldTab* shieldTab;
    WeaponTab* weaponTab;

    QHBoxLayout *horilayout;

    QTabWidget *usertab;        //widget principale per "contenere" il resto


    QTextEdit *informationTab;  //tab per le informazioni, al momento è un textedit

    void addtabs();

    //funzioni da collegare
public slots:
     void ShowData();
     void keyPressEvent(QKeyEvent *event);
     //void addEntry();
};

#endif // TAB_H
