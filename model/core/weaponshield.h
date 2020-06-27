#ifndef WEAPONSHIELD_H
#define WEAPONSHIELD_H

#include "weapon.h"
#include "shield.h"

class WeaponShield : public Weapon , public Shield {
public:
    WeaponShield(U_INT, U_INT, U_INT, U_INT);
    virtual ~WeaponShield() =default;

    //METODI
    virtual double getTotalDmg() const override;
    virtual double getTotalRed() const override;
    virtual string getType() const override;
};

#endif // WEAPONSHIELD_H
