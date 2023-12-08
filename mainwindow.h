#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSslSocket>
#include <QTextStream>
#include "smtp.h"
#include"employe.h"
#include <QMainWindow>
#include "alerte.h"
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
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_clicked();

    void on_supprimer_2_clicked();

    void on_supprimer_3_clicked();

    void on_PDF_clicked();

    void on_suivant_clicked();

    void on_back_clicked();

    void on_supprimer_4_clicked();

    void on_login_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_19_clicked();

    void on_suivant_2_clicked();

    void on_back_2_clicked();

    //void on_suivant_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();


    void on_employ_buttom_clicked();

    void on_ajouter_2_clicked();

    void on_modifier_3_clicked();
     bool controlSaisie();
      void on_table_employe_activated(const QModelIndex &index);

      void on_suprimer_clicked();

      void on_suivant_3_clicked();

      void on_back_3_clicked();

      void on_suivant_4_clicked();

      void on_back_4_clicked();

      void on_exportpdfb_clicked();

      void on_stat_clicked();

      void on_suivant_5_clicked();

      void on_bac_4_clicked();

      void on_calendarWidget_selectionChanged();

      void on_suivant_6_clicked();

      void on_back_5_clicked();

      void on_pushButton_17_clicked();

      void on_pushButton_18_clicked();

private:
    Ui::MainWindow *ui;
    alerte *Alerte;
    employe emp;

};
#endif // MAINWINDOW_H
