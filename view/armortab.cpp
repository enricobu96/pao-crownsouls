#include "armortab.h"

ArmorTab::ArmorTab(QWidget* parent) : QTableView(parent) {
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model = new Model(this);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    setModel(proxyModel);
}
