#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "calendrier.h"
#include <QSqlQuery>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refresh();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refresh(){
    ui->tabemploye->setModel(tmpemploye.afficher());
    ui->comboBox_22->setModel(tmpemploye.afficherid());
    ui->comboBox_2->setModel(tmpemploye.afficherid());
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_fonction->clear();
    ui->lineEdit_telephone->clear();
     ui->comboBox_4->setModel(tmpemploye.afficherid());
     ui->tabemploi->setModel(tmpcalendrier.afficher());
     ui->comboBox_23->setModel(tmpcalendrier.afficherid());
     ui->comboBox_3->setModel(tmpcalendrier.afficherid());
     ui->comboBox_5->setModel(tmpemploye.afficherid());
      ui->comboBox_7->setModel(tmpemploye.afficherid());
}

void MainWindow::on_ajouter_2_clicked()
{
        QString id = ui->lineEdit_id->text();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        QString fonction= ui->lineEdit_fonction->text();
        QString telephone= ui->lineEdit_telephone->text();

        Employe e(id,nom,prenom,fonction,telephone);
        bool test=e.ajouter();
        if(test)
        {
            refresh();//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                      QObject::tr("client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_comboBox_22_activated(const QString &arg1)
{
    ui->supprimer_6->setText(arg1);
}


void MainWindow::on_supprimer_employe_clicked()
{
     QString id =ui->supprimer_6->text();
     bool test=tmpemploye.supprimer(id);
     if(test)
 {
         refresh();//refresh
     QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                 QObject::tr(" employe supprimé.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
     ui->supprimer_6->clear();
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Supprimer un  employe"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    QString id=ui->comboBox_2->currentText();
    QSqlQuery query=tmpemploye.recherche_id2(id);
    QString nom;
    QString prenom;
    QString fonction;
    QString telephone;

    if (query.next()){
        nom= query.value(1).toString();
        ui->lineEdit_3->setText(nom);
        prenom= query.value(2).toString();
        ui->lineEdit_2->setText(prenom);
        fonction= query.value(3).toString();
        ui->lineEdit_fun->setText(fonction);
        telephone= query.value(4).toString();
        ui->num_5->setText(telephone);
    }
}

void MainWindow::on_modifier_p_2_clicked()
{
    QString id = ui->comboBox_2->currentText();
    QString nom= ui->lineEdit_3->text();
    QString prenom = ui->lineEdit_2->text();
    QString fonction =ui->lineEdit_fun->text();
    QString telephone = ui->num_5->text();
    Employe e(id,nom,prenom,fonction,telephone);

    e.modifier(id);
    refresh();

    QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                QObject::tr("employe modifié !!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
     ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::on_ajouter_3_clicked()
{

  //  QString id = ui->lineEdit_id->text();
     QString date= ui->dateEdit->text();
     QString idemlpoye= ui->comboBox_4->currentText();


    Calendrier e(date);
    bool test=e.ajouter(idemlpoye);
    if(test)
    {
        refresh();//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un emploi"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboBox_23_activated(const QString &arg1)
{
    ui->supprimer_7->setText(arg1);
}

void MainWindow::on_supprimer_employe_2_clicked()
{
    QString id =ui->supprimer_7->text();
    bool test=tmpcalendrier.supprimer(id);
    if(test)
{
        refresh();//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un emploi"),
                QObject::tr(" employe supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->supprimer_7->clear();
}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un  emploi"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    QString id=ui->comboBox_3->currentText();
    QSqlQuery query=tmpcalendrier.recherche_id2(id);
    QString date ;
     QString employe;

    if (query.next()){

        employe =query.value(2).toString();
        qDebug()<< employe;
        int index = ui->comboBox_5->findText(employe);
        qDebug()<< index;
        if (index != -1 ){
             ui->comboBox_5->setCurrentIndex(index);
        }
        date= query.value(1).toString();
        QDate Date = QDate::fromString(date,"dd/MM/yyyy");
        ui->dateEdit_2->setDate(Date);
    }
}

void MainWindow::on_modifier_p_3_clicked()
{
     int id=ui->comboBox_3->currentText().toInt();
    QString employe= ui->comboBox_5->currentText();
    QString date = ui->dateEdit_2->text();
    Calendrier c(date);

    c.modifier(id,employe);
    refresh();
    
    QMessageBox::information(nullptr, QObject::tr("modifier un emploi"),
                QObject::tr("emploi modifié !!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    QString idemploye=ui->comboBox_7->currentText();
    tmpcalendrier.exporterpdf(idemploye);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabemploye->setModel(tmpemploye.recherchetrie(champ,valeur,etat));
}

void MainWindow::on_recherche_tri_textChanged(const QString &arg1)
{
     valeur=arg1;
    ui->tabemploye->setModel(tmpemploye.recherchetrie(champ,valeur,etat));
}

void MainWindow::on_champ_activated(const QString &arg1)
{
    champ=arg1;
    ui->tabemploye->setModel(tmpemploye.recherchetrie(champ,valeur,etat));
}



void MainWindow::sendMail()

{

    Smtp* smtp = new Smtp("", "","smtp.gmail.com",465,3000);

    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("employer", ui->lineEdit_5->text() , ui->lineEdit_4->text(),ui->plainTextEdit->toPlainText());

}



void MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        int a = 0;
}


void MainWindow::on_pushButton_2_clicked()
{
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(sendMail()));
}
