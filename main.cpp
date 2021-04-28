#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Connexion c;
     bool t= c.ouvrirConnexion();
    MainWindow w;
    w.show();

    return a.exec();
}
