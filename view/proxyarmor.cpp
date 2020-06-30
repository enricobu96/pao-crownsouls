#include "proxyarmor.h"
#include<iostream>
Proxy::Proxy(QObject * parent) : QSortFilterProxyModel(parent) {}

/*bool Proxy::insertRows(int row, int count, const QModelIndex &parent) {
    std::cout << "QUa ci arriva";
    bool r = sourceModel()->insertRows(row, count, parent);
    std::cout << "QUa ci arriva";
    invalidateFilter();

    return r;
} */

/*QModelIndex Proxy::mapToSource(const QModelIndex &proxyIndex) const {
    Model* p = qobject_cast<Model*>(sourceModel());
    if(!p || !proxyIndex.isValid()) return QModelIndex();
    return qobject_cast<Model*>(sourceModel())->createIndex(proxyIndex.row(), proxyIndex.column(), proxyIndex.internalPointer());
} */

bool Proxy::filterAcceptsRow(int rowse, const QModelIndex & index) const {
    return static_cast<Model*>(sourceModel())->inventory[rowse]->getType() == nomeTipo.toUtf8().constData();
}

QString Proxy::getNomeTipo() const {
    return nomeTipo;
}

void Proxy::setNomeTipo(const QString &value) {
    nomeTipo = value;
}
