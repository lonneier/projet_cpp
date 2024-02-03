#include "ajout.h"
#include "ui_ajout.h"
#include "client.h"
#include<QMessageBox>

ajout::ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout)
{
    ui->setupUi(this);
}

ajout::~ajout()
{
    delete ui;
}

void ajout::on_pushButton_clicked()
{
    double h=0;
    int id=ui->LID->text().toInt();
    QString nom=ui->LNOM->text();
    QString prenom=ui->LPRENOM->text();

    Entrp C(id,nom,prenom,h);
    bool test=C.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("SUCCESSFULL"),QObject::tr("Ajout effectué\n"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("FAILED"),QObject::tr("Ajout non effectué\n"),QMessageBox::Ok);

    }
}
