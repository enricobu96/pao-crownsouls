#include "weaponarmor_gloves.h"

Gloves::Gloves(U_SHORT _strScaling) {
    setStrScaling(_strScaling);
}

void Gloves::setStrScaling(const unsigned short & _strScaling) {
    if(_strScaling >= 0 && _strScaling <= 4)
        strScaling = _strScaling;
    else
        strScaling = 0;
}
