#ifndef ADDITEM_H
#define ADDITEM_H

#include<QDialog>
#include<QVBoxLayout>
#include<QPushButton>
#include<QLabel>
#include<QComboBox>
#include<QLineEdit>
#include<QTextEdit>
#include<QObject>
#include<QSpinBox>
#include<QGroupBox>

class AddItem : public QDialog
{
    Q_OBJECT
public:
    AddItem(QString t,QWidget* parent=nullptr);

    QLineEdit* namePlaceholder;
    QTextEdit *flavourText;
    QLineEdit* itemLevelPlaceholder;
    QComboBox *typeItemBox;
    QSpinBox *levelItem;
    QSpinBox *physDef;
    QSpinBox *magicDef;
    QSpinBox *balance;
    QSpinBox *fallDef;
    QSpinBox *stabDef;
    QSpinBox *strScaling;
    QSpinBox *physDmg;
    QSpinBox *magicDmg;
    QSpinBox *dexScaling;
    QSpinBox *physRes;
    QSpinBox *magicRes;
    QSpinBox *stsIncreasing;

    enum ObjType{E_bodyArmor,E_gloves,E_attackweapon,E_attackshield,E_defenceshield,E_ring};

public slots:
    void obscurer(int i);

private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    QGridLayout *gbLayout;
    QLabel *nameLabel;
    QLabel *typeLabel;
    QLabel *descLabel;
    QLabel *ilvlLabel;
    QPushButton *buttok;
    QGroupBox* information;
};

#endif // ADDITEM_H
