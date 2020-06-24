#ifndef WEAPONSHIELD_H
#define WEAPONSHIELD_H

#include "weapon.h"
#include "shield.h"

class WeaponShield : public Weapon , public Shield {
public:
    WeaponShield(string, U_SHORT, string, U_INT, U_INT, U_INT, U_INT);

    //METODI
    virtual double getTotalDmg() const;
    virtual double getTotalRed() const;
};

#endif // WEAPONSHIELD_H
