#ifndef WEAPON_H
#define WEAPON_H

#include "inventoryitem.h"

class Weapon : public InventoryItem {
public:
    Weapon(unsigned int =0, unsigned short =0, unsigned short =0, unsigned short =0,
           unsigned short =0);

    unsigned int CalculateQualityDmg();
private:
    unsigned int BaseDmg;
    unsigned int QualityDmg;
    unsigned short StrScaling;
    unsigned short DexScaling;
    unsigned short IntScaling;
    unsigned short FthScaling;
};

#endif // WEAPON_H
