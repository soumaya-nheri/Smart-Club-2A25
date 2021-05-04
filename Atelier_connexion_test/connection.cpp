#include "connection.h"
#include"QSqlDatabase"
connexion::connexion()
{

}
bool connexion::createconnection()
{ bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase(("QODBC"));
db.setDatabaseName("Source_Projet2A");
db.setUserName("aziz");
db.setPassword("esprit18");

if(db.open())
    test=true;
return test;

}
