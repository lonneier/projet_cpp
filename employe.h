#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTextDocument>
#include <QPrinter>
#include <QRegularExpression>

class employe
{
private:
    int id_employe;
    QString nom;
    QString prenom;
    QString sexe;
    int telephone;
    QString adresse;
    QString departement;
    QString grade;
    double salaire;


public:
    // Constructeurs
    employe();
    employe(int id_employe, QString nom, QString prenom, QString sexe, int telephone,
            QString adresse, QString departement, QString grade, double salaire);

    // Setters
    void setIdEmploye(int id_employe);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setSexe(QString sexe);
    void setTelephone(int telephone);
    void setAdresse(QString adresse);
    void setDepartement(QString departement);
    void setGrade(QString grade);
    void setSalaire(double salaire);

    // Getters
    int getIdEmploye() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getSexe() const;
    int getTelephone() const;
    QString getAdresse() const;
    QString getDepartement() const;
    QString getGrade() const;
    double getSalaire() const;


        QSqlQueryModel* GETALL();
        QSqlTableModel* getSortedModel();
        bool DELETEE(int);
        bool ADD();
        bool employeExists(int id_employe);
        bool UPDATE();
        void writeToPDF(int id);
        employe getEmployeById(int id_employe);
        void stat(double *malePercentage,double *femalePercentage);
        bool isValidEmail(QString email);
    };

#endif // EMPLOYE_H
