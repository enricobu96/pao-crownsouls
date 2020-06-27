#include "weaponshield.h"

WeaponShield::WeaponShield(U_INT pdmg, U_INT mdmg, U_INT pred, U_INT mred) :
    Weapon(pdmg, mdmg), Shield(pred, mred) {}

//METODI
double WeaponShield::getTotalDmg() const {
    return Weapon::getTotalDmg();
}

double WeaponShield::getTotalRed() const {
    return Shield::getTotalRed();
}

std::string WeaponShield::getType() const {
    return "weaponshield";
}
