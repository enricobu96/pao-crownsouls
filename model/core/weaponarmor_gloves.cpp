#include "weaponarmor_gloves.h"

Gloves::Gloves(string n, U_SHORT il, string d, U_INT pdef, U_INT mdef, U_SHORT b, U_INT pdmg, U_INT mdmg, U_SHORT _strScaling) :
InventoryItem(n, il, d), WeaponArmor(pdef, mdef, b, pdmg, mdmg) {
    setStrScaling(_strScaling);
}

Gloves *Gloves::clone() const {
    return new Gloves(*this);
}

//SETTER
void Gloves::setStrScaling(const unsigned short & _strScaling) {
    if(_strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}

//GETTER
unsigned short Gloves::getStrScaling() const { return strScaling; }

//METODI
double Gloves::getTotalDef() const {
    //IL +1 SU STR SCALING È PER EVITARE CHE SIA 0
    return WeaponArmor::getTotalDef()*(strScaling+1)*0.25;
}
