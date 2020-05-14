#ifndef WEAPON_H
#define WEAPON_H

#include "inventoryitem.h"

class Weapon : public InventoryItem {
public:
    Weapon(unsigned int =0);

    unsigned int CalculateQualityDmg();
private:
    unsigned int baseDmg;
    unsigned int qualityDmg;
};

#endif // WEAPON_H
