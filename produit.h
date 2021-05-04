#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class produit
{
public:
    produit();
    produit(int,QString,int,int);
    int get_ref_produit();
    QString get_type();
    int get_prix_unitaire();

    int get_idF();


    //fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * combo_box();
    //fonctions avancées
    QSqlQueryModel * recherche_ref_produit(int);

    QSqlQueryModel * trier_ref_produit();
    QSqlQueryModel * trier_type_produit();

private:
    int ref_produit,prix_unitaire,idF;
    QString type;
};

#endif // PRODUIT_H
