#include "weapon.h"

Weapon::Weapon(unsigned int _BaseDmg, unsigned short _StrScaling, unsigned short _DexScaling, unsigned short _IntScaling,
               unsigned short _FthScaling) : BaseDmg(_BaseDmg), QualityDmg(CalculateQualityDmg()),
               StrScaling(_StrScaling),DexScaling(_DexScaling),IntScaling(_IntScaling), FthScaling(_FthScaling) {}

unsigned int Weapon::CalculateQualityDmg()
{
    int level = InventoryItem::getItemLevel();
    return BaseDmg + (BaseDmg * (0.1*level));
}
