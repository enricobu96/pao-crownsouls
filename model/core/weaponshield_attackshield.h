#ifndef ATTACKSHIELD_H
#define ATTACKSHIELD_H

#include "weaponshield.h"

class AttackShield : public WeaponShield {
public:

    AttackShield(string, U_INT, string, U_INT, U_INT, U_INT, U_INT, U_INT =0);
    virtual AttackShield* clone() const;

    //SETTER
    void setDexScaling(const U_INT&);

    //GETTER
    U_INT getDexScaling() const;

    //METODI
    virtual double getTotalRed() const;
    virtual double getTotalDmg() const;

private:
    U_INT dexScaling;
};

#endif // ATTACKSHIELD_H
