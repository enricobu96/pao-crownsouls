#include "weapon.h"

Weapon::Weapon(U_INT _physicalDmg, U_INT _magicalDmg):
    levelDmg(CalculateLevelDmg()) {
    setPhysicalDmg(_physicalDmg);
    setMagicalDmg(_magicalDmg);
}

void Weapon::setPhysicalDmg(const unsigned int & _physicalDmg) {
    if(_physicalDmg > 0 && _physicalDmg < 500)
        physicalDmg = _physicalDmg;
    else
        physicalDmg = 0;
}

void Weapon::setMagicalDmg(const unsigned int & _magicalDmg) {
    if(_magicalDmg > 0 && _magicalDmg < 500)
        magicalDmg = _magicalDmg;
    else
        magicalDmg = 0;
}


U_INT Weapon::CalculateLevelDmg() const {
    return InventoryItem::getItemLevel()*3;
}

U_INT Weapon::getTotalDmg() const
{
    return physicalDmg+magicalDmg+levelDmg;
}

