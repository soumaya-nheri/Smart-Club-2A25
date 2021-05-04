#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include"machine.h"
#include"fournisseur.h"
#include "arduino.h"





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_label();

    void on_pb_ajouterma_clicked();

    void on_pb_supprimer_clicked();



    void on_pb_modifier_clicked();

    void on_pb_ajouterfo_clicked();

    void on_pb_supprimerfo_clicked();

    void on_pb_modifierfo_clicked();

    void on_pb_chercher_clicked();

    void on_pb_Fonctionnel_clicked();


    void on_pb_Non_Fonctionnel_clicked();

    void on_pushButton_1_2_clicked();
    void on_pushButton_2_3_clicked();
    void on_pushButton_3_4_clicked();
    void on_pushButton_4_1_clicked();


    void on_pushButton_clicked();

    void on_pushButton_actualiser2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;


    Machine M;
    Fournisseur F;

};
#endif // MAINWINDOW_H

