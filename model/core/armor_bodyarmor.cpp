#include "armor_bodyarmor.h"

BodyArmor::BodyArmor(string n, U_INT il, string d, U_INT pdef, U_INT mdef, U_INT b, U_INT _fallingDef, U_INT _stabbingDef) :
InventoryItem(n, il, d), Armor(pdef, mdef, b) {
    setFallingDef(_fallingDef);
    setStabbingDef(_stabbingDef);
}

BodyArmor *BodyArmor::clone() const {
    return new BodyArmor(*this);
}

//SETTER
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

//GETTER
unsigned int BodyArmor::getFallingDef() const {
    return fallingDef;
}

unsigned int BodyArmor::getStabbingDef() const {
    return stabbingDef;
}

//METODI
double BodyArmor::getTotalDef() const {
    return Armor::getTotalDef() + fallingDef + stabbingDef;
}
