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


class AddItem : public QDialog
{
    Q_OBJECT
public:
    AddItem(QString t,QWidget* parent=nullptr);

    QLineEdit* namePlaceholder; //nome
    QTextEdit *flavourText;
    QLineEdit* itemLevelPlaceholder; //itemLevel

private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;

    QLabel *nameLabel;
    QLabel *typeLabel;
    QLabel *descLabel;

    QComboBox *typeItemBox;
    QPushButton *buttok;
};

#endif // ADDITEM_H
