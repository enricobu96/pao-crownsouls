#ifndef SHIELD_H
#define SHIELD_H

#include "inventoryitem.h"

class Shield : public InventoryItem {
public:
    Shield(U_INT =0, U_INT =0);

    //metodi setter
    void setPhysicalRed(const U_INT&);
    void setMagicalRed(const U_INT&);

    U_INT getTotalRed() const;
private:
    U_INT physicalRed;
    U_INT magicalRed;
};

#endif // SHIELD_H
