#include "proxyarmor.h"
#include<iostream>
Proxy::Proxy(QObject * parent) : QSortFilterProxyModel(parent) {}

bool Proxy::filterAcceptsRow(int rowse, const QModelIndex & index) const {
    Q_UNUSED(index);
    if(static_cast<Model*>(sourceModel())->getInventory().getSize() == 1) return true;
    QRegExp regex("*"+getNomeTipo()+"*",Qt::CaseInsensitive, QRegExp::Wildcard);
    //return static_cast<Model*>(sourceModel())->inventory[rowse]->getType() == nomeTipo.toUtf8().constData();
    return regex.exactMatch(QString::fromStdString(static_cast<Model*>(sourceModel())->inventory[rowse]->getType()));
}

QString Proxy::getNomeTipo() const {
    return nomeTipo;
}

void Proxy::setNomeTipo(const QString &value) {
    nomeTipo = value;
}
