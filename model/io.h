#ifndef IO_H
#define IO_H

#include<QFile>
#include<QXmlStreamReader>
#include<iostream>
#include<QSaveFile>
#include<QString>
#include<QMessageBox>
#include"inventory.hpp"
#include"model.h"


class IO {
public:
    //COSTRUTTORE
    IO(const QString&);

    //METODI
    //lettura
    Inventory<InventoryItem*> readFile() const;

    //scrittura
    void write(const Inventory<InventoryItem*>&) const;

private:
    QString name; //nome del file
    InventoryItem* readFromXml(QXmlStreamReader &) const;
    void writeToXml(InventoryItem*, QXmlStreamWriter &) const;
};

#endif // IO_H
