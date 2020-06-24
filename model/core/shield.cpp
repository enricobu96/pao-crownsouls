#include "shield.h"

Shield::Shield(U_INT _physicalRed, U_INT _magicalRed, U_INT _fireRed, U_INT _electricRed) :
    physicalRed(_physicalRed), magicalRed(_magicalRed), fireRed(_fireRed), electricRed(_electricRed) {}

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

void Shield::setFireRed(const unsigned int & _fireRed) {
    if(_fireRed > 0 && _fireRed < 100)
        fireRed = _fireRed;
    else
        fireRed = 0;
}

void Shield::setElectricRed(const unsigned int & _electricRed) {
    if(_electricRed > 0 && _electricRed < 100)
        electricRed = _electricRed;
    else
        electricRed = 0;
}

U_INT Shield::getTotalRed() const
{
    return physicalRed+magicalRed+fireRed+electricRed;
}

