#include "machine.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

Machine::Machine()
{
idma=0;type="";marque="";

}
Machine::Machine(int idma ,QString type,QString marque)
{
    this->idma=idma;
    this->type=type;
    this->marque=marque;

}

int Machine::getidma(){return idma;}
QString Machine::gettype(){return type;}
QString Machine::getmarque(){return marque;}

void Machine::setidma(int idma){this->idma=idma;}
void Machine::settype(QString type){this->type=type;}
void Machine::setmarque(QString marque){this->marque=marque;}

bool Machine::ajouterma()
{
   QSqlQuery query;
   QString idma_string=QString::number(idma);
         query.prepare("INSERT INTO machines (idma,type,marque) "
                       "VALUES (:idma :type, :marque)");
         query.bindValue(":idma", idma_string);
         query.bindValue(":type", type);
         query.bindValue(":marque", marque);

   return query.exec();
}
bool Machine::supprimerma(int idma)
{
    QSqlQuery query;

          query.prepare("Delete from machines where idma=:idma");
          query.bindValue(0,idma);
   return query.exec();
}

QSqlQueryModel* Machine::afficherma()
{
    QSqlQueryModel* model=new QSqlQueryModel();



    model->setQuery("SELECT * FROM machines");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idma"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    return  model;
}
bool Machine::modifierma(int idma,QString type,QString marque)
{
    QSqlQuery query;
   QString idma_string=QString::number(idma);
          query.prepare("update machines SET idma=:idma, type:=type, marque:=marque");
                        query.bindValue(":idma",idma_string);
                        query.bindValue(":type", type);
                        query.bindValue(":marque" , marque);
   return query.exec();
}
bool Machine::chercher(int idma)
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
       QString idma_string=QString::number(idma);

    model->setQuery("select * FROM machines WHERE idma='"+idma_string+ "'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idma"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
query.exec();
    return  model;
}
QSqlQueryModel* Machine::trier_id()
{


    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT * FROM machines ORDER BY idma ");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idma"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));

    return  model;



}
QSqlQueryModel* Machine::trier_marque()
{


    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT * FROM machines ORDER BY marque ");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idma"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));


    return  model;



}
