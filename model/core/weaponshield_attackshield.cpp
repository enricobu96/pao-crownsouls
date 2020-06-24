#include "weaponshield_attackshield.h"

AttackShield::AttackShield(U_SHORT _dexScaling) {
    setDexScaling(_dexScaling);
}

void AttackShield::setDexScaling(const unsigned short & _dexScaling) {
    if(_dexScaling >= 0 && _dexScaling <= 4)
        dexScaling = _dexScaling;
    else
        dexScaling = 0;
}
