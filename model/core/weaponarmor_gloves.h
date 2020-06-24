#ifndef GLOVES_H
#define GLOVES_H

#include "weaponarmor.h"

class Gloves : public WeaponArmor {
public:
    Gloves(string, U_SHORT, string, U_INT, U_INT, U_SHORT, U_INT, U_INT, U_SHORT =0);

    void setStrScaling(const U_SHORT&);

private:
    U_SHORT strScaling;
};

#endif // GLOVES_H
