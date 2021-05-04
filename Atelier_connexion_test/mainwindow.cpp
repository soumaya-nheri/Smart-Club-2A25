#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"machine.h"
#include"fournisseur.h"
#include<QIntValidator>
#include<QPixmap>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_idma->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_machine->setModel(M.afficherma());

    ui->setupUi(this);
    ui->le_idfo->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_fournisseur->setModel(F.afficherfo());



    //QPixmap pix("C:/Users/INFOMED/Desktop/Atelier_connexion_test/gym.jpg");
   // int w1 =ui->label_pic->width();
   // int h1 =ui->label_pic->height();

   // ui->label_pic->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));



   // int ret=A.connect_arduino(); // lancer la connexion à arduino
     //  switch(ret){
       //case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         //  break;
       //case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        //  break;
       //case(-1):qDebug() << "arduino is not available";
      // }
        //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).

}

MainWindow::~MainWindow()

{
    delete ui;
}


void MainWindow::on_pb_ajouterma_clicked()
{
    int idma=ui->le_idma->text().toInt();
    QString type=ui->le_type->text();
    QString marque=ui->le_marque->text();
    Machine M(idma, type, marque);



    bool test=M.ajouterma();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tab_machine->setModel(M.afficherma());
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();

}



void MainWindow::on_pb_supprimer_clicked()
{
    Machine M1;
    M1.setidma(ui->le_idma_supp->text().toInt());
    bool test=M1.supprimerma(M1.getidma());
    if (test)
        ui->tab_machine->setModel(M.afficherma());

}

void MainWindow::on_pb_modifier_clicked()
{
    int idma=ui->le_idma_modif->text().toInt();
    QString type=ui->le_type_modif->text();
    QString marque=ui->le_marque_modif->text();
    Machine M(idma, type, marque);
}

void MainWindow::on_pb_ajouterfo_clicked()
{
    int idfo=ui->le_idfo->text().toInt();
    QString societe=ui->le_societe->text();
    int numero=ui->le_numero->text().toInt();
    QString email=ui->le_email->text();
    Fournisseur F(idfo, societe,numero, email);
}

void MainWindow::on_pb_supprimerfo_clicked()
{
    Fournisseur F1;
    F1.setidfo(ui->le_idfo_supp->text().toInt());
    bool test=F1.supprimerfo(F1.getidfo());
    if (test)
        ui->tab_fournisseur->setModel(F.afficherfo());
}


void MainWindow::on_pb_modifierfo_clicked()
{
    int idfo=ui->le_idfo_modif->text().toInt();
    QString societe=ui->le_societe_modif->text();
    int numero=ui->le_numero_modif->text().toInt();
    QString email=ui->le_email_modif->text();
    Fournisseur F(idfo,societe,numero, email);
}

void MainWindow::on_pb_chercher_clicked()
{
    Machine M2;
    
    M2.setidma(ui->le_idma_chercher->text().toInt());    
    bool test=M2.chercher(M2.getidma());
    if (test)
        ui->tab_machine->setModel(M.afficherma());
    
}
void MainWindow::update_label()
{
    //data=A.read_from_arduino();



}

void MainWindow::on_pb_Fonctionnel_clicked()
{
     // A.write_to_arduino("0"); //envoyer 0 à arduino
}

void MainWindow::on_pb_Non_Fonctionnel_clicked()
{
       // A.write_to_arduino("1"); //envoyer 1 à arduino
}


void MainWindow::on_pushButton_1_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_2_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_3_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_pushButton_4_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
         ui->tab_machine->setModel(M.afficherma());
}

void MainWindow::on_pushButton_actualiser2_clicked()
{
    ui->tab_fournisseur->setModel(F.afficherfo());
}

void MainWindow::on_pushButton_2_clicked()
{
         ui->tab_machine->setModel(M.trier_id());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tab_machine->setModel(M.trier_marque());
}
