#include "additem.h"

AddItem::AddItem(QString t, QWidget *parent): QDialog(parent)
{
    //NOME ITEM
    nameLabel = new QLabel("Item Name");
    namePlaceholder = new QLineEdit;
    namePlaceholder->setPlaceholderText("Insert name");

    //DESCRIZIONE ITEM
    descLabel = new QLabel("Description");
    flavourText = new QTextEdit;

    //ITEM LEVEl
    ilvlLabel = new QLabel("Item Level");
    levelItem = new QSpinBox;
    levelItem->setRange(0,99);
    levelItem->setAlignment(Qt::AlignCenter);

    //BOTTONI VARI PER ACCETTARE / CANCELLARE
    buttok = new QPushButton("Add");

    //COMBOBOX TIPOLOGIA ITEM
    typeLabel = new QLabel("Item Type");
    typeItemBox = new QComboBox;
    typeItemBox->addItem("Body Armor");
    typeItemBox->addItem("Gloves");
    typeItemBox->addItem("Attack Weapon");
    typeItemBox->addItem("Attack Shield");
    typeItemBox->addItem("Defense Shield");
    typeItemBox->addItem("Ring");

    //TEST GROUPBOX
    gbLayout = new QGridLayout;
    information = new QGroupBox("Additional Information");
    information->setMinimumSize(540,100);
    information->setLayout(gbLayout);

    //INFORMAZIONI AGGIUNTIVE
    QLabel *physDefL = new QLabel("Physical Defence");
    QLabel *magicDefL = new QLabel("Magic Defence");
    QLabel *balanceL = new QLabel("Balance");
    QLabel *fallDefL = new QLabel("Falling Defense");
    QLabel *stabDefL = new QLabel("Stabbing Defense");
    QLabel *strScalingL = new QLabel("Strenght Scaling");
    QLabel *physDmgL = new QLabel("Physical Damage");
    QLabel *magicDmgL = new QLabel("Magical Damage");
    QLabel *dexScalingL = new QLabel("Dexterity scaling");
    QLabel *physResL = new QLabel("Physical Resistance");
    QLabel *magicResL = new QLabel("Magical Resistance");
    QLabel *stsIncreasingL = new QLabel("Stats Increasing");

    physDef = new QSpinBox;
    physDef->setRange(0, 199);
    magicDef = new QSpinBox;
    magicDef->setRange(0, 199);
    balance = new QSpinBox;
    balance->setRange(0, 29);
    fallDef = new QSpinBox;
    fallDef->setRange(0, 99);
    stabDef = new QSpinBox;
    stabDef->setRange(0, 99);
    strScaling = new QSpinBox;
    strScaling->setRange(0, 3);
    physDmg = new QSpinBox;
    physDmg->setRange(0, 499);
    magicDmg = new QSpinBox;
    magicDmg->setRange(0, 499);
    dexScaling = new QSpinBox;
    dexScaling->setRange(0, 3);
    physRes = new QSpinBox;
    physRes->setRange(0, 99);
    magicRes = new QSpinBox;
    magicRes->setRange(0,99);
    stsIncreasing = new QSpinBox;
    stsIncreasing->setRange(0, 3);

    gbLayout->addWidget(physDefL,0,0);
    gbLayout->addWidget(physDef,0,1);
    gbLayout->addWidget(magicDefL,0,2);
    gbLayout->addWidget(magicDef,0,3);
    gbLayout->addWidget(balanceL,1,0);
    gbLayout->addWidget(balance,1,1);
    gbLayout->addWidget(fallDefL,1,2);
    gbLayout->addWidget(fallDef,1,3);
    gbLayout->addWidget(stabDefL,2,0);
    gbLayout->addWidget(stabDef,2,1);
    gbLayout->addWidget(strScalingL,2,2);
    gbLayout->addWidget(strScaling,2,3);
    gbLayout->addWidget(physDmgL,3,0);
    gbLayout->addWidget(physDmg,3,1);
    gbLayout->addWidget(magicDmgL,3,2);
    gbLayout->addWidget(magicDmg,3,3);
    gbLayout->addWidget(dexScalingL,4,0);
    gbLayout->addWidget(dexScaling,4,1);
    gbLayout->addWidget(physResL,4,2);
    gbLayout->addWidget(physRes,4,3);
    gbLayout->addWidget(magicResL,5,0);
    gbLayout->addWidget(magicRes,5,1);
    gbLayout->addWidget(stsIncreasingL,5,2);
    gbLayout->addWidget(stsIncreasing,5,3);

    //AGGIUNTA DEI WIDGET AL LAYOUT
    gridLayout = new QGridLayout;
    gridLayout->addWidget(nameLabel,0,0);
    gridLayout->addWidget(namePlaceholder,0,1);
    gridLayout->addWidget(typeLabel,0,2);
    gridLayout->addWidget(typeItemBox,0,3);
    gridLayout->addWidget(ilvlLabel,0,4);
    gridLayout->addWidget(levelItem,0,5);
    gridLayout->addWidget(descLabel,1,0);
    gridLayout->addWidget(flavourText,2,0,2,2);
    gridLayout->addWidget(buttok,4,2);
    gridLayout->addWidget(information,1,2,3,4);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);

    obscurer(0);

    //CONNECT
    connect(buttok,SIGNAL(clicked()),this,SLOT(accept()));
    connect(typeItemBox,SIGNAL(currentIndexChanged(int)),this,SLOT(obscurer(int)));

    setWindowTitle(t);

    //THEMING
    nameLabel->setProperty("type", "addInformation");
    descLabel->setProperty("type", "addInformation");
    ilvlLabel->setProperty("type", "addInformation");
    typeLabel->setProperty("type", "addInformation");
    physDefL->setProperty("type", "addInformation");
    magicDefL->setProperty("type", "addInformation");
    balanceL->setProperty("type", "addInformation");
    fallDefL->setProperty("type", "addInformation");
    stabDefL->setProperty("type", "addInformation");
    strScalingL->setProperty("type", "addInformation");
    physDmgL->setProperty("type", "addInformation");
    magicDmgL->setProperty("type", "addInformation");
    dexScalingL->setProperty("type", "addInformation");
    physResL->setProperty("type", "addInformation");
    magicResL->setProperty("type", "addInformation");
    stsIncreasingL->setProperty("type", "addInformation");

    physDef->setAlignment(Qt::AlignCenter);
    magicDef->setAlignment(Qt::AlignCenter);
    balance->setAlignment(Qt::AlignCenter);
    fallDef->setAlignment(Qt::AlignCenter);
    stabDef->setAlignment(Qt::AlignCenter);
    strScaling->setAlignment(Qt::AlignCenter);
    physDmg->setAlignment(Qt::AlignCenter);
    magicDmg->setAlignment(Qt::AlignCenter);
    dexScaling->setAlignment(Qt::AlignCenter);
    physRes->setAlignment(Qt::AlignCenter);
    magicRes->setAlignment(Qt::AlignCenter);
    stsIncreasing->setAlignment(Qt::AlignCenter);
}

void AddItem::obscurer(int i) {
    switch (i){
        case E_bodyArmor: {
            physDef->setEnabled(true);
            magicDef->setEnabled(true);
            balance->setEnabled(true);
            fallDef->setEnabled(true);
            stabDef->setEnabled(true);
            strScaling->setEnabled(false);
            physDmg->setEnabled(false);
            magicDmg->setEnabled(false);
            dexScaling->setEnabled(false);
            physRes->setEnabled(false);
            magicRes->setEnabled(false);
            stsIncreasing->setEnabled(false);
            break;
        };
        case E_gloves: {
            physDef->setEnabled(true);
            magicDef->setEnabled(true);
            balance->setEnabled(true);
            fallDef->setEnabled(false);
            stabDef->setEnabled(false);
            strScaling->setEnabled(true);
            physDmg->setEnabled(true);
            magicDmg->setEnabled(true);
            dexScaling->setEnabled(false);
            physRes->setEnabled(false);
            magicRes->setEnabled(false);
            stsIncreasing->setEnabled(false);
            break;
        };
        case E_attackweapon:{
            physDef->setEnabled(false);
            magicDef->setEnabled(false);
            balance->setEnabled(false);
            fallDef->setEnabled(false);
            stabDef->setEnabled(false);
            strScaling->setEnabled(true);
            physDmg->setEnabled(true);
            magicDmg->setEnabled(true);
            dexScaling->setEnabled(true);
            physRes->setEnabled(false);
            magicRes->setEnabled(false);
            stsIncreasing->setEnabled(false);
            break;
        };
        case E_attackshield:{
            physDef->setEnabled(false);
            magicDef->setEnabled(false);
            balance->setEnabled(false);
            fallDef->setEnabled(false);
            stabDef->setEnabled(false);
            strScaling->setEnabled(false);
            physDmg->setEnabled(true);
            magicDmg->setEnabled(true);
            dexScaling->setEnabled(true);
            physRes->setEnabled(true);
            magicRes->setEnabled(true);
            stsIncreasing->setEnabled(false);
            break;
        };
        case E_defenceshield:{
            physDef->setEnabled(false);
            magicDef->setEnabled(false);
            balance->setEnabled(false);
            fallDef->setEnabled(false);
            stabDef->setEnabled(false);
            strScaling->setEnabled(false);
            physDmg->setEnabled(false);
            magicDmg->setEnabled(false);
            dexScaling->setEnabled(false);
            physRes->setEnabled(true);
            magicRes->setEnabled(true);
            stsIncreasing->setEnabled(false);
            break;
        };
        case E_ring:{
            physDef->setEnabled(false);
            magicDef->setEnabled(false);
            balance->setEnabled(false);
            fallDef->setEnabled(false);
            stabDef->setEnabled(false);
            strScaling->setEnabled(false);
            physDmg->setEnabled(false);
            magicDmg->setEnabled(false);
            dexScaling->setEnabled(false);
            physRes->setEnabled(false);
            magicRes->setEnabled(false);
            stsIncreasing->setEnabled(true);
            break;
        };
        default:{
            physDef->setEnabled(false);
            magicDef->setEnabled(false);
            balance->setEnabled(false);
            fallDef->setEnabled(false);
            stabDef->setEnabled(false);
            strScaling->setEnabled(false);
            physDmg->setEnabled(false);
            magicDmg->setEnabled(false);
            dexScaling->setEnabled(false);
            physRes->setEnabled(false);
            magicRes->setEnabled(false);
            stsIncreasing->setEnabled(false);
            break;
        };
    }
}
