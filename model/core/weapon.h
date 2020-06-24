#ifndef WEAPON_H
#define WEAPON_H

#include "inventoryitem.h"

class Weapon : public InventoryItem {
public:
    Weapon(U_INT =0, U_INT =0, U_INT =0, U_INT =0);

    //metodi setter
    void setPhysicalDmg(const U_INT &);
    void setMagicalDmg(const U_INT &);
    void setFireDmg(const U_INT &);
    void setElectricDmg(const U_INT &);

    U_INT CalculateLevelDmg() const;
    U_INT getTotalDmg() const;
private:
    U_INT physicalDmg;
    U_INT magicalDmg;
    U_INT fireDmg;
    U_INT electricDmg;
    U_INT levelDmg;
};

#endif // WEAPON_H
