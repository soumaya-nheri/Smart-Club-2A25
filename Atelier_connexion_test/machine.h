#ifndef MACHINE_H
#define MACHINE_H
#include<QString>
#include<QSqlQueryModel>

class Machine
{
public:
    Machine();
    Machine(int,QString,QString);

   int getidma();
   QString gettype();
   QString getmarque();

   void setidma(int);
   void settype(QString);
   void setmarque(QString);

   bool ajouterma();
   QSqlQueryModel* afficherma();
   bool supprimerma(int);
   bool modifierma(int,QString,QString);
   bool chercher(int);
   QSqlQueryModel* trier_marque();
    QSqlQueryModel* trier_id();


private:
    int idma;
    QString type,marque;

};

#endif // MACHINE_H
