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

    //LAYOUT
    QHBoxLayout *horilayout;
    QTabWidget *usertab;

    //ESTENSIONI
    QTextEdit *informationTab;

public slots:

    void addItem();
    void showData();
    void keyPressEvent(QKeyEvent *event);
    void updateFilterRows(int);

};

#endif // TAB_H
