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
    delInventory = new QAction("Svuota inventario", this);

    //I/O
    loadFile = new QAction("Carica inventario", this);
    saveFile = new QAction("Salva inventario", this);
    file = new QMenu("File", this);
    file->addAction(loadFile);
    file->addAction(saveFile);
    file->addAction(delInventory);
    menuBar()->addMenu(file);
    connect(loadFile, SIGNAL(triggered()), tabWidget, SLOT(loadFileDialog()));
    connect(saveFile, SIGNAL(triggered()), tabWidget, SLOT(saveFileDialog()));
    connect(delInventory, SIGNAL(triggered()), tabWidget, SLOT(destroyInventory()));

    //AGGIUNTA - RIMOZIONE
    action1 = new QAction("Aggiungi oggetto",this);
    menuBar()->addAction(action1);
    connect(action1, SIGNAL(triggered()), tabWidget, SLOT(addItem()));
    action2 = new QAction("Elimina oggetto",this);
    menuBar()->addAction(action2);
    connect(action2,SIGNAL(triggered()),tabWidget,SLOT(removeItem()));
    action3 = new QAction("Modifica oggetto",this);
    menuBar()->addAction(action3);
    connect(action3,SIGNAL(triggered()),tabWidget,SLOT(modifyItem()));

}

