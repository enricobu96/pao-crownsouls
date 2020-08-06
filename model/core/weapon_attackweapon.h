#ifndef AXE_H
#define AXE_H

#include "weapon.h"

class AttackWeapon : public Weapon {
public:

    AttackWeapon(string, U_INT, string, U_INT, U_INT, U_INT =0, U_INT =0);
    virtual AttackWeapon* clone() const;

    //SETTER
    void setStrScaling(const U_INT&);
    void setDexScaling(const U_INT&);

    //GETTER
    U_INT getStrScaling() const;
    U_INT getDexScaling() const;

    //METODI
    virtual double getTotalDmg() const;

private:
    U_INT strScaling;
    U_INT dexScaling;
};

#endif // AXE_H
