#include "weapon.h"

Weapon::Weapon(string n, U_SHORT il, string d, U_INT _physicalDmg, U_INT _magicalDmg):
    InventoryItem(n, il, d) {
    setPhysicalDmg(_physicalDmg);
    setMagicalDmg(_magicalDmg);
    levelDmg = CalculateLevelDmg();
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

