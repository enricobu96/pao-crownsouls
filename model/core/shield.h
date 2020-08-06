#ifndef SHIELD_H
#define SHIELD_H

#include "inventoryitem.h"

class Shield : virtual public InventoryItem {
public:

    Shield(U_INT =0, U_INT =0);
    virtual ~Shield() =default;

    //SETTER
    void setPhysicalRed(const U_INT&);
    void setMagicalRed(const U_INT&);

    //GETTER
    U_INT getPhysicalRed() const;
    U_INT getMagicalRed() const;

    //METODI
    virtual double getTotalRed() const;
    virtual string getType() const override;

private:
    U_INT physicalRed;
    U_INT magicalRed;
};

#endif // SHIELD_H
