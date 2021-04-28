#ifndef CALENDRIER_H
#define CALENDRIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>
#include "QTextBrowser"
#include <QtPrintSupport\qprinter.h>

class Calendrier
{
private:
    QString id,date;
 public:
    Calendrier();
    Calendrier(QString);

    QString getid(){return id;}
    QString getdate(){return date;}

    void setid(QString id){this->id=id;}
    void setdate(QString date){this->date=date;}

    bool ajouter(QString);
    bool supprimer(QString);
   bool modifier (int,QString);
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficherid();
    void  exporterpdf(QString);
    // QSqlQueryModel * recherche_id (QString);
     QSqlQuery recherche_id2 (QString);
};

#endif // CALENDRIER_H
