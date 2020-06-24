#ifndef WEAPON_H
#define WEAPON_H

#include "inventoryitem.h"

class Weapon : virtual public InventoryItem {
public:

    Weapon(U_INT =0, U_INT =0);

    //SETTER
    void setPhysicalDmg(const U_INT &);
    void setMagicalDmg(const U_INT &);

    //GETTER
    U_INT getPhysicalDmg() const;
    U_INT getMagicalDmg() const;
    U_INT getLevelDmg() const;

    //METODI
    U_INT CalculateLevelDmg() const;
    virtual double getTotalDmg() const;

private:
    U_INT physicalDmg;
    U_INT magicalDmg;
    U_INT levelDmg;
};

#endif // WEAPON_H
