#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include <QStyledItemDelegate>
#include <QDate>


#include "penalite.h"
#include <QTextEdit>
#include <QLineEdit>
#include"qrcode.h"
#include <QSslSocket>
#include <QTextStream>
#include "smtp.h"
#include"employe.h"
#include <QMainWindow>
#include "alerte.h"
#include "auditeur.h"
#include"arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onDownloadButtonClicked();
    int getSelectedPDFId();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_8_clicked();

    void on_bout_ajout_clicked();

    void on_s1_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_PDF_BUT_clicked();

    void on_DATA_ENT_clicked();

    void on_IMPORT_clicked();

    void on_EXPORT_clicked();

    void on_ERASE_clicked();

    void on_RECHERCHE_textChanged(const QString &arg1);

    void on_pbmenu6_clicked();

    void on_pbmenu1_clicked();

    void on_pbmenu2_clicked();

    void on_pbmenu3_clicked();

    void on_pbmenu4_clicked();

    void on_pbmenu5_clicked();

    void showPage(int n=0);
    void showPageEntrep(int n=0);




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

    void on_pushButton_19_clicked();

    void on_suivant_2_clicked();

    void on_back_2_clicked();

    //void on_suivant_3_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void  update_label();

    void on_employ_buttom_clicked();

    void on_ajouter_2_clicked();

    void on_modifier_3_clicked();
     bool controlSaisie();
          bool controlSaisiemelek();
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

      void on_pushButton_12_clicked();

      void on_nouraffichertableau_clicked();

     // void on_pushButton_2_clicked();

      //void on_supprimerButton_clicked();

      void on_nourajouterfor_clicked();

      void on_nourmodifierfor_clicked();

     // void on_LID_textChanged(const QString &arg1);

      //void on_pushButton_2_clicked();

      void on_nourchangerpage2a1_clicked();

     // void on_pushButton_2_clicked();

    //  void on_pushButton_3_clicked();

     // void on_sortAscButton_clicked();

   //   void on_sortDescButton_clicked();

      void on_nourtriacsendant_clicked();

      void on_nourtridecendant_clicked();
      void on_nourstatistiqueButton_clicked();
      void afficherGraphiqueCirculaire(QMap<QString, int> statistiques);
     // void onBoutonGenererPDFClicked();


     // void on_boutonGenererPDF_clicked();

      void on_nourpdf_clicked();
      //void on_evaluerButton_clicked();
      void on_nourabsenceformateurs_clicked();




      //void on_pushButtonDatesFormations_clicked();

      void on_nourpushButtonDatesFormations_clicked();

      //void on_llllllll_clicked();

      void on_nourchangerpage3a2_clicked();

      void on_lineEdit_textChanged(const QString &arg1);


      void on_nourclear1_clicked();

      void on_nourclear2_clicked();

      void on_nouraffichermoyenne_clicked();

      void on_etoile_clicked();

      void on_pushButtonAfficherPhoto_clicked();

      void on_pushButton_2000_clicked();

      //void on_pushButton_21_clicked();

      void on_nourbouttsupp_clicked();
      void on_pushButton_10_clicked();
      bool  controlSaisie_ayoub();
      void on_table_penaliter_activated(const QModelIndex &index);
      void on_ajouter_ayoub_clicked();

      void on_modifier_ayoub_clicked();

      void on_supprimer_ayoub_clicked();

      void on_back_ayoub_clicked();

      void on_suivant_1_ayoub_clicked();

      void on_PDF_ayoub_clicked();

      void on_STAT_clicked();

      void afficherGraphiqueCirculaire_2(QMap<QString, int> statistiques);

      void on_ASC_clicked();

      void on_DESC_clicked();
      void on_qr_clicked();

      void on_pdf_2_clicked();

      void on_ajouter_auditeur_clicked();

      void on_modifier_auditeur_clicked();

      void on_pdf_clicked();

      void on_suivant_7_clicked();

      void on_back_9_clicked();

      void on_suivant_9_clicked();

      void on_pb_supprimer_clicked();

      void on_stat_buttion_2_clicked();

      void on_ASC_2_clicked();

      void on_DESC_2_clicked();

      void on_stat_buttion_clicked();

      void  test();

private:
    Ui::MainWindow *ui;

    Entrp Etemp;
    alerte *Alerte;
    employe emp;
    penalite pen;
    QTextEdit *chat;
    QLineEdit *user_input;
    auditeur aud;
         Arduino A;
    int calculerNombreEtoiles(const QString& niveau);
};



class DateDelegate : public QStyledItemDelegate {
public:
    DateDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void initStyleOption(QStyleOptionViewItem* option, const QModelIndex& index) const override {
        QStyledItemDelegate::initStyleOption(option, index);

        // Check if the item corresponds to the "Due Date" column
        if (index.column() == 4) {
            QVariant value = index.data(Qt::DisplayRole);
            QDate dueDate = value.toDate();

            // Compare the due date with today's date
            if (dueDate < QDate::currentDate()) {
                // Set the text color to red
                option->palette.setColor(QPalette::Text, Qt::red);
            }
        }
    }
};


#endif // MAINWINDOW_H
