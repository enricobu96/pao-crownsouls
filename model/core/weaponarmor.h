#ifndef WEAPONARMOR_H
#define WEAPONARMOR_H

#include "armor.h"
#include "weapon.h"

class WeaponArmor : public Armor , public Weapon {
public:
    WeaponArmor();
};

#endif // WEAPONARMOR_H
