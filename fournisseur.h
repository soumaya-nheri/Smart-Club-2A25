#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString,QDate);
    int get_idF();
    QString get_nom();
    QDate get_date_ajout();

    //fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * combo_box();
    //fonctions avancées
    QSqlQueryModel * recherche_idF(int);
    QSqlQueryModel * recherche_nom(QString);

    QSqlQueryModel * trier_idF();
    QSqlQueryModel * trier_nom();

private:
    int idF;
    QString nom;
    QDate date_ajout;
};

#endif // FOURNISSEUR_H
