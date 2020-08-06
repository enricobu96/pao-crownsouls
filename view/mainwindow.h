#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT
#include<QObject>
#include<QMenuBar>
#include<QMainWindow>
#include<QVBoxLayout>
#include<QLabel>

#include"tab.h"
#include"additem.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* =nullptr);
private:

    QMenuBar* menubar;
    QMenu* menu;
    QMenu* menuext;
    QAction* action1;
    QAction* action2;
    QAction* action3;
    QMenu* file;
    QAction* loadFile;
    QAction* saveFile;
    QAction* delInventory;
    QVBoxLayout *mainlayout;
    Tab* tabWidget;

    void addmenu();

};

#endif // MAINWINDOW_H
