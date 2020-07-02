#include "weapon_attackweapon.h"

AttackWeapon::AttackWeapon(string n, U_SHORT il, string d, U_INT pdmg, U_INT mdmg, U_SHORT _strScaling, U_SHORT _dexScaling) :
InventoryItem(n, il, d), Weapon(pdmg, mdmg) {
    setStrScaling(_strScaling);
    setDexScaling(_dexScaling);
}

AttackWeapon *AttackWeapon::clone() const {
    return new AttackWeapon(*this);
}


//SETTER
void AttackWeapon::setStrScaling(const unsigned short & _strScaling) {
    if(_strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}

void AttackWeapon::setDexScaling(const unsigned short & _dexScaling) {
    if(_dexScaling <= 4)
        dexScaling = _dexScaling;
    else
        dexScaling = 0;
}

//GETTER
unsigned short AttackWeapon::getStrScaling() const {
    return strScaling;
}

unsigned short AttackWeapon::getDexScaling() const {
    return dexScaling;
}

//METODI
double AttackWeapon::getTotalDmg() const {
    return Weapon::getTotalDmg()+(strScaling*0.25)+(dexScaling*0.125);
}
