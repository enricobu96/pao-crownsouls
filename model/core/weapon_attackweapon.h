#ifndef AXE_H
#define AXE_H

#include "weapon.h"

class AttackWeapon : public Weapon {
public:

    AttackWeapon(string, U_SHORT, string, U_INT, U_INT, U_SHORT =0, U_SHORT =0);
    virtual AttackWeapon* clone() const;

    //SETTER
    void setStrScaling(const U_SHORT&);
    void setDexScaling(const U_SHORT&);

    //GETTER
    U_SHORT getStrScaling() const;
    U_SHORT getDexScaling() const;

    //METODI
    virtual double getTotalDmg() const;

private:
    U_SHORT strScaling;
    U_SHORT dexScaling;
};

#endif // AXE_H
