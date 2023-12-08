#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("source_projet2a");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("221JMT6233");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection()
{
    db.close();
}
