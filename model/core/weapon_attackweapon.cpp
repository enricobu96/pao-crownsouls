#include "weapon_attackweapon.h"

AttackWeapon::AttackWeapon(U_SHORT _strScaling, U_SHORT _dexScaling) {
    setStrScaling(_strScaling);
    setDexScaling(_dexScaling);
}

void AttackWeapon::setStrScaling(const unsigned short & _strScaling) {
    if(_strScaling >= 0 && _strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}

void AttackWeapon::setDexScaling(const unsigned short & _dexScaling) {
    if(_dexScaling >= 0 && _dexScaling <= 4)
        dexScaling = _dexScaling;
    else
        dexScaling = 0;
}
