#include "weaponshield_attackshield.h"

AttackShield::AttackShield(string n, U_INT il, string d, U_INT pdmg, U_INT mdmg, U_INT pred, U_INT mred, U_INT _dexScaling) :
    InventoryItem(n, il, d), WeaponShield(pdmg, mdmg, pred, mred) {
    setDexScaling(_dexScaling);
}

AttackShield *AttackShield::clone() const {
    return new AttackShield(*this);
}

//SETTER
void AttackShield::setDexScaling(const U_INT & _dexScaling) {
    if(_dexScaling <= 4)
        dexScaling = _dexScaling;
    else
        dexScaling = 0;
}

//GETTER
U_INT AttackShield::getDexScaling() const {
    return dexScaling;
}

//METODI
double AttackShield::getTotalRed() const {
    return WeaponShield::getTotalRed()+dexScaling*0.15;
}

double AttackShield::getTotalDmg() const {
    return WeaponShield::getTotalDmg()+dexScaling*0.33;
}
