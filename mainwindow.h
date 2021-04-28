#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include <QMessageBox>
#include "employe.h"
#include "calendrier.h"
#include <QGeoPositionInfo>
#include "stmp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ajouter_2_clicked();
    void refresh();
    void on_supprimer_employe_clicked();

    void sendMail();
    void mailSent(QString) ;

    void on_comboBox_22_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_modifier_p_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_ajouter_3_clicked();

    void on_comboBox_23_activated(const QString &arg1);

    void on_supprimer_employe_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_modifier_p_3_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);


    void on_recherche_tri_textChanged(const QString &arg1);

    void on_champ_activated(const QString &arg1);




    void on_pushButton_2_clicked();

private:

    int etat=0;
    QString valeur;
    QString champ="id";

    Ui::MainWindow *ui;
    Employe tmpemploye;
    Calendrier tmpcalendrier;
};

#endif // MAINWINDOW_H
