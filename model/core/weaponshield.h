#ifndef WEAPONSHIELD_H
#define WEAPONSHIELD_H

#include "weapon.h"
#include "shield.h"

class WeaponShield : public Weapon , public Shield {
public:
    WeaponShield();
};

#endif // WEAPONSHIELD_H
