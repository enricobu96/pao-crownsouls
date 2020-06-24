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
    BodyArmor* ba = new BodyArmor("bodyarmor", 5, "bbbodyarmor", 4, 4, 4, 4, 4);
    cout << "prima bodyarmor be liek:" << endl;
    cout << ba->getName() << " " << ba->getItemLevel() << " " << ba->getDescription() << " " << ba->getPhysicalDef() << " " <<
            ba->getMagicalDef() << " " << ba->getBalance()<< " " <<ba->getFallingDef()<< " " << ba->getStabbingDef() << endl;



    Gloves* g = new Gloves("gloves",  9, "gggloves", 9, 9, 9, 9, 9, 2);
    cout << "prima gloves be liek:" << endl;
    cout << g->getName() << " " << g->getItemLevel() << " " << g->getDescription() << " " <<
            g->getPhysicalDef() << " " << g->getMagicalDef() << " " << g->getBalance() << " " <<
            g->getPhysicalDmg() << " " << g->getMagicalDmg() << " " << g->getStrScaling() << endl;



    AttackWeapon* aw = new AttackWeapon("attackweapon", 1, "aaaattackweapon", 1, 1, 1, 1);
    cout << "prima attackweapon be liek:" << endl;
    cout << aw->getName() << " " << aw->getItemLevel() << " " << aw->getDescription() << " " <<
            aw->getPhysicalDmg() << " " << aw->getMagicalDmg() << " " << aw->getStrScaling() << " " <<
            aw->getDexScaling() << endl;



    AttackShield* ass = new AttackShield("attackshield", 2, "aaaaattackshield", 2, 2, 2, 2, 2);
    cout << "prima attackshield be liek:" << endl;
    cout << ass->getName() << " " << ass->getItemLevel() << " " << ass->getDescription() << " " <<
            ass->getPhysicalDmg() << " " << ass->getMagicalDmg() << " " << ass->getPhysicalRed() << " " <<
            ass->getMagicalRed() << " " << ass->getDexScaling() << endl;



    DefenseShield* ds = new DefenseShield("defenseshield", 3, "dddefenseshield", 3, 3, 3);
    cout << "prima defenseshield be liek:" << endl;
    cout << ds->getName() << " " << ds->getItemLevel() << " " << ds->getDescription() << " " <<
            ds->getPhysicalRed() << " " << ds->getMagicalRed() << " " << ds->getSpeedPenality() << endl;



    Ring* r = new Ring("primo anello", 5, "descrizione primo anello", "storia del primo anello");
    cout << "primo anello be liek:" <<endl;
    cout << r->getName() << " " << r->getItemLevel() << " " << r->getDescription() << " " << r->getFlavour() << endl;


    //TEST DEI METODI DELLA GERARCHIA
    cout << "bodyarmor: " << ba->getTotalDef() << endl;
    cout << "gloves: " << g->getTotalDef() << " " << g->getTotalDmg() << endl;
    cout << "attackweapon: " << aw->getTotalDmg() << endl;
    cout << "attackshield: " << ass->getTotalDmg() << " " << ass->getTotalRed() << endl;
    cout << "defenseshield: " << ds->getTotalRed() << endl;

}
