#include "calendrier.h"
#include <QFileDialog>


Calendrier::Calendrier()
{
    id="";
    date="";


}
Calendrier::Calendrier(QString date){
    this->date=date;
}


bool Calendrier::ajouter(QString idemlpoye){
    QSqlQuery query;
    query.prepare("insert into MAHDICalendrier (ID,JOUR_TRAVAIL,employe)" "values (1,:date,:idemploye)");
    query.bindValue(":date",date);
    query.bindValue(":idemploye",idemlpoye);
    return    query.exec();
}
QSqlQueryModel * Calendrier::afficher(){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from MAHDICalendrier");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("jour de travail"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("employe"));

     return model;
}

bool Calendrier::supprimer(QString idE)
{
    QSqlQuery query;
    query.prepare("Delete from MAHDICalendrier where ID = :id");
    query.bindValue(":id", idE);
    return    query.exec();
}

bool Calendrier ::modifier(int idp,QString employe)
{    QSqlQuery query;
        QString res= QString::number(idp);
        // QString res2= QString::number(employe);
      query.prepare("UPDATE MAHDICalendrier SET JOUR_TRAVAIL=:date ,EMPLOYE=:employe  where ID = "+res+"");
      query.bindValue(":date",date);
      query.bindValue(":employe",employe);
        return    query.exec();
}

 QSqlQueryModel * Calendrier::afficherid(){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select id  from MAHDICalendrier");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     return model;
 }


 QSqlQuery Calendrier::recherche_id2(QString id)
  {
      QSqlQuery query ;
         query.prepare("SELECT * FROM MAHDICalendrier WHERE ID = :id");
         query.bindValue(":id",id);
          query.exec();
          return query;
  }

 void Calendrier::exporterpdf(QString employe)
 {
     QTextBrowser *text = new QTextBrowser();
   // QString tt;
     QSqlQuery qry,qry2;
     std::list<QString> tt;
      qry2.prepare("SELECT * FROM MAHDIEMPLOYE WHERE ID = :employe");
      qry2.bindValue(":employe",employe);
      qry2.exec();
    while(qry2.next()){
        tt.push_back("employe: "+qry2.value(1).toString()+" "+qry2.value(2).toString() + "\n"+"fonction: "+qry2.value(3).toString()+"\n");
    }

    qry.prepare("SELECT * FROM MAHDICalendrier WHERE employe = :employe");
    qry.bindValue(":employe",employe);
       qry.exec();
     QString data;
     tt.push_back("emploi(calendrier):\n");
     while(qry.next())
     {
         tt.push_back(qry.value(1).toString()+"\n");
     }

     for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
     {
       data=data+*it;
     }
         text->setText(data);
     QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
     QPrinter printer(QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);
     text->print(&printer);
 }
