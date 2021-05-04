#include "fournisseur.h"

#include<QDebug>
#include<QDate>
#include <QApplication>

fournisseur::fournisseur()
{

    idF=0;
    nom="";
    date_ajout=date_ajout.currentDate();
}

fournisseur::fournisseur( int idF ,QString nom,QDate date_ajout)
{
  this->idF=idF;
  this->nom=nom;
  this->date_ajout=date_ajout;

}

QString fournisseur::get_nom(){return  nom;}
QDate fournisseur::get_date_ajout(){return date_ajout;}
int fournisseur::get_idF(){return  idF;}


bool fournisseur::ajouter(){
    QSqlQuery query;
    QString res= QString::number(idF);
    query.prepare("INSERT INTO fournisseur (idF, nom, date_ajout) "
                        "VALUES (:idF, :nom, :date_ajout)");
    query.bindValue(":idF", res);
    query.bindValue(":nom", nom);
    query.bindValue(":date_ajout", date_ajout);

    return query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));


    return model;
}

bool fournisseur::supprimer(int idF)
{
    QSqlQuery query;
    QString res= QString::number(idF);
    query.prepare("Delete from fournisseur where idF = :idF");
    query.bindValue(":idF", res);
    return query.exec();
}

bool fournisseur::modifier()
{
    QSqlQuery query;
    QString idF_modif= QString::number(this->idF);
    QString nom_modif= this->nom;
    QDate date_ajout_modif= this->date_ajout;
    query.prepare("UPDATE fournisseur SET nom =:nom , date_ajout=:date_ajout  WHERE idF =:idF");
    query.bindValue(":idF",idF_modif);
    query.bindValue(":nom",nom_modif);
    query.bindValue(":date_ajout",date_ajout_modif);
    return  query.exec();
}

QSqlQueryModel * fournisseur::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select idF from fournisseur");
    return model;
}

QSqlQueryModel * fournisseur::recherche_idF(int idF){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(idF);
    model->setQuery("Select * From fournisseur WHERE idF = " + res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));

    return model;
}

QSqlQueryModel * fournisseur::recherche_nom(QString nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From fournisseur WHERE nom ='" +nom+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));

    return model;
}

QSqlQueryModel * fournisseur::trier_idF()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from fournisseur\
                         Order by idF ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));

    return model;
}

QSqlQueryModel * fournisseur::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from fournisseur\
                         Order by nom ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));

    return model;
}



