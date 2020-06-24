#ifndef AXE_H
#define AXE_H

#include "weapon.h"

class AttackWeapon : public Weapon {
public:
    AttackWeapon(U_SHORT =0, U_SHORT =0);

    //metodi setter
    void setStrScaling(const U_SHORT&);
    void setDexScaling(const U_SHORT&);

private:
    U_SHORT strScaling;
    U_SHORT dexScaling;
};

#endif // AXE_H
