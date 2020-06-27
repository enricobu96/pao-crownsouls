#include "weaponarmor.h"

WeaponArmor::WeaponArmor(U_INT pdef, U_INT mdef, U_SHORT b, U_INT pdmg, U_INT mdmg) :
    Armor(pdef, mdef, b), Weapon(pdmg, mdmg) {}

//METODI
double WeaponArmor::getTotalDef() const {
    return Armor::getTotalDef();
}

std::string WeaponArmor::getType() const {
    return "weaponarmor";
}
