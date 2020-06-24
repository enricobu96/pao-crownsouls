#include "view/mainwindow.h"
#include <QApplication>

//FOR DEBUG PURPOSES ONLY
#include<iostream>
#include "model/core/armor.h"
#include "model/core/armor_bodyarmor.h"
#include "model/core/inventoryitem.h"
#include "model/core/ring.h"
#include "model/core/shield.h"
#include "model/core/shield_defenseshield.h"
#include "model/core/weapon.h"
#include "model/core/weapon_attackweapon.h"
#include "model/core/weaponarmor.h"
#include "model/core/weaponarmor_gloves.h"
#include "model/core/weaponshield.h"
#include "model/core/weaponshield_attackshield.h"
#include "model/inventory.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec(); */

    cout << "entrato nel main" << endl;

    //TESTING CREAZIONE OGGETTI DELLA GERARCHIA

    //ASTRATTE NORMALI - check
    //InventoryItem* i = new InventoryItem("aaaa" , 69, "bbbb"); //non compila e questo è esattamente quello che voglio
    //Armor* a = new Armor("aaa", 420, "bbb", 3, 3, 3); //non compila e questo è esattamente quello che voglio
    //Weapon* w = new Weapon("aaaa", 69, "bbbb", 7, 7, 7); //non compila e questo è esattamente quello che voglio
    //Shield* s = new Shield("aaa", 69, "bbb", 5, 5); //non compila e questo è esattamente quello che voglio

    //ASTRATTE EREDITARIETÀ MULTIPLA - check
    //WeaponArmor wa = new WeaponArmor("aaa", 63, "bbb", 5, 5, 5, 5, 5); //non compila e questo è esattamente quello che voglio
    //WeaponShield ws = new WeaponShield("aaa", 54, "bbb", 3, 3, 3, 3); //non compila e questo è esattamente quello che voglio

    //CONCRETE
    BodyArmor* ba = new BodyArmor("aaa", 5, "bbb", 4, 4, 4, 4, 4);
    cout << "prima bodyarmor be liek:" << endl;
    cout << ba->getName() << " " << ba->getItemLevel() << " " << ba->getDescription() << " " << ba->getPhysicalDef() << " " <<
            ba->getMagicalDef() << " " << ba->getBalance()<< " " <<ba->getFallingDef()<< " " << ba->getStabbingDef() << endl;

    Ring* r = new Ring("primo anello", 5, "descrizione primo anello", "storia del primo anello");
    cout << "primo anello be liek:" <<endl;
    cout << r->getName() << " " << r->getItemLevel() << " " << r->getDescription() << " " << r->getFlavour() << endl;

}
