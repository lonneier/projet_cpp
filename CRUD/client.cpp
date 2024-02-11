#include "client.h"
#include "xlsxdocument.h"
#include "xlsxworksheet.h"
#include "xlsxcellrange.h"
#include <QDialog>
#include<QDebug>
#include <QtCharts>
#include<QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <iostream>
#include <QFile>
#include <QtWidgets>
#include<QMessageBox>
using namespace std;

Entrp::Entrp(): id(0), effectif(0), capital(0.0), chaffaire(0.0) {};


Entrp::Entrp(int id, QString DS, QString DC, QString PAYS, QString SECT, QString SSECT, int effectif, double capital, double chaffaire)
    : id(id), DS(DS), DC(DC), PAYS(PAYS), SECT(SECT), SSECT(SSECT), effectif(effectif), capital(capital), chaffaire(chaffaire) {}

Entrp::Entrp(int id, QString DS, QString DC,double Capital){
    this->id=id;
    this->DS=DS;
    this->DC=DC;
    this->capital=Capital;
}

bool Entrp::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO BDTUN (ID, DS, DC, PAYS, SECT, SSECT, EFFECTIF, CAPITAL, CHAFFAIRE) "
                  "VALUES (:id, :ds, :dc, :pays, :sect, :ssect, :effectif, :capital, :chaffaire)");

    query.bindValue(":id", id);
    query.bindValue(":ds", DS);
    query.bindValue(":dc", DC);
    query.bindValue(":pays", PAYS);
    query.bindValue(":sect", SECT);
    query.bindValue(":ssect", SSECT);
    query.bindValue(":effectif", effectif);
    query.bindValue(":capital", capital);
    query.bindValue(":chaffaire", chaffaire);

    if (!query.exec()) {
        qDebug() << "Error inserting record into BDTUN:" ;
        return false;
    }

    return true;
}


bool Entrp::CheckId(int id)
{
    QList<Entrp> entrpList = retrieveClientsFromDatabase();

    foreach (Entrp entry, entrpList) {
        int temp = entry.getID();
        if (temp==id){
            return true;
        }
    }
    return false;


}


QSqlQueryModel* Entrp::afficher(const QString& sortingOption, const QString& filterText) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString query = "SELECT * FROM BDTUN";

    if (!filterText.isEmpty()) {
        query += " WHERE DS LIKE '%" + filterText + "%'";
    }

    if (sortingOption != "NONE") {
        query += " ORDER BY " + sortingOption;
    }

    model->setQuery(query);
    /*
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SECTEUR"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SOUSSECT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("CAPITAL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("CHAFFAIRE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("EFFECTIF"));
*/
    return model;
}

bool Entrp::supprimer(int id){
    QSqlQuery query;
    //QString res = QString::number(id);
    query.prepare("Delete from BDTUN where ID= :id");

    query.bindValue(":id",id);
    return query.exec();

}

bool Entrp::updateCompanyInDatabase(int id, const QString& newDS, const QString& newDC, const QString& newDirigeant, const QString& newAdresse, const QString& newCP, const QString& newPays, const QString& newGouvernorat, const QString& newVille, const QString& newTelephone, const QString& newFax, const QString& newEmail, const QString& newSecteur, const QString& newSousSect, const QString& newDivision, double newCapital, int newEffectif, double newChaffaire, const QString& newSiteWeb)
{
    QSqlQuery query;

    query.prepare("UPDATE BDTUN SET DS = :ds, DC = :dc, DIRIGEANT = :dirigeant, ADRESSE = :adresse, CP = :cp, PAYS = :pays, GOUVERNORAT = :gouvernorat, VILLE = :ville, TELEPHONE = :telephone, FAX = :fax, EMAIL = :email, SECTEUR = :secteur, SOUSSECT = :soussect, DIVISION = :division, CAPITAL = :capital, EFFECTIF = :effectif, CHAFFAIRE = :chaffaire, SITEWEB = :siteweb WHERE ID = :id");

    query.bindValue(":id", id);
    query.bindValue(":ds", newDS);
    query.bindValue(":dc", newDC);
    query.bindValue(":dirigeant", newDirigeant);
    query.bindValue(":adresse", newAdresse);
    query.bindValue(":cp", newCP);
    query.bindValue(":pays", newPays);
    query.bindValue(":gouvernorat", newGouvernorat);
    query.bindValue(":ville", newVille);
    query.bindValue(":telephone", newTelephone);
    query.bindValue(":fax", newFax);
    query.bindValue(":email", newEmail);
    query.bindValue(":secteur", newSecteur);
    query.bindValue(":soussect", newSousSect);
    query.bindValue(":division", newDivision);
    query.bindValue(":capital", newCapital);
    query.bindValue(":effectif", newEffectif);
    query.bindValue(":chaffaire", newChaffaire);
    query.bindValue(":siteweb", newSiteWeb);

    return query.exec();
}



void Entrp::generateExcelFile()
{
    QXlsx::Document xlsx;
    QXlsx::Worksheet* sheet = xlsx.currentWorksheet();

    sheet->write("A1", "ID");
    sheet->write("B1", "DS");
    sheet->write("C1", "DC");
    sheet->write("D1", "CAPITAL");
QList<Entrp> clients = retrieveClientsFromDatabase();

    int row = 2;

    foreach (Entrp client, clients) {
        sheet->write("A" + QString::number(row), client.getID());
        sheet->write("B" + QString::number(row), client.getDS());
        sheet->write("C" + QString::number(row), client.getDC());
        sheet->write("D" + QString::number(row), client.getCapital());

        row++;
    }

    xlsx.saveAs("XXTRP.xlsx");
    QMessageBox::information(nullptr, "Creation Successful", "EXCEL successfully.");

}





QList<Entrp> Entrp::retrieveEntrpFromDatabase() {
    QList<Entrp> entrpList; // Create a list to store Entrp objects

    QSqlQuery query("SELECT ID, DS, DC, PAYS, SECT, SSECT, EFFECTIF, CAPITAL, CHAFFAIRE FROM BDTUN");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString DS = query.value(1).toString();
        QString DC = query.value(2).toString();
        QString PAYS = query.value(3).toString();
        QString SECT = query.value(4).toString();
        QString SSECT = query.value(5).toString();
        int effectif = query.value(6).toInt();
        double capital = query.value(7).toDouble();
        double chaffaire = query.value(8).toDouble();

        // Create an Entrp object and add it to the list
        entrpList.append(Entrp(id, DS, DC, PAYS, SECT, SSECT, effectif, capital, chaffaire));
    }

    return entrpList;
}
QList<Entrp> Entrp::retrieveClientsFromDatabase() {
    QList<Entrp> clients;

    QSqlQuery query("SELECT ID, DS, DC, CAPITAL FROM BDTUN");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString DS = query.value(1).toString();
        QString DC = query.value(2).toString();
        double Cap = query.value(3).toDouble();

        clients.append(Entrp(id, DS, DC,Cap));
    }

    return clients;
}

QChart* Entrp::LoadStats() {
    QList<Entrp> entrpList = retrieveClientsFromDatabase();

    int numMoreThan50M = 0;
    int numBetween1MAnd50M = 0;
    int numBetween100KAnd1M = 0;
    int numBetween10KAnd100K = 0;
    int numLessThan10K = 0;

    // Calculate the counts for different net worth categories
    foreach (Entrp entry, entrpList) {
        double capital = entry.getCapital();
        cout << "capital is: " << capital << endl;

        if (!std::isnan(capital) && !std::isinf(capital)) {
            if (capital > 50000000) {
                numMoreThan50M++;
            } else if (capital > 1000000) {
                numBetween1MAnd50M++;
            } else if (capital > 100000 && capital <= 1000000) {
                numBetween100KAnd1M++;
            } else if (capital > 10000 && capital <= 100000) {
                numBetween10KAnd100K++;
            } else if (capital <= 10000) {
                numLessThan10K++;
            }
        }
    }

    // Calculate percentages
    int totalCompanies = numMoreThan50M + numBetween1MAnd50M + numBetween100KAnd1M + numBetween10KAnd100K + numLessThan10K;

    // Add checks to avoid division by zero
    float percentageMoreThan50M = (totalCompanies > 0) ? (static_cast<double>(numMoreThan50M) / totalCompanies * 100) : 0;
    float percentageBetween1MAnd50M = (totalCompanies > 0) ? (static_cast<double>(numBetween1MAnd50M) / totalCompanies * 100) : 0;
    float percentageBetween100KAnd1M = (totalCompanies > 0) ? (static_cast<double>(numBetween100KAnd1M) / totalCompanies * 100) : 0;
    float percentageBetween10KAnd100K = (totalCompanies > 0) ? (static_cast<double>(numBetween10KAnd100K) / totalCompanies * 100) : 0;
    float percentageLessThan10K = (totalCompanies > 0) ? (static_cast<double>(numLessThan10K) / totalCompanies * 100) : 0;

    // Create a pie series
    QPieSeries *series = new QPieSeries();
    series->append("More than 50M (" + QString::number(percentageMoreThan50M, 'f', 2) + "%)", percentageMoreThan50M);
    series->append("1M - 50M (" + QString::number(percentageBetween1MAnd50M, 'f', 2) + "%)", percentageBetween1MAnd50M);
    series->append("100K - 1M (" + QString::number(percentageBetween100KAnd1M, 'f', 2) + "%)", percentageBetween100KAnd1M);
    series->append("10K - 100K (" + QString::number(percentageBetween10KAnd100K, 'f', 2) + "%)", percentageBetween10KAnd100K);
    series->append("Less than 10K (" + QString::number(percentageLessThan10K, 'f', 2) + "%)", percentageLessThan10K);

    // Create a chart and set the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Net Worth Statistics");
    chart->setTheme(QChart::ChartThemeBlueNcs); // Set the chart theme (you can choose different themes)
    chart->setAnimationOptions(QChart::AllAnimations); // Enable chart animations

    // Create and set a chart legend
    QLegend *legend = chart->legend();
    legend->setAlignment(Qt::AlignRight);

    return chart;
}



QSqlQueryModel* Entrp::afficher_AN() {
    QString queryStr = "SELECT b.ID, b.DS, p.MONTANT, p.DATE_ISS, p.DATE_AVANT "
                       "FROM BDTUN b "
                       "JOIN PENALITE p ON b.ID = p.ID_ENT "
                       "WHERE p.PAID = 0";

    QSqlQuery query(queryStr);

    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery(query);

    return model;
}

QSqlQueryModel* Entrp::afficher_DATA() {
    QString queryStr = "SELECT ID,DS,DC,SECTEUR,CAPITAL,EFFECTIF FROM BDTUN WHERE PDF_CONTENT IS NOT NULL";

    QSqlQuery query(queryStr);

    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery(query);

    return model;
}
/*
void loadPDFIntoDatabase(int id,const QString &pdfFilePath) {
    QFile pdfFile(pdfFilePath);

    if (pdfFile.open(QIODevice::ReadOnly)) {
        QByteArray pdfData = pdfFile.readAll();

        QSqlQuery query;
        query.prepare("INSERT INTO PENALITE (pdf_content) VALUES (:pdfContent) WHERE ID_PEN=:id");
        query.bindValue(":pdfContent", pdfData);
        query.bindValue(":id", id);

        if (query.exec()) {
            qDebug() << "PDF file loaded into the database successfully.";
        } else {
            qDebug() << "Error: " << query.lastError().text();
        }

        pdfFile.close();
    } else {
        qDebug() << "Failed to open the PDF file.";
    }
}

*/


QByteArray Entrp::fetchPDFContentFromDatabase(int pdfId) {
       // Assuming you have a QSqlDatabase named 'db' and it's already open
       QSqlQuery query;
       query.prepare("SELECT PDF_CONTENT FROM BDTUN WHERE ID = :pdfId");
       query.bindValue(":pdfId", pdfId);

       if (query.exec() && query.next()) {
           // Retrieve the PDF content from the database
           return query.value(0).toByteArray();
       }

       // Handle error or return an empty QByteArray if the PDF is not found
       qDebug() << "Error fetching PDF content from the database:";
       return QByteArray();
   }

bool Entrp::deletePDFFromDatabase(int pdfId) {
    // Assuming you have a QSqlDatabase named 'db' and it's already open
    QSqlQuery query;
    query.prepare("UPDATE BDTUN SET PDF_CONTENT = NULL WHERE ID = :pdfId");
    query.bindValue(":pdfId", pdfId);

    if (query.exec()) {
        // The deletion was successful
        return true;
    }

    // Handle error
    qDebug() << "Error deleting PDF from the database:" ;
    return false;
}


bool Entrp::exportPDFToDatabase(int pdfId, const QByteArray& pdfContent) {
    // Assuming you have a QSqlDatabase named 'db' and it's already open
    QSqlQuery query;
    query.prepare("UPDATE BDTUN SET PDF_CONTENT = :pdfContent WHERE ID = :pdfId");
    query.bindValue(":pdfId", pdfId);
    query.bindValue(":pdfContent", pdfContent);

    if (query.exec()) {
        // The export was successful
        return true;
    }

    // Handle error
    qDebug() << "Error exporting PDF to the database:" ;
    return false;
}
