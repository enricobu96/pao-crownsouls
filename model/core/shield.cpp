#include "shield.h"

Shield::Shield(string n, U_SHORT il, string d, U_INT _physicalRed, U_INT _magicalRed) :
    InventoryItem(n, il, d) {
    setPhysicalRed(_physicalRed);
    setMagicalRed(_magicalRed);
}

void Shield::setPhysicalRed(const unsigned int & _physicalRed) {
    if(_physicalRed > 0 && _physicalRed < 100)
        physicalRed = _physicalRed;
    else
        physicalRed = 0;
}

void Shield::setMagicalRed(const unsigned int & _magicalRed) {
    if(_magicalRed > 0 && _magicalRed < 100)
        magicalRed = _magicalRed;
    else
        magicalRed = 0;
}

U_INT Shield::getTotalRed() const
{
    return physicalRed+magicalRed;
}

