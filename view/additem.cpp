#include "additem.h"

AddItem::AddItem(QString t, QWidget *parent): QDialog(parent)
{
    nameLabel = new QLabel("Nome Oggetto");
    typeLabel = new QLabel("Tipologia Oggetto");
    descLabel = new QLabel("Descrizione");

    namePlaceholder = new QLineEdit;
    namePlaceholder->setPlaceholderText("Nome oggetto");

    flavourText = new QTextEdit;

    typeItemBox = new QComboBox;
    typeItemBox->addItem("Arma");
    typeItemBox->addItem("Armatura");
    typeItemBox->addItem("Anello");

    gridLayout = new QGridLayout;
    gridLayout->addWidget(nameLabel,0,0);
    gridLayout->addWidget(namePlaceholder,0,1);
    gridLayout->addWidget(typeLabel,0,2);
    gridLayout->addWidget(typeItemBox,0,3);
    gridLayout->addWidget(descLabel,1,0);
    gridLayout->addWidget(flavourText,1,1,2,4);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);
    setWindowTitle(t);
}
