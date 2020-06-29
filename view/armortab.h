#ifndef ARMORTAB_H
#define ARMORTAB_H

#include<QTableView>
#include<QHeaderView>
#include"../model/model.h"
#include<QSortFilterProxyModel>

class ArmorTab: public QTableView {
public:
    ArmorTab(QWidget* =nullptr);

private:
    Model* model;
    QSortFilterProxyModel* proxyModel;
};

#endif // ARMORTAB_H
