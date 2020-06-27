#ifndef ARMOR_H
#define ARMOR_H

#include "inventoryitem.h"

class Armor : virtual public InventoryItem {
public:

    Armor(U_INT =0, U_INT =0, U_SHORT =0);
    virtual ~Armor() =default;

    //SETTER
    void setPhysicalDef(const U_INT &);
    void setMagicalDef(const U_INT &);
    void setBalance(const U_SHORT &);

    //GETTER
    U_INT getPhysicalDef() const;
    U_INT getMagicalDef() const;
    U_SHORT getBalance() const;

    //METODI
    virtual double getTotalDef() const =0;
    virtual string getType() const override;

private:
    U_INT physicalDef;
    U_INT magicalDef;
    U_SHORT balance;
};

#endif // ARMOR_H
