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
private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;

    QLabel *nameLabel;
    QLabel *typeLabel;
    QLabel *descLabel;
    QTextEdit *flavourText;
    QComboBox *typeItemBox;
    QLineEdit *namePlaceholder;
    QPushButton *buttok;
public slots:
    void addOggetto();
};

#endif // ADDITEM_H
