#include "supprime.h"
#include "ui_supprime.h"
#include "client.h"

#include<QMessageBox>

Supprime::Supprime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprime)
{
    ui->setupUi(this);
}

Supprime::~Supprime()
{
    delete ui;
}

void Supprime::on_pushButton_clicked()
{
    int id= ui->s1->text().toInt();
    bool test=Ctemp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("SUCCESSFULL"),QObject::tr("Suppression effectué\n"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("FAILED"),QObject::tr("Suppression non effectué\n"),QMessageBox::Ok);

    }
}
