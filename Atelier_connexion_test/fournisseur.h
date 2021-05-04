#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>
#include<QSqlQueryModel>


class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,int,QString);

   int getidfo();
   QString getsociete();
   int getnumero();
   QString getemail();

   void setidfo(int);
   void setsociete(QString);
   void setnumero(int);
   void setemail(QString);

   bool ajouterfo();
   QSqlQueryModel* afficherfo();
   bool supprimerfo(int);
   bool modifierfo(int,QString,int,QString);


private:
    int idfo,numero;
    QString societe,email;

};

#endif // FOURNISSEUR_H
