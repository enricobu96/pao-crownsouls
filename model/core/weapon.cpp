#include "weapon.h"

Weapon::Weapon(U_INT _physicalDmg, U_INT _magicalDmg, U_INT _fireDmg, U_INT _electricDmg):
    levelDmg(CalculateLevelDmg()) {
    setPhysicalDmg(_physicalDmg);
    setMagicalDmg(_magicalDmg);
    setFireDmg(_fireDmg);
    setElectricDmg(_electricDmg);
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

void Weapon::setFireDmg(const unsigned int & _fireDmg) {
    if(_fireDmg > 0 && _fireDmg < 500)
        fireDmg = _fireDmg;
    else
        fireDmg = 0;
}

void Weapon::setElectricDmg(const unsigned int & _electricDmg) {
    if(_electricDmg > 0 && _electricDmg < 500)
        electricDmg = _electricDmg;
    else
        electricDmg = 0;
}

U_INT Weapon::CalculateLevelDmg() const {
    return InventoryItem::getItemLevel()*3;
}

U_INT Weapon::getTotalDmg() const
{
    return physicalDmg+magicalDmg+fireDmg+electricDmg+levelDmg;
}

