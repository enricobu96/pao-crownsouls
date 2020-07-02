#include "armor.h"

Armor::Armor(U_INT _physicalDef, U_INT _magicalDef, U_SHORT _balance) {
    setPhysicalDef(_physicalDef);
    setMagicalDef(_magicalDef);
    setBalance(_balance);
}

//SETTER
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
        balance = _balance;
    else
        balance = 0;
}


//GETTER
unsigned int Armor::getPhysicalDef() const {
    return physicalDef;
}

unsigned int Armor::getMagicalDef() const {
    return magicalDef;
}

unsigned short Armor::getBalance() const {
    return balance;
}

//METODI
double Armor::getTotalDef() const {
    return physicalDef+magicalDef;
}

std::string Armor::getType() const {
    return "armor";
}
