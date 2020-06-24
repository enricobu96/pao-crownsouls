#include "armor_bodyarmor.h"

BodyArmor::BodyArmor(U_INT _fallingDef, U_INT _stabbingDef) {
    setFallingDef(_fallingDef);
    setStabbingDef(_stabbingDef);
}

void BodyArmor::setFallingDef(const unsigned int & _fallingDef) {
    if(_fallingDef > 0 && _fallingDef < 100)
        fallingDef = _fallingDef;
    else
        fallingDef = 0;
}

void BodyArmor::setStabbingDef(const unsigned int & _stabbingDef) {
    if(_stabbingDef > 0 && _stabbingDef < 100)
        stabbingDef = _stabbingDef;
    else
        stabbingDef = 0;
}
