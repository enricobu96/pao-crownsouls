#include "weapon.h"

Weapon::Weapon(U_INT _physicalDmg, U_INT _magicalDmg) {
    setPhysicalDmg(_physicalDmg);
    setMagicalDmg(_magicalDmg);
    levelDmg = CalculateLevelDmg();
}

//SETTER
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

//GETTER
unsigned int Weapon::getPhysicalDmg() const { return physicalDmg; }
unsigned int Weapon::getMagicalDmg() const { return magicalDmg; }
unsigned int Weapon::getLevelDmg() const { return levelDmg; }

//METODI
U_INT Weapon::CalculateLevelDmg() const {
    return InventoryItem::getItemLevel()*3;
}

double Weapon::getTotalDmg() const {
    return physicalDmg+magicalDmg+levelDmg;
}

std::string Weapon::getType() const {
    return "weapon";
}

