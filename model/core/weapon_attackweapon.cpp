#include "weapon_attackweapon.h"

AttackWeapon::AttackWeapon(string n, U_INT il, string d, U_INT pdmg, U_INT mdmg, U_INT _strScaling, U_INT _dexScaling) :
InventoryItem(n, il, d), Weapon(pdmg, mdmg) {
    setStrScaling(_strScaling);
    setDexScaling(_dexScaling);
}

AttackWeapon *AttackWeapon::clone() const {
    return new AttackWeapon(*this);
}


//SETTER
void AttackWeapon::setStrScaling(const U_INT & _strScaling) {
    if(_strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}

void AttackWeapon::setDexScaling(const U_INT & _dexScaling) {
    if(_dexScaling <= 4)
        dexScaling = _dexScaling;
    else
        dexScaling = 0;
}

//GETTER
U_INT AttackWeapon::getStrScaling() const {
    return strScaling;
}

U_INT AttackWeapon::getDexScaling() const {
    return dexScaling;
}

//METODI
double AttackWeapon::getTotalDmg() const {
    return Weapon::getTotalDmg()+(strScaling*0.25)+(dexScaling*0.125);
}
