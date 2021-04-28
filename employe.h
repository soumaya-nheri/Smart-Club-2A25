#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employe
{
private:
    QString id,nom,prenom,fonction,telephone;
 public:
    Employe();
    Employe(QString,QString,QString,QString,QString);

    QString getid(){return id;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getpost(){return fonction;}
    QString gettelephone(){return telephone;}

    void setid(QString id){this->id=id;}
    void setnom(QString nom){this->nom=nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    void setfonction(QString fonction){this->fonction=fonction;}
    void settelephone(QString telephone){this->telephone=telephone;}

    bool ajouter();
    bool supprimer(QString);
    bool modifier (QString);
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficherid();
     QSqlQueryModel * recherche_id (QString);
     QSqlQuery recherche_id2 (QString);
     QSqlQueryModel * recherchetrie(QString,QString ,int);


};

#endif // EMPLOYE_H
