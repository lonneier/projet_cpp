#include "alerte.h"
#include "ui_alerte.h"
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "matriels.h"
#include "mainwindow.h"
alerte::alerte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alerte)
{
    ui->setupUi(this);
    Matriels m;
    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT id FROM APP_MATRIELS WHERE garantie>=CURRENT_DATE ");
    //q->prepare("SELECT * FROM APP_MATRIELS WHERE garantie <= DATE_ADD(CURRENT_DATE,INTERVAL 3 MONTH) ");
    q->exec();
    model->setQuery(*q);
    ui->tableView->setModel(model);
}
alerte::~alerte()
{
    delete ui;
}
