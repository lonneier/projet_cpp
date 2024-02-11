#include "connection.h"


Connection::Connection(){}

bool Connection::createconnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Iheb");
    db.setPassword("esprit18");
    if (db.open()) test=true;

    return test;



   /* if (db.open()) {
        qDebug() << "Connected to Oracle database.";
        // Your database operations go here.
    } else {
        qDebug() << "Failed to connect to Oracle database:" << db.lastError().text();
    }
    */
}


void Connection::closeconnection(){db.close();}
