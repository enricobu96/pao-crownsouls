#ifndef PROXYARMOR_H
#define PROXYARMOR_H

#include <QObject>
#include<QSortFilterProxyModel>
#include "../model/model.h"

class Proxy : public QSortFilterProxyModel {
    Q_OBJECT
public:
    Proxy(QObject* =nullptr);


    QString getNomeTipo() const;
    void setNomeTipo(const QString &value);

    //bool insertRows(int row, int count, const QModelIndex &parent) override;

    //void invalidateFilter() {invalidateFilter();}
    //QModelIndex mapToSource(const QModelIndex &) const;

private:
    QString nomeTipo;

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};

#endif // PROXYARMOR_H
