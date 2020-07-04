#ifndef WEAPONARMOR_H
#define WEAPONARMOR_H

#include "armor.h"
#include "weapon.h"

class WeaponArmor : public Armor , public Weapon {
public:

    WeaponArmor(U_INT, U_INT, U_INT, U_INT =0, U_INT =0);
    virtual ~WeaponArmor() =default;

    //METODI
    virtual double getTotalDef() const override;
    virtual string getType() const override;

};

#endif // WEAPONARMOR_H
