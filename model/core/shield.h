#ifndef SHIELD_H
#define SHIELD_H

#include "inventoryitem.h"

class Shield : virtual public InventoryItem {
public:
    Shield(string, U_SHORT, string, U_INT =0, U_INT =0);

    //metodi setter
    void setPhysicalRed(const U_INT&);
    void setMagicalRed(const U_INT&);

    U_INT getTotalRed() const;
private:
    U_INT physicalRed;
    U_INT magicalRed;
};

#endif // SHIELD_H
