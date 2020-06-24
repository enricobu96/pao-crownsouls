#ifndef INVENTORY_H
#define INVENTORY_H
#include "core/inventoryitem.h"

class Inventory
{
public:
    Inventory();

private:
    class SmartP {
    public:
        InventoryItem* p;
        SmartP(InventoryItem* q=nullptr);
        SmartP(const SmartP& s);
        SmartP& operator=(const SmartP& s);
        ~SmartP();
        InventoryItem* operator->() const;
        InventoryItem& operator*() const;
    };
};

#endif // INVENTORY_H
