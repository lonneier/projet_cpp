#ifndef PENALITE_H
#define PENALITE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QPrinter>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

class penalite
{
    private:
        int numero_penalite;
        QDate date_penalite;
        double montant;
        QString nature;
        int id_auditeur;
        QString notes;
    public:
        penalite();
        penalite(int numero_penalite, QDate date_penalite, double montant, QString nature, int id_auditeur, QString notes);

        //setters
        void set_numero_penalite(int numero_penalite);
        void set_date_penalite(QDate date_penalite);
        void set_montant(double montant);
        void set_nature(QString nature);
        void set_id_auditeur(int id_auditeur);
        void set_notes(QString notes);

        //getters
        int get_numero_penalite() const;
        QDate get_date_penalite() const;
        double get_montant() const;
        QString get_nature() const;
        int get_id_auditeur() const;
        QString get_notes() const;


        QSqlQueryModel* GETALL();
        bool DELETEE(int);
        bool ADD();
        bool penaliteExists(int numero_penalite);
        bool UPDATE();
        penalite getPenaliteByNum(int numero_penalite);
        void writeToPDF(int numero_penalite);
        QChartView *statistique();
        QSqlQueryModel* trie(QString croissance, QString critere);
        void generateQRCode(QLabel *qr_code, QLineEdit *numero_penalite_2);
        //void chatbot(QTextEdit *chat, QLineEdit *user_input);
    };

    #endif // PENALITE_H
