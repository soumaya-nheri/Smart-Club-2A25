#include "connexion.h"
#include <QApplication>
#include <QSqlError>

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    bool test=false;
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("projet-c++");
  db.setUserName("houssem");//system
  db.setPassword("toumi");

  if (db.open())
      test=true;

   return test ;
}


void Connexion::closeconnection() {db.close();}
