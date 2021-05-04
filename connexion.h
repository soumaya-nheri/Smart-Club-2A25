#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>

class Connexion
{
    QSqlDatabase db;
 public :
    Connexion();
    bool createconnect();
    void closeconnection();
};


#endif // CONNEXION_H
