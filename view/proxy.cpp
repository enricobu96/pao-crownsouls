#include "proxy.h"

Proxy::Proxy(QObject * parent) :
    QSortFilterProxyModel(parent) {}

bool Proxy::filterAcceptsRow(int rowse, const QModelIndex & index) const {
    Q_UNUSED(index);
    if(static_cast<Model*>(sourceModel())->getInventory().isEmpty()) return true;

    QRegExp regex("*"+getNomeTipo()+"*",Qt::CaseInsensitive, QRegExp::Wildcard);
    return regex.exactMatch(QString::fromStdString(static_cast<Model*>(sourceModel())->getInventory()[rowse]->getType()));
}

QString Proxy::getNomeTipo() const {
    return nomeTipo;
}

void Proxy::setNomeTipo(const QString &value) {
    nomeTipo = value;
}
