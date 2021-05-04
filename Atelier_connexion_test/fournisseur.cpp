#include "fournisseur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

Fournisseur::Fournisseur()
{
idfo=0;societe="";numero=0;email="";

}
Fournisseur::Fournisseur(int idfo ,QString societe,int numero,QString email)
{
    this->idfo=idfo;
    this->societe=societe;
    this->numero=numero;
    this->email=email;

}

int Fournisseur::getidfo(){return idfo;}
QString Fournisseur::getsociete(){return societe;}
int Fournisseur::getnumero(){return numero;}
QString Fournisseur::getemail(){return email;}

void Fournisseur::setidfo(int idfo){this->idfo=idfo;}
void Fournisseur::setsociete(QString societe){this->societe=societe;}
void Fournisseur::setnumero(int numero){this->numero=numero;}
void Fournisseur::setemail(QString email){this->email=email;}

bool Fournisseur::ajouterfo()
{
   QSqlQuery query;
   QString idfo_string=QString::number(idfo);
   QString numero_string=QString::number(numero);
         query.prepare("INSERT INTO fournisseurs (idfo, societe,numero, email) "
                       "VALUES (:idfo, :societe, :numero, :email)");
         query.bindValue(0,idfo_string);
         query.bindValue(":societe", societe);
         query.bindValue(numero_string, numero);
         query.bindValue(":email", email);

   return query.exec();
}
bool Fournisseur::supprimerfo(int idfo)
{
    QSqlQuery query;
         query.prepare(" Delete from fournisseurs where idfo=:idfo");
         query.bindValue(0, idfo);

        return query.exec();
}

QSqlQueryModel* Fournisseur::afficherfo()
{
    QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM fournisseurs");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idfo"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("societe"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));


    return  model;
}
bool Fournisseur::modifierfo(int idfo,QString societe,int numero,QString email)
{

   QSqlQuery query;
   QString idfo_string= QString::number(idfo);
   QString numero_string= QString::number(numero);


          query.prepare(" UPDATE fournisseurs SET  societe=:societe, numero=:numero, email=:email  WHERE idfo=:idfo ");
           query.bindValue(":idfo", idfo_string);


          query.bindValue(":idfo",idfo_string );
          query.bindValue(":numero", numero_string);
          query.bindValue(":societe",societe);
          query.bindValue(":email",email);
;
         return query.exec();
}
