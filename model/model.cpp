#include "model.h"

//COSTRUTTORI
Model::Model(QObject* parent) : QAbstractListModel(parent) , name("CrownSouls"), inventory() {}

int Model::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return inventory.getSize();
}

int Model::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 4;
}


bool Model::removeRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for(int i = 0; i < rows; ++i) {
        inventory.popAtPosition(position);
    }
    endRemoveRows();
    return true;
}

QVariant Model::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole && inventory[index.row()]) {
        if(index.column() == 0) {
            QString t = QString::fromStdString(inventory[index.row()]->getName());
            return t;
        } else if(index.column() == 1) {
            QString t = QString::fromStdString(inventory[index.row()]->getDescription());
            return t;
        } else if (index.column() == 2) {
            QString t = QString::number(inventory[index.row()]->getItemLevel());
            return t;
        }
    }
    return QVariant();
}

/*bool Model::setData(const QModelIndex& index, const QVariant& value, int role) {
    if(!index.isValid())
        return false;
    if(role != Qt::EditRole)
        return false;
    if(index.column() == 0) {

        //inventory[index.row()]->setName(value.toStdString());
    }
} */

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal) {
        if(section == 0)
            return "Nome";
        else if(section == 1)
            return "Descrizione";
        else if(section == 2)
            return "Livello";
    }
    return QVariant();
}



//GETTER
QString Model::getName() const {
    return name;
}

Inventory<InventoryItem *> Model::getInventory() const {
    return inventory;
}

Inventory<InventoryItem*> Model::getArmorItems() const {
    Inventory<InventoryItem*> l;
    Inventory<InventoryItem*>::Iterator it;
     for(it=inventory.begin(); it.hasFinished(); ++it) {
        InventoryItem* t = *it;
        if(t->getType() == "armor" || t->getType() == "weaponarmor")
            l.pushBack(t);
     }
     return l;
}

Inventory<InventoryItem*> Model::getWeaponItems() const {
    Inventory<InventoryItem*> l;
    Inventory<InventoryItem*>::Iterator it;
     for(it=inventory.begin(); it.hasFinished(); ++it) {
        InventoryItem* t = *it;
        if(t->getType() == "weapon" || t->getType() == "weaponarmor")
            l.pushBack(t);
     }
     return l;
}

Inventory<InventoryItem*> Model::getShieldItems() const {
    Inventory<InventoryItem*> l;
    Inventory<InventoryItem*>::Iterator it;
     for(it=inventory.begin(); it.hasFinished(); ++it) {
        InventoryItem* t = *it;
        if(t->getType() == "shield" || t->getType() == "weaponshield")
            l.pushBack(t);
     }
     return l;
}

Inventory<InventoryItem*> Model::getRingItems() const {
    Inventory<InventoryItem*> l;
    Inventory<InventoryItem*>::Iterator it;
     for(it=inventory.begin(); it.hasFinished(); ++it) {
        InventoryItem* t = *it;
        if(t->getType() == "ring")
            l.pushBack(t);
     }
     return l;
}

unsigned int Model::armorCount() const {
    return getArmorItems().getSize();
}

int Model::ringCount() const {
    return getRingItems().getSize();
}

int Model::shieldCount() const {
    return getShieldItems().getSize();
}

int Model::weaponCount() const {
    return getWeaponItems().getSize();
}

