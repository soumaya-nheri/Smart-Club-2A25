#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>

Employe::Employe()
{
    id="";
    nom="";
    prenom="";
    telephone="";
    fonction="";

}
Employe::Employe(QString id,QString nom ,QString prenom,QString fonction,QString telephone){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->telephone=telephone;
    this->fonction=fonction;
}


bool Employe::ajouter(){
    QSqlQuery query;
    //QString
    query.prepare("insert into MAHDIemploye (ID, NOM, PRENOM, fonction, TELEPHONE )" "values (:id, :nom, :prenom, :fonction, :telephone)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":fonction",fonction);
    query.bindValue(":telephone",telephone);
    return    query.exec();
}

QSqlQueryModel * Employe::afficher(){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from MAHDIemploye");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));

     return model;
}

bool Employe::supprimer(QString idE)
{
    QSqlQuery query;
    query.prepare("Delete from MAHDIemploye where ID = :id");
    query.bindValue(":id", idE);
    return    query.exec();
}
bool Employe ::modifier(QString idp)
{    QSqlQuery query;

      query.prepare("UPDATE MAHDIEmploye SET NOM=:nom ,PRENOM=:prenom ,fonction=:fonction ,TELEPHONE=:telephone  where ID = :idp");
      query.bindValue(":idp",idp);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":fonction",fonction);
      query.bindValue(":telephone",telephone);
        return    query.exec();
}
 QSqlQueryModel * Employe::afficherid(){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select id  from MAHDIEmploye");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     return model;
 }


 QSqlQueryModel *   Employe::recherche_id(QString id)
 {
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("SELECT * FROM MAHDIEMPLOYE WHERE ID = :id");
    // model->bindValue(":id", id);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));


     return model;
 }
QSqlQuery Employe::recherche_id2(QString id)
 {
     QSqlQuery query ;
        query.prepare("SELECT * FROM MAHDIEMPLOYE WHERE ID = :id");
        query.bindValue(":id",id);
         query.exec();
         return query;
}


QSqlQueryModel * Employe::recherchetrie(QString champ,QString valeur,int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)

   { query.prepare("SELECT * FROM MAHDIEMPLOYE WHERE ("+champ+" LIKE :valeur) order by id");}

    else   { query.prepare("SELECT * FROM MAHDIEMPLOYE WHERE ("+champ+" LIKE :valeur) order by id desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
    return model;
}
