#include "armor.h"

Armor::Armor(U_INT _physicalDef, U_INT _magicalDef, U_INT _fireDef, U_INT _electricDef,
             U_SHORT _balance, U_SHORT _bleedingRes, U_SHORT _poisonRes) : InventoryItem() {
    setPhysicalDef(_physicalDef);
    setMagicalDef(_magicalDef);
    setFireDef(_fireDef);
    setElectricDef(_electricDef);
    setBalance(_balance);
    setBleedingRes(_bleedingRes);
    setPoisonRes(_poisonRes);
}

void Armor::setPhysicalDef(const unsigned int & _physicalDef) {
    if(_physicalDef > 0 && _physicalDef < 200)
        physicalDef = _physicalDef;
    else
        physicalDef = 0;
}

void Armor::setMagicalDef(const unsigned int & _magicalDef) {
    if(_magicalDef > 0 && _magicalDef < 200)
        magicalDef = _magicalDef;
    else
        magicalDef = 0;
}

void Armor::setFireDef(const unsigned int & _fireDef) {
    if(_fireDef > 0 && _fireDef < 200)
        fireDef = _fireDef;
    else
        fireDef = 0;
}

void Armor::setElectricDef(const unsigned int & _electricDef) {
    if(_electricDef > 0 && _electricDef < 200)
        electricDef = _electricDef;
    else
        electricDef = 0;
}

void Armor::setBalance(const unsigned short & _balance) {
    if(_balance > 0 && _balance < 30)
        physicalDef = _balance;
    else
        balance = 0;
}

void Armor::setBleedingRes(const unsigned short & _bleedingRes) {
    if(_bleedingRes > 0 && _bleedingRes < 150)
        bleedingRes = _bleedingRes;
    else
        bleedingRes = 0;
}

void Armor::setPoisonRes(const unsigned short & _poisonRes) {
    if(_poisonRes > 0 && _poisonRes < 150)
        poisonRes = _poisonRes;
    else
        poisonRes = 0;
}

U_INT Armor::getTotalDef() const
{
    return physicalDef+magicalDef+fireDef+electricDef;
}
