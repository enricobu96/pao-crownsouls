#ifndef RING_H
#define RING_H

#include "inventoryitem.h"
#include "string"

using std::string;

class Ring : public InventoryItem {
public:

    Ring(string, U_SHORT, string, string ="Storia non definita");
    virtual Ring* clone() const;

    //SETTER
    void setFlavour(const string&);

    //GETTER
    string getFlavour() const;

    //METODI
    virtual string getType() const override;

private:
    string flavour;
};

#endif // RING_H
