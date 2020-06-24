#ifndef RING_H
#define RING_H

#include "inventoryitem.h"
#include "string"

using std::string;

class Ring : public InventoryItem {
public:
    Ring(string, U_SHORT, string, string ="Storia non definita");

    string getFlavour() const;
private:
    string flavour;
};

#endif // RING_H
