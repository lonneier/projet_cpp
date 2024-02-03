#ifndef CLIENT_H
#define CLIENT_H
#include <QDialog>

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts>
#include<QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
class Entrp
{
    int id,effectif;
    double capital, chaffaire;
    QString DS,DC,PAYS,SECT,SSECT;
public:
    Entrp();
    Entrp(int newID, QString newDS, QString newDC, QString newPAYS, QString newSECT, QString newSSECT, int newEffectif, double newCapital, double newChaffaire);
    Entrp(int id, QString DS, QString DC,double Capital);

    //////      //////      //////      //////

    QString getDC(){return DC;}
    QString getDS(){return DS;}
    QString getPays(){return PAYS;}
    QString getSect(){return SECT;}
    QString getSsect(){return SSECT;}
    int getID(){return id;}
    int getEffectif(){return effectif;}
    double getCapital()const{return capital;}
    double getChaffaire(){return chaffaire;}

    //////      //////      //////      //////


    void setID(int n){this->id=n;}
    void setDC(const QString& newDC) {
            DC = newDC;
        }
    void setDS(const QString& newDS) {       DS = newDS;  }

    void setPays(const QString& newPays) {
        PAYS = newPays;
    }

    void setSect(const QString& newSect) {
        SECT = newSect;
    }

    void setSsect(const QString& newSsect) {
        SSECT = newSsect;
    }

    void setEffectif(int newEffectif) {
        effectif = newEffectif;
    }

    void setCapital(double newCapital) {
        capital = newCapital;
    }

    void setChaffaire(double newChaffaire) {
        chaffaire = newChaffaire;
    }
    //////      //////      //////      //////

    bool ajouter();
    bool CheckId(int id);
    QSqlQueryModel* afficher(const QString& sortingOption = "NONE", const QString& filterText = "");
    bool supprimer(int);
    bool updateCompanyInDatabase(int id, const QString& newDS, const QString& newDC, const QString& newDirigeant, const QString& newAdresse, const QString& newCP, const QString& newPays, const QString& newGouvernorat, const QString& newVille, const QString& newTelephone, const QString& newFax, const QString& newEmail, const QString& newSecteur, const QString& newSousSect, const QString& newDivision, double newCapital, int newEffectif, double newChaffaire, const QString& newSiteWeb);
    void generateExcelFile();
    QList<Entrp> retrieveEntrpFromDatabase();
    QList<Entrp> retrieveClientsFromDatabase();
    QChart* LoadStats();
    QSqlQueryModel* afficher_AN();
    QSqlQueryModel* afficher_DATA();
    QByteArray fetchPDFContentFromDatabase(int pdfId);
    bool deletePDFFromDatabase(int pdfId);
    bool exportPDFToDatabase(int pdfId, const QByteArray& pdfContent);
};


#endif // CLIENT_H
