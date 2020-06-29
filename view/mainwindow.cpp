#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {


    //MENU
    addmenu();

    //TABS
    tabWidget = new Tab(this);
    setCentralWidget(tabWidget);

    //APPLICAZIONE
    setMinimumSize(1024,720);
}

void MainWindow::addmenu()
{
    action1 = new QAction("Aggiungi oggetto",this);
    menuBar()->addAction(action1);
    connect(action1, SIGNAL(triggered()), this, SLOT(addItem()));
    menuBar()->addAction("Placeholder");
}

void MainWindow::addItem() {
    AddItem aItem("Add Item");
    aItem.exec();
}
