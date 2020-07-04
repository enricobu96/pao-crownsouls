#include "weaponarmor_gloves.h"

Gloves::Gloves(string n, U_INT il, string d, U_INT pdef, U_INT mdef, U_INT b, U_INT pdmg, U_INT mdmg, U_INT _strScaling) :
InventoryItem(n, il, d), WeaponArmor(pdef, mdef, b, pdmg, mdmg) {
    setStrScaling(_strScaling);
}

Gloves *Gloves::clone() const {
    return new Gloves(*this);
}

//SETTER
void Gloves::setStrScaling(const U_INT & _strScaling) {
    if(_strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}

//GETTER
U_INT Gloves::getStrScaling() const {
    return strScaling;
}

//METODI
double Gloves::getTotalDef() const {
    return WeaponArmor::getTotalDef()+strScaling*0.25;
}
