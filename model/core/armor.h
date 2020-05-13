#ifndef ARMOR_H
#define ARMOR_H

#include "inventoryitem.h"

class Armor : public InventoryItem {
public:
    Armor(unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0,
          unsigned short =0, unsigned short =0, unsigned short =0);

    unsigned int calculateTotalDef();
private:
    unsigned int physicalDef;
    unsigned int magicalDef;
    unsigned int fireDef;
    unsigned int electricDef;
    unsigned int totalDef;
    unsigned short balance;
    unsigned short bleedingRes;
    unsigned short poisonRes;
};

#endif // ARMOR_H
