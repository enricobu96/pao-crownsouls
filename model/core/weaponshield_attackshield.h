#ifndef ATTACKSHIELD_H
#define ATTACKSHIELD_H

#include "weaponshield.h"

class AttackShield : public WeaponShield {
public:
    AttackShield(string, U_SHORT, string, U_INT, U_INT, U_INT, U_INT, U_SHORT =0);

    void setDexScaling(const U_SHORT&);
private:
    U_SHORT dexScaling;
};

#endif // ATTACKSHIELD_H
