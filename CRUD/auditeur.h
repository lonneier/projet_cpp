#ifndef AUDITEUR_H
#define AUDITEUR_H

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
class auditeur
{

    private:
        int id_auditeur;
        QString nom_auditeur;
        QString prenom_auditeur;
        QString sexe;
        int telephone;
        QString adresse;
        QString email;
        QString departement;
        double salaire;
        QString secteur;
        QString mission;
        QString grade;
        bool archive;
        QString image;
    public:
        auditeur();
        auditeur(int id_auditeur, QString nom_auditeur, QString prenom_auditeur, QString sexe, int telephone, QString adresse, QString email, QString departement, double salaire, QString secteur, QString mission, QString grade, bool archive,QString image);

        // Setters for the attributes
        void set_id_auditeur(int id_auditeur);
        void set_nom_auditeur(QString nom_auditeur);
        void set_prenom_auditeur(QString prenom_auditeur);
        void set_sexe(QString sexe);
        void set_telephone(int telephone);
        void set_adresse(QString adresse);
        void set_email(QString email);
        void set_departement(QString departement);
        void set_salaire(double salaire);
        void set_secteur(QString secteur);
        void set_mission(QString mission);
        void set_grade(QString grade);
        void set_archive(bool archive);
        void set_image(QString image);
        // Getters for the attributes
        int get_id_auditeur() const;
        QString get_nom_auditeur() const;
        QString get_prenom_auditeur() const;
        QString get_sexe() const;
        int get_telephone() const;
        QString get_adresse() const;
        QString get_email() const;
        QString get_departement() const;
        double get_salaire() const;
        QString get_secteur() const;
        QString get_mission() const;
        QString get_grade() const;
        bool get_archive() const;
        QString get_image() const;
        QChartView *stat_capacite();
        // Other methods can be added here if needed.
        QSqlQueryModel*  findbyid(int NUMERO);
        QSqlQueryModel* GETALL();
        bool DELETEE(int);
        bool ADD();
        bool UPDATE();
        QSqlQueryModel* trie(QString croissance,QString critere);
        bool auditeurexiste(QString NUMERO);
};

#endif // AUDITEUR_H
