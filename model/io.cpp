#include "io.h"

IO::IO(const QString & s) : name(s) {}

Inventory<InventoryItem*> IO::readFile() const { //questo dovrà ritornare a tab
    Inventory<InventoryItem*> t;
    QFile file(name);
    if(file.open(QIODevice::ReadOnly)) {
        QXmlStreamReader xml(&file);
        xml.readNextStartElement();
        if(xml.name() == "Inventory")
            xml.readNext();
        while(xml.readNextStartElement() && xml.name() == "InventoryItem") {
            try {
                t.pushFront(readFromXml(xml));
            } catch(const std::exception& e) {
                QMessageBox box(QMessageBox::Warning, "File mal formato", "Errore nell'apertura del file.", QMessageBox::Ok);
                throw 1;
                return t;
            }
        }
    } else {
        QMessageBox box(QMessageBox::Warning, "File mal formato", "Errore nell'apertura del file.", QMessageBox::Ok);
        box.exec();
        throw 1;
        return t;
    }
    file.close();
    return t;
}

void IO::write(const Inventory<InventoryItem *>& inv) const {
    QSaveFile file(name);
    if(file.open((QIODevice::WriteOnly))) {
        QXmlStreamWriter xml(&file);
        xml.setAutoFormatting(true);
        xml.writeStartDocument();
        xml.writeStartElement("Inventory");
        try {
            Inventory<InventoryItem*>::Iterator it;
            for(it=inv.begin(); !it.hasFinished() && *it; ++it) {
                writeToXml(*it, xml);
            }
        } catch (const std::exception& e) {
            QMessageBox box(QMessageBox::Warning, "Errore in scrittura", "Errore nella scrittura del file.", QMessageBox::Ok);
            throw 1;
            return;
        }
        xml.writeEndElement();
        xml.writeEndDocument();
        file.commit();
    }
    QMessageBox box(QMessageBox::Warning, "Errore in scrittura", "Errore nella scrittura del file.", QMessageBox::Ok);
    return;
}


InventoryItem* IO::readFromXml(QXmlStreamReader & xml) const {
    string name = "";
    U_INT itemLevel =0;
    string description = "";
    string type = "";
    U_INT pdef = 0;
    U_INT mdef = 0;
    U_INT b = 0;
    U_INT fallingDef = 0;
    U_INT stabbingDef = 0;
    U_INT pdmg = 0;
    U_INT mdmg = 0;
    U_INT strScaling = 0;
    U_INT dexScaling = 0;
    U_INT statsIncreasing = 0;
    U_INT pred = 0;
    U_INT mred = 0;

    xml.readNext();


    if(xml.readNextStartElement() && xml.name() == "name")
        name = xml.readElementText().toUtf8().constData();
    if(xml.readNextStartElement() && xml.name() == "itemLevel")
        itemLevel = xml.readElementText().toInt();
    if(xml.readNextStartElement() && xml.name() == "description")
        description = xml.readElementText().toUtf8().constData();
    if(xml.readNextStartElement() && xml.name() == "type")
        type = xml.readElementText().toUtf8().constData();


    if(type == "armor") {
        if(xml.readNextStartElement() && xml.name() == "physicalDefense")
            pdef = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalDefense")
            mdef = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "balance")
            b = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "fallingDefense")
            fallingDef = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "stabbingDefense")
            stabbingDef = xml.readElementText().toInt();
        xml.skipCurrentElement();
        return new BodyArmor(name, itemLevel, description, pdef, mdef, b, fallingDef, stabbingDef);
    } else if(type == "weaponarmor") {
        if(xml.readNextStartElement() && xml.name() == "physicalDefense")
            pdef = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalDefense")
            mdef = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "balance")
            b = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "physicalDamage")
            pdmg = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalDamage")
            mdmg = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "strenghtScaling")
            strScaling = xml.readElementText().toInt();
        xml.skipCurrentElement();
        return new Gloves(name, itemLevel, description, pdef, mdef, b, pdmg, mdmg, strScaling);
    } else if(type == "ring") {
        if(xml.readNextStartElement() && xml.name() == "statsIncreasing")
            statsIncreasing = xml.readElementText().toInt();
        xml.skipCurrentElement();
        return new Ring(name, itemLevel, description, statsIncreasing);
    } else if(type == "shield") {
        if(xml.readNextStartElement() && xml.name() == "physicalReduction")
            pred = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalReduction")
            mred = xml.readElementText().toInt();
        xml.skipCurrentElement();
        return new DefenseShield(name, itemLevel, description, pred, mred);
    } else if(type == "weapon") {
        if(xml.readNextStartElement() && xml.name() == "physicalDamage")
            pdmg = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalDamage")
            mdmg = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "strenghtScaling")
            strScaling = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "dexScaling")
            dexScaling = xml.readElementText().toInt();
        xml.skipCurrentElement();
        return new AttackWeapon(name, itemLevel, description, pdmg, mdmg, strScaling, dexScaling);
    } else if(type == "weaponshield") {
        if(xml.readNextStartElement() && xml.name() == "physicalDamage")
            pdmg = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalDamage")
            mdmg = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "physicalReduction")
            pred = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "magicalReduction")
            mred = xml.readElementText().toInt();
        if(xml.readNextStartElement() && xml.name() == "dexScaling")
            dexScaling = xml.readElementText().toInt();
        xml.skipCurrentElement();
        return new AttackShield(name, itemLevel, description, pdmg, mdmg, pred, mred, dexScaling);
    }
    xml.skipCurrentElement();
    return nullptr;
}

void IO::writeToXml(InventoryItem* inv, QXmlStreamWriter& xml) const {
    xml.writeStartElement("InventoryItem");

    xml.writeStartElement("name");
    xml.writeCharacters(QString::fromStdString(inv->getName()));
    xml.writeEndElement();

    xml.writeStartElement("itemLevel");
    xml.writeCharacters(QString::number(inv->getItemLevel()));
    xml.writeEndElement();

    xml.writeStartElement("description");
    xml.writeCharacters(QString::fromStdString(inv->getDescription()));
    xml.writeEndElement();

    xml.writeStartElement("type");
    xml.writeCharacters(QString::fromStdString(inv->getType()));
    xml.writeEndElement();

    if(inv->getType() == "armor") {

        xml.writeStartElement("physicalDefense");
        xml.writeCharacters(QString::number(dynamic_cast<BodyArmor*>(inv)->getPhysicalDef()));
        xml.writeEndElement();

        xml.writeStartElement("magicalDefense");
        xml.writeCharacters(QString::number(dynamic_cast<BodyArmor*>(inv)->getMagicalDef()));
        xml.writeEndElement();

        xml.writeStartElement("balance");
        xml.writeCharacters(QString::number(dynamic_cast<BodyArmor*>(inv)->getBalance()));
        xml.writeEndElement();

        xml.writeStartElement("fallingDefense");
        xml.writeCharacters(QString::number(dynamic_cast<BodyArmor*>(inv)->getFallingDef()));
        xml.writeEndElement();

        xml.writeStartElement("stabbingDefense");
        xml.writeCharacters(QString::number(dynamic_cast<BodyArmor*>(inv)->getStabbingDef()));
        xml.writeEndElement();

    } else if(inv->getType() == "weaponarmor") {

        xml.writeStartElement("physicalDefense");
        xml.writeCharacters(QString::number(dynamic_cast<Gloves*>(inv)->getPhysicalDef()));
        xml.writeEndElement();

        xml.writeStartElement("magicalDefense");
        xml.writeCharacters(QString::number(dynamic_cast<Gloves*>(inv)->getMagicalDef()));
        xml.writeEndElement();

        xml.writeStartElement("balance");
        xml.writeCharacters(QString::number(dynamic_cast<Gloves*>(inv)->getBalance()));
        xml.writeEndElement();

        xml.writeStartElement("physicalDamage");
        xml.writeCharacters(QString::number(dynamic_cast<Gloves*>(inv)->getPhysicalDmg()));
        xml.writeEndElement();

        xml.writeStartElement("magicalDamage");
        xml.writeCharacters(QString::number(dynamic_cast<Gloves*>(inv)->getMagicalDmg()));
        xml.writeEndElement();

        xml.writeStartElement("strenghtScaling");
        xml.writeCharacters(QString::number(dynamic_cast<Gloves*>(inv)->getStrScaling()));
        xml.writeEndElement();

    } else if(inv->getType() == "ring") {

        xml.writeStartElement("statsIncreasing");
        xml.writeCharacters(QString::number(dynamic_cast<Ring*>(inv)->getStatsIncreasing()));
        xml.writeEndElement();

    } else if(inv->getType() == "shield") {

        xml.writeStartElement("physicalReduction");
        xml.writeCharacters(QString::number(dynamic_cast<DefenseShield*>(inv)->getPhysicalRed()));
        xml.writeEndElement();

        xml.writeStartElement("magicalReduction");
        xml.writeCharacters(QString::number(dynamic_cast<DefenseShield*>(inv)->getMagicalRed()));
        xml.writeEndElement();

    } else if(inv->getType() == "weapon") {

        xml.writeStartElement("physicalDamage");
        xml.writeCharacters(QString::number(dynamic_cast<AttackWeapon*>(inv)->getPhysicalDmg()));
        xml.writeEndElement();

        xml.writeStartElement("magicalDamage");
        xml.writeCharacters(QString::number(dynamic_cast<AttackWeapon*>(inv)->getMagicalDmg()));
        xml.writeEndElement();

        xml.writeStartElement("strenghtScaling");
        xml.writeCharacters(QString::number(dynamic_cast<AttackWeapon*>(inv)->getStrScaling()));
        xml.writeEndElement();

        xml.writeStartElement("dexScaling");
        xml.writeCharacters(QString::number(dynamic_cast<AttackWeapon*>(inv)->getDexScaling()));
        xml.writeEndElement();

    } else if(inv->getType() == "weaponshield") {

        xml.writeStartElement("physicalDamage");
        xml.writeCharacters(QString::number(dynamic_cast<AttackShield*>(inv)->getPhysicalDmg()));
        xml.writeEndElement();

        xml.writeStartElement("magicalDamage");
        xml.writeCharacters(QString::number(dynamic_cast<AttackShield*>(inv)->getMagicalDmg()));
        xml.writeEndElement();

        xml.writeStartElement("physicalReduction");
        xml.writeCharacters(QString::number(dynamic_cast<AttackShield*>(inv)->getPhysicalRed()));
        xml.writeEndElement();

        xml.writeStartElement("magicalReduction");
        xml.writeCharacters(QString::number(dynamic_cast<AttackShield*>(inv)->getMagicalRed()));
        xml.writeEndElement();

        xml.writeStartElement("dexScaling");
        xml.writeCharacters(QString::number(dynamic_cast<AttackShield*>(inv)->getDexScaling()));
        xml.writeEndElement();

    }

    xml.writeEndElement(); //InventoryItem
}
