#include "modify.h"
#include "ui_modify.h"
#include "client.h"

#include<QMessageBox>


Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}


void Modify::onIDTextChanged(const QString &text) {
    int companyId = text.toInt(); // Get the ID from the QLineEdit

    QSqlQuery query;
    query.prepare("SELECT DS, DC, DIRIGEANT, ADRESSE, CP, PAYS, GOUVERNORAT, VILLE, TELEPHONE, FAX, EMAIL, SECTEUR, SOUSSECT, DIVISION, CAPITAL, EFFECTIF, CHAFFAIRE, SITEWEB FROM BDTUN WHERE ID = :id");
    query.bindValue(":id", companyId);

    if (query.exec() && query.next()) {
        ui->DSLE->setText(query.value(0).toString());
        ui->DCLE->setText(query.value(1).toString());
        ui->DIRLE->setText(query.value(2).toString());
        ui->ADRESSELE->setText(query.value(3).toString());
        ui->CPLE->setText(query.value(4).toString());
        ui->PAYSLE->setText(query.value(5).toString());
        ui->GVTLE->setText(query.value(6).toString());
        ui->VILLELE->setText(query.value(7).toString());
        ui->TLPHLE->setText(query.value(8).toString());
        ui->FAXLE->setText(query.value(9).toString());
        ui->EMAILLE->setText(query.value(10).toString());
        ui->SECTLE->setText(query.value(11).toString());
        ui->SSECTLE->setText(query.value(12).toString());
        ui->DIVLE->setText(query.value(13).toString());
        ui->CAPLE->setText(query.value(14).toString());
        ui->EFFLE->setText(query.value(15).toString());
        ui->CHAFFLE->setText(query.value(16).toString());
        ui->SITELE->setText(query.value(17).toString());
    }else
    {
        ui->DSLE->setText("");
           ui->DCLE->setText("");
           ui->DIRLE->setText("");
           ui->ADRESSELE->setText("");
           ui->CPLE->setText("");
           ui->PAYSLE->setText("");
           ui->GVTLE->setText("");
           ui->VILLELE->setText("");
           ui->TLPHLE->setText("");
           ui->FAXLE->setText("");
           ui->EMAILLE->setText("");
           ui->SECTLE->setText("");
           ui->SSECTLE->setText("");
           ui->DIVLE->setText("");
           ui->CAPLE->setText("");
           ui->EFFLE->setText("");
           ui->CHAFFLE->setText("");
           ui->SITELE->setText("");

    }
}

void Modify::on_pushButton_clicked()
{
    int id = ui->IDLE->text().toInt();
    QString newDS = ui->DSLE->text();
    QString newDC = ui->DCLE->text();
    QString newDirigeant = ui->DIRLE->text();
    QString newAdresse = ui->ADRESSELE->text();
    QString newCP = ui->CPLE->text();
    QString newPays = ui->PAYSLE->text();
    QString newGouvernorat = ui->GVTLE->text();
    QString newVille = ui->VILLELE->text();
    QString newTelephone = ui->TLPHLE->text();
    QString newFax = ui->FAXLE->text();
    QString newEmail = ui->EMAILLE->text();
    QString newSecteur = ui->SECTLE->text();
    QString newSousSect = ui->SSECTLE->text();
    QString newDivision = ui->DIVLE->text();
    double newCapital = ui->CAPLE->text().toDouble();
    int newEffectif = ui->EFFLE->text().toInt();
    double newChaffaire = ui->CHAFFLE->text().toDouble();
    QString newSiteWeb = ui->SITELE->text();

    if (Ctemp.updateCompanyInDatabase(id, newDS, newDC, newDirigeant, newAdresse, newCP, newPays, newGouvernorat, newVille, newTelephone, newFax, newEmail, newSecteur, newSousSect, newDivision, newCapital, newEffectif, newChaffaire, newSiteWeb)) {
        QMessageBox::information(this, "Success", "Company information updated successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to update company information.");
    }
}

void Modify::on_IDLE_returnPressed()
{
}

void Modify::on_IDLE_textChanged(const QString &arg1)
{
    onIDTextChanged(arg1);

}
