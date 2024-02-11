#include "mainwindow.h"
#include "connection.h"
#include "login.h"

#include <QApplication>
#include<QLabel>
#include<QMessageBox>
#include <QtSql>
#include <QCoreApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    if(test){


        QMessageBox::information(nullptr,QObject::tr("Database open"),
                              QObject::tr("Connection successfully estabished.\n")
                              ,QMessageBox::Close);


    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Database error"),
                              QObject::tr("connection failed.\n""Click cancel to exit.")
                              ,QMessageBox::Cancel);
    }
    LOGIN L;


    L.setWindowTitle("SIGN_IN");
    L.show();

    return a.exec();
}
