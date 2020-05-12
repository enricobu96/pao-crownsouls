#include "armor.h"

Armor::Armor(unsigned int _physicalDef, unsigned int _magicalDef, unsigned int _fireDef, unsigned int _electricDef,
             unsigned short _balance, unsigned short _bleedingRes, unsigned short _poisonRes) :
    physicalDef(_physicalDef), magicalDef(_magicalDef), fireDef(_fireDef), electricDef(_electricDef), totalDef(calculateTotalDef()),
    balance(_balance), bleedingRes(_bleedingRes), poisonRes(_poisonRes) {}

unsigned int Armor::calculateTotalDef()
{
    return physicalDef+magicalDef+fireDef+electricDef;
}
