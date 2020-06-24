#ifndef ARMOR_H
#define ARMOR_H

#include "inventoryitem.h"

class Armor : virtual public InventoryItem {
public:
    Armor(string, U_SHORT, string, U_INT =0, U_INT =0, U_SHORT =0);

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
