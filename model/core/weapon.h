#ifndef WEAPON_H
#define WEAPON_H

#include "inventoryitem.h"

class Weapon : virtual public InventoryItem {
public:
    Weapon(string, U_SHORT, string, U_INT =0, U_INT =0);

    //metodi setter
    void setPhysicalDmg(const U_INT &);
    void setMagicalDmg(const U_INT &);

    U_INT CalculateLevelDmg() const;
    U_INT getTotalDmg() const;
private:
    U_INT physicalDmg;
    U_INT magicalDmg;
    U_INT levelDmg;
};

#endif // WEAPON_H
