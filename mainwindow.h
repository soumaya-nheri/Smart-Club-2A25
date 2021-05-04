#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"
#include "produit.h"


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
    void on_objetname_tabBarClicked(int index);

    void on_pushButton_2_clicked();

    void on_modifie_produit_clicked();

    void on_supprimer_produit_clicked();

    void on_ajouter_fournisseur_clicked();

    void on_modifie_fournisseur_clicked();

    void on_supprimer_fournisseur_clicked();

    void on_imprimer_clicked();

    void on_recherche_fournisseur_textChanged(const QString &arg1);

    void on_recherche_produit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_triefournisseur_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_widget_stat_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    fournisseur tmpfournisseur;
    produit tmpproduit;

};
#endif // MAINWINDOW_H
