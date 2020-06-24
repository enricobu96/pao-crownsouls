#include "armor_bodyarmor.h"

BodyArmor::BodyArmor(string n, U_SHORT il, string d, U_INT pdef, U_INT mdef, U_SHORT b, U_INT _fallingDef, U_INT _stabbingDef) :
Armor(n, il, d, pdef, mdef, b) {
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
