#include "weapon.h"

Weapon::Weapon(unsigned int _baseDmg):  baseDmg(_baseDmg) {}

unsigned int Weapon::CalculateQualityDmg()
{
    int level = InventoryItem::getItemLevel();
    return baseDmg + (baseDmg * (0.1*level));
}
