#ifndef ATTACKSHIELD_H
#define ATTACKSHIELD_H

#include "weaponshield.h"

class AttackShield : public WeaponShield {
public:

    AttackShield(string, U_SHORT, string, U_INT, U_INT, U_INT, U_INT, U_SHORT =0);
    virtual AttackShield* clone() const;

    //SETTER
    void setDexScaling(const U_SHORT&);

    //GETTER
    U_SHORT getDexScaling() const;

    //METODI
    virtual double getTotalRed() const;
    virtual double getTotalDmg() const;

private:
    U_SHORT dexScaling;
};

#endif // ATTACKSHIELD_H
