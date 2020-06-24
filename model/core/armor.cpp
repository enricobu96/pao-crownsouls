#include "armor.h"

Armor::Armor(string n, U_SHORT il, string d, U_INT _physicalDef, U_INT _magicalDef, U_SHORT _balance) : InventoryItem(n, il, d) {
    setPhysicalDef(_physicalDef);
    setMagicalDef(_magicalDef);
    setBalance(_balance);
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


void Armor::setBalance(const unsigned short & _balance) {
    if(_balance > 0 && _balance < 30)
        physicalDef = _balance;
    else
        balance = 0;
}


U_INT Armor::getTotalDef() const
{
    return physicalDef+magicalDef;
}
