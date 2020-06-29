#ifndef RING_H
#define RING_H

#include "inventoryitem.h"
#include "string"

using std::string;

class Ring : public InventoryItem {
public:

    Ring(string, U_SHORT, string, U_INT =0);
    virtual Ring* clone() const override;

    //SETTER
    void setStatsIncreasing(const U_INT&);

    //GETTER
    U_INT getStatsIncreasing() const;

    //METODI
    virtual string getType() const override;

private:
    U_INT statsIncreasing;
};

#endif // RING_H
