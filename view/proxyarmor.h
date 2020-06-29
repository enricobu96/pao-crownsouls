#ifndef PROXYARMOR_H
#define PROXYARMOR_H

#include <QObject>
#include<QSortFilterProxyModel>

class ProxyArmor : public QSortFilterProxyModel {
    Q_OBJECT
public:
    ProxyArmor();
};

#endif // PROXYARMOR_H
