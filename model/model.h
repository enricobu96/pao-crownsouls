#ifndef MODEL_H
#define MODEL_H
#include"../view/proxy.h"

//GERARCHIA
#include "core/inventoryitem.h"
#include "core/armor.h"
#include "core/armor_bodyarmor.h"
#include "core/ring.h"
#include "core/shield.h"
#include "model/core/shield_defenseshield.h"
#include "model/core/weapon.h"
#include "model/core/weapon_attackweapon.h"
#include "model/core/weaponarmor.h"
#include "model/core/weaponarmor_gloves.h"
#include "model/core/weaponshield.h"
#include "model/core/weaponshield_attackshield.h"

//CONTAINER
#include "inventory.hpp"

//QT
#include<QObject>
#include<QString>
#include<QAbstractListModel>
#include<QXmlStreamReader>

Q_DECLARE_METATYPE(InventoryItem*)

class Model : public QAbstractListModel
{
    Q_OBJECT
    friend class Proxy;

public:

    //COSTRUTTORI
    Model(QObject* =nullptr);
    ~Model() =default;

    //METODI
    //@override QAbstractListModel
    int rowCount(const QModelIndex&  =QModelIndex()) const override;
    int columnCount(const QModelIndex&) const override;
    bool insertRows(int, int, const QModelIndex& =QModelIndex()) override;

    bool removeRows(int, int, const QModelIndex& =QModelIndex()) override;
    QVariant data(const QModelIndex&, int =Qt::DisplayRole) const override;
    bool setData(const QModelIndex&, const QVariant&, int =Qt::EditRole) override;
    QVariant headerData(int, Qt::Orientation, int) const override;

    //METODI PROPRI
    //getter
    QString getProgramName() const;
    Inventory<InventoryItem*> getInventory() const;
    Inventory<InventoryItem*> getArmorItems() const;
    Inventory<InventoryItem*> getWeaponItems() const;
    Inventory<InventoryItem*> getShieldItems() const;
    Inventory<InventoryItem*> getRingItems() const;
    U_INT armorCount() const;
    int ringCount() const;
    int shieldCount() const;
    int weaponCount() const;

    //setter
    bool addInventoryItem(const QModelIndex&, const QVariant&);

    //metodi
    bool filter(int, QString) const;

private:
    const QString name;
    Inventory<InventoryItem*> inventory;
};

#endif // MODEL_H
