#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include<QMenuBar>
#include<QMainWindow>
#include<QVBoxLayout>
#include<QLabel>
#include"tab.h"
#include"additem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* =nullptr);

private:

    QMenuBar* menubar;
    QMenu* menu;
    QMenu* menuext;
    QAction* action1;
    QAction* action2;
    QVBoxLayout *mainlayout;
    Tab* tabWidget;

    void addmenu();
};

#endif // MAINWINDOW_H
