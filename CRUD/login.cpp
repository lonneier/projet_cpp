#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include <iostream>

LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    this->access=false;
    this->access_code=0;

    QIcon icon(":/img/img/logo_app.png");
    this->setWindowIcon(icon);


    ////
    QPixmap pix(":/img/img/logo_app.png");
    int height = ui->pic->height();
    int width = ui->pic->width();
    ui->pic->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
    ////
    QPixmap pix2(":/img/img/logo_ministre.png");
    int height2 = ui->pic_2->height();
    int width2 = ui->pic_2->width();
    ui->pic_2->setPixmap(pix2.scaled(width2,height2,Qt::KeepAspectRatio));
}

LOGIN::~LOGIN()
{
    delete ui;
}



User getUserFromDatabase(QString inputName, QString inputPassword) {
    // Establish the database connection

    QSqlQuery query;

    query.prepare("SELECT * FROM USERS WHERE USERNAME = :inputName AND PASSWORD = :inputPassword");

    query.bindValue(":inputName",inputName);
    query.bindValue(":inputPassword",inputPassword);

    User foundUser;


    if(query.exec()){

    if (query.next()) {
        foundUser.setName(query.value("USERNAME").toString());
        foundUser.setPassword(query.value("PASSWORD").toString());
        foundUser.setAccessLevel(query.value("ACCESS_LEVEL").toInt());
    }
}


    return foundUser;
}


void LOGIN::on_login_but_clicked()
{
    QString usr = ui->USRLE->text();
    QString pswd = ui->PWDLE->text();

   if(!getUserFromDatabase(usr,pswd).getName().isEmpty())
   {
       QMessageBox::information(this,"Login","Logged in successfully");

       this->setAccess(true);


   }
   else
     {
       QMessageBox::critical(this,"Login","Username or password incorrect");

   }

   if(this->getAccess()){
   this->close();
   w.setWindowTitle("AUDITHUB");
   w.show();

   }
}
