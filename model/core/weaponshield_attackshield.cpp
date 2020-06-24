#include "weaponshield_attackshield.h"

AttackShield::AttackShield(string n, U_SHORT il, string d, U_INT pdmg, U_INT mdmg, U_INT pred, U_INT mred, U_SHORT _dexScaling) :
WeaponShield(n, il, d, pdmg, mdmg, pred, mred) {
    setDexScaling(_dexScaling);
}

void AttackShield::setDexScaling(const unsigned short & _dexScaling) {
    if(_dexScaling <= 4)
        dexScaling = _dexScaling;
    else
        dexScaling = 0;
}
