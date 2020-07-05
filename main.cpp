#include "view/mainwindow.h"
#include<QApplication>
#include<QStyleFactory>
#include<QTabWidget>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QFile stylePath(":/style/style.css");
    stylePath.open(QFile::ReadOnly);
    QString StyleSheet(stylePath.readAll());
    a.setStyleSheet(StyleSheet);
    a.setStyle(QStyleFactory::create("Fusion"));
    w.show();
    return a.exec();
}
