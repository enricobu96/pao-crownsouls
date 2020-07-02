#ifndef PROXYARMOR_H
#define PROXYARMOR_H

#include<QObject>
#include<QSortFilterProxyModel>

#include"../model/model.h"

class Proxy : public QSortFilterProxyModel {
    Q_OBJECT
public:

    Proxy(QObject* =nullptr);

    //METODI
    QString getNomeTipo() const;
    void setNomeTipo(const QString &value);

private:
    QString nomeTipo;

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};

#endif // PROXYARMOR_H
