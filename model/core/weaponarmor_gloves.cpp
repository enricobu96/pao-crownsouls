#include "weaponarmor_gloves.h"

Gloves::Gloves(string n, U_SHORT il, string d, U_INT pdef, U_INT mdef, U_SHORT b, U_INT pdmg, U_INT mdmg, U_SHORT _strScaling) :
WeaponArmor(n, il, d, pdef, mdef, b, pdmg, mdmg) {
    setStrScaling(_strScaling);
}

void Gloves::setStrScaling(const unsigned short & _strScaling) {
    if(_strScaling >= 0 && _strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}
