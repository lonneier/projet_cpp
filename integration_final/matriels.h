#ifndef MATRIELS_H
#define MATRIELS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Matriels
{
private:
    int id;
    QString nom;
    QString type;
    QString etat;
    QDate garantie;
    int disponibilite;
public:
    Matriels();
    Matriels(int,QString,QString,QString,QDate,int);
    int getid();
    QString getnom();
    QString gettype();
    QString getetat();
    QDate getgarantie();
    int getdisponibilite();

    void setid(int);
    void setnom(QString);
    void settype(QString);
    void setetat(QString);
    void setgarantie(QDate);
    void setdisponibilite(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQuery rechercher(int);
    QSqlQueryModel * tri();
    void calculateEtatStatistics();
    void generatePDF();
    bool rechercher_arduino(int);
    bool modifierarduino(int disponibilite);




};

#endif // MATRIELS_H
