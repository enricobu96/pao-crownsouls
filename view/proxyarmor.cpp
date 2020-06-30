#include "proxyarmor.h"
#include<iostream>
Proxy::Proxy(QObject * parent) : QSortFilterProxyModel(parent) {}

bool Proxy::filterAcceptsRow(int rowse, const QModelIndex & index) const {
    Q_UNUSED(index);
    return static_cast<Model*>(sourceModel())->inventory[rowse]->getType() == nomeTipo.toUtf8().constData();
}

QString Proxy::getNomeTipo() const {
    return nomeTipo;
}

void Proxy::setNomeTipo(const QString &value) {
    nomeTipo = value;
}
