#ifndef ARMOR_H
#define ARMOR_H

#include "inventoryitem.h"

class Armor : public InventoryItem {
public:
    Armor( U_INT =0, U_INT =0, U_SHORT =0);

    //metodi setter
    void setPhysicalDef(const U_INT &);
    void setMagicalDef(const U_INT &);
    void setBalance(const U_SHORT &);

    virtual U_INT getTotalDef() const =0;
private:
    U_INT physicalDef;
    U_INT magicalDef;
    U_SHORT balance;
};

#endif // ARMOR_H
