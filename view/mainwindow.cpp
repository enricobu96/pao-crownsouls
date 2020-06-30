#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {

    //TABS
    tabWidget = new Tab(this);
    setCentralWidget(tabWidget);

    //MENU
    addmenu();

    //APPLICAZIONE
    setMinimumSize(1024,720);
}

void MainWindow::addmenu()
{
    action1 = new QAction("Aggiungi oggetto",this);
    menuBar()->addAction(action1);
    connect(action1, SIGNAL(triggered()), tabWidget, SLOT(addItem()));
    action2 = new QAction("Elimina oggetto",this);
    menuBar()->addAction(action2);
    connect(action2,SIGNAL(triggered()),tabWidget,SLOT(removeItem()));

}


