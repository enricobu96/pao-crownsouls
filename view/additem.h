#ifndef ADDITEM_H
#define ADDITEM_H

#include<QDialog>
#include<QVBoxLayout>
#include<QPushButton>
#include<QLabel>
#include<QComboBox>
#include<QLineEdit>
#include<QTextEdit>


class AddItem : public QDialog
{
public:
    AddItem(QString t,QWidget* parent=nullptr);
private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;

    QLabel *nameLabel;
    QLabel *typeLabel;
    QLabel *descLabel;
    QTextEdit *flavourText;
    QComboBox *typeItemBox;
    QLineEdit *namePlaceholder;

};

#endif // ADDITEM_H
