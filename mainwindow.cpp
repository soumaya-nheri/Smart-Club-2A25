#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //affichage produit
     ui->tabproduit->setModel(tmpproduit.afficher());
     ui->comboPsupp->setModel(tmpproduit.combo_box());
     ui->comboPmodif->setModel(tmpproduit.combo_box());
     //affichage fournisseur
     ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
     ui->comboFsupp->setModel(tmpfournisseur.combo_box());
     ui->comboFmodif->setModel(tmpfournisseur.combo_box());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_objetname_tabBarClicked(int index)
{

}
//------------------crud produit----------------------//

//ajouter produit

void MainWindow::on_pushButton_2_clicked()
{
    int ref_produit = ui->lineEdit_ref->text().toInt();
    QString type = ui->combocombo->currentText();
    int prix_unitaire = ui->lineEdit_prix->text().toInt();
    int id = ui->lineEdit_f->text().toInt();

  produit p(ref_produit,type,prix_unitaire,id);

  bool test=p.ajouter();

  if(test)

{      //refresh_stat();
      ui->comboPsupp->setModel(tmpproduit.combo_box());
      ui->comboPmodif->setModel(tmpproduit.combo_box());

      ui->tabproduit->setModel(tmpproduit.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("produit Ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
//modifier produit



void MainWindow::on_modifie_produit_clicked()
{

    int ref_produit = ui->comboPmodif->currentText().toInt();
    QString type = ui->combocombo_2->currentText();
    int prix_unitaire = ui->lineEdit_prix_2->text().toInt();
    int id = ui->lineEdit_f_2->text().toInt();

    produit p(ref_produit,type,prix_unitaire,id);
      bool test=p.modifier();
      if(test)
    {      //refresh_stat();
          ui->tabproduit->setModel(tmpproduit.afficher());//refresh
          ui->comboPsupp->setModel(tmpproduit.combo_box());
          ui->comboPmodif->setModel(tmpproduit.combo_box());
    QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                      QObject::tr("produit modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
//supprimer produit
void MainWindow::on_supprimer_produit_clicked()
{
    int ref = ui->comboPsupp->currentText().toInt();
    bool test=tmpproduit.supprimer(ref);
    if(test)
    { //refresh_stat();
        ui->tabproduit->setModel(tmpproduit.afficher());//refresh
        ui->comboPsupp->setModel(tmpproduit.combo_box());
        ui->comboPmodif->setModel(tmpproduit.combo_box());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
//------------------crud fournisseur----------------------//
//ajouter fournisseur
void MainWindow::on_ajouter_fournisseur_clicked()
{
    int idF = ui->lineEdit_idf->text().toInt();
    QString nom= ui->lineEdit_nomf->text();
    QDate date_ajout= ui->ajouterdatefournisseur->date();
  fournisseur f(idF,nom, date_ajout);
  bool test=f.ajouter();
  if(test)
{

      ui->comboFsupp->setModel(tmpfournisseur.combo_box());
      ui->comboFmodif->setModel(tmpfournisseur.combo_box());
      ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Fournisseur Ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
//modifier fournisseur
void MainWindow::on_modifie_fournisseur_clicked()
{

    int idF = ui->comboFmodif->currentText().toInt();
    QString nom= ui->lineEdit_nomf_2->text();
    QDate date_ajout= ui->modifierdatefournisseur->date();
    fournisseur f(idF,nom, date_ajout);
  bool test=f.modifier();
  if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
      ui->comboFsupp->setModel(tmpfournisseur.combo_box());
      ui->comboFmodif->setModel(tmpfournisseur.combo_box());

QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                  QObject::tr("fournisseur modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
//supprimer fournisseur
void MainWindow::on_supprimer_fournisseur_clicked()
{
    int idF = ui->comboFsupp->currentText().toInt();
    bool test=tmpfournisseur.supprimer(idF);
    if(test)
    {ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
        ui->comboFsupp->setModel(tmpfournisseur.combo_box());
        ui->comboFmodif->setModel(tmpfournisseur.combo_box());

        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_imprimer_clicked()
{

}



void MainWindow::on_recherche_fournisseur_textChanged(const QString &arg1){
ui->tabfournisseur->setModel(tmpfournisseur.recherche_nom(arg1));

}

void MainWindow::on_recherche_produit_textChanged(const QString &arg1)
{
    ui->tabproduit->setModel(tmpproduit.recherche_ref_produit(arg1.toInt()));
}

void MainWindow::on_pushButton_clicked()
{ if(ui->type_radio->isChecked())
    { ui->tabproduit->setModel(tmpproduit.trier_type_produit());
    }
 else if (ui->reference_radio->isChecked()){
        ui->tabproduit->setModel(tmpproduit.trier_ref_produit());
    }    else {
        ui->tabproduit->setModel(tmpproduit.afficher());
    }
}

void MainWindow::on_triefournisseur_clicked()
{
    if(ui->id_radio->isChecked())
       { ui->tabfournisseur->setModel(tmpfournisseur.trier_idF());
       }
    else if (ui->nom_radio->isChecked()){
           ui->tabfournisseur->setModel(tmpfournisseur.trier_nom());
       }    else {
           ui->tabfournisseur->setModel(tmpfournisseur.afficher());
       }
}

