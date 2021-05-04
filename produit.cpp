#include "produit.h"

#include<QDebug>

produit::produit()
{
    ref_produit=0;
    type="";
    prix_unitaire=0;
    idF=0;

}

produit::produit( int ref_produit,QString type,int prix_unitaire,int idF)
{
    this->ref_produit=ref_produit;
    this->type=type;
    this->prix_unitaire=prix_unitaire;
    this->idF=idF;

}

int produit::get_ref_produit(){return  ref_produit;}
QString produit::get_type(){return  type;}
int produit::get_prix_unitaire(){return  prix_unitaire;}
int produit::get_idF(){return  idF;}


bool produit::ajouter(){
    QSqlQuery query;
    QString res= QString::number(ref_produit);
    query.prepare("INSERT INTO produit (ref_produit,type,prix_unitaire,idF) "
                        "VALUES (:ref_produit,:type,:prix_unitaire,:idF)");
    query.bindValue(":ref_produit", res);
    query.bindValue(":type", type);

    query.bindValue(":prix_unitaire", prix_unitaire);


    query.bindValue(":idF", idF);

    return query.exec();
}

QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_unitaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idF"));


    return model;
}

bool produit::supprimer(int ref_produit)
{
    QSqlQuery query;
    QString res= QString::number(ref_produit);
    query.prepare("Delete from produit where ref_produit = :ref_produit");
    query.bindValue(":ref_produit", res);
    return query.exec();
}

bool produit::modifier()
{
    QSqlQuery query;
    QString ref_produit_modif= QString::number(this->ref_produit);
    QString type_modif=this->type;
    QString prix_unitaire_modif= QString::number(this->prix_unitaire);
    QString id_modif= QString::number(this->idF);

    query.prepare("UPDATE produit SET type=:type,prix_unitaire=:prix_unitaire,idF=:idF  WHERE ref_produit =:ref_produit");
    query.bindValue(":ref_produit",ref_produit_modif);
    query.bindValue(":type", type_modif);
    query.bindValue(":prix_unitaire", prix_unitaire_modif);
    query.bindValue(":idF", id_modif);


    return  query.exec();
}

QSqlQueryModel * produit::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select ref_produit from produit");
    return model;
}

QSqlQueryModel * produit::recherche_ref_produit(int ref_produit){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(ref_produit);
    model->setQuery("Select * From produit WHERE ref_produit = " + res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_unitaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idF"));

    return model;
}


QSqlQueryModel * produit::trier_ref_produit()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from produit\
                         Order by ref_produit ASC");
                    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_produit"));
                    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_unitaire"));
                    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idF"));

    return model;
}

QSqlQueryModel * produit::trier_type_produit()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from produit\
                         Order by type ASC");
                    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_produit"));
                    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_unitaire"));
                    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idF"));

    return model;
}




