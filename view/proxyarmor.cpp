#include "proxyarmor.h"
#include<iostream>
using namespace std;
Proxy::Proxy(QObject * parent) : QSortFilterProxyModel(parent) {}

bool Proxy::filterAcceptsRow(int rowse, const QModelIndex & index) const {
    Q_UNUSED(index);
    cout << "rowse: " << rowse;
    cout << endl << "SIZE: " << endl << static_cast<Model*>(sourceModel())->getInventory().getSize() << endl;

    if(static_cast<Model*>(sourceModel())->getInventory().isEmpty()) return true;


    QRegExp regex("*"+getNomeTipo()+"*",Qt::CaseInsensitive, QRegExp::Wildcard);
    return regex.exactMatch(QString::fromStdString(static_cast<Model*>(sourceModel())->getInventory()[rowse]->getType()));
    //return true;
}

QString Proxy::getNomeTipo() const {
    return nomeTipo;
}

void Proxy::setNomeTipo(const QString &value) {
    nomeTipo = value;
}
