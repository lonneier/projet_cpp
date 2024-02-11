#include "formations.h"


formations::formations()
{

    num_form = 0; // Set to a default integer value
    type_form = ""; // Set to a default QString value
    date_form = QDate(); // Set to a default QDate value
    id_form = 0; // Set to a default integer value
    niv_stag = ""; // Set to a default QString value
}
formations::formations(int num_form, const QString& type_form, const QDate& date_form, int id_form, const QString& niv_stag)
    : num_form(num_form), type_form(type_form), date_form(date_form), id_form(id_form), niv_stag(niv_stag)
{

}
formations::~formations()
{

}

bool formations::UPDATE()
{
    QSqlQuery query;
    query.prepare("UPDATE formations SET NUM_FORMATION=:num_form, TYPE_FORMATION=:type_form, DATE_FORMATION=:date_form , NIVEAU_STAGIAIRE=:niv_stag WHERE ID_FORMATEUR=:id_form");
    query.bindValue(":id_form", id_form);
    query.bindValue(":num_form", num_form);
    query.bindValue(":type_form", type_form);
    query.bindValue(":date_form", date_form);
    query.bindValue(":niv_stag", niv_stag);

   // return query.exec();
    if (query.exec()) {
            // Vérifier si une ligne a été effectivement mise à jour
            return query.numRowsAffected() > 0;
        } else {
            qDebug() << "Erreur lors de la mise à jour : " << query.lastError().text();
            return false;
        }
}



bool formations::ADD()
{
    QSqlQuery query;


    query.prepare("INSERT INTO formations (ID_FORMATEUR, NUM_FORMATION, TYPE_FORMATION, DATE_FORMATION, NIVEAU_STAGIAIRE ) "
                   "VALUES (:id_form, :num_form, :type_form, :date_form, :niv_stag)");
    query.bindValue(":id_form", id_form);
    query.bindValue(":num_form", num_form);
    query.bindValue(":type_form", type_form);
    query.bindValue(":date_form", date_form);
    query.bindValue(":niv_stag", niv_stag);
    return query.exec();
}


bool formations::checkPresence(int id_form)
{
    QSqlQuery query;
    query.prepare("SELECT NIVEAU_STAGIAIRE FROM formations WHERE ID_FORMATEUR = :id_form");
    query.bindValue(":id_form", id_form);

    if (query.exec() && query.next()) {

        QString niveauStagiaire = query.value("NIVEAU_STAGIAIRE").toString();
        return !niveauStagiaire.isEmpty();
    }

    qDebug() << "Erreur lors de la vérification de la présence : " << query.lastError().text();
    return false;
}

QSqlQueryModel* formations::FINDBYIdForm(int id_form)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM formations WHERE id_form = " + QString::number(id_form));
    return model;
}
bool formations::DELETEE(int id_form)
{
   QSqlQuery query;
   query.prepare("DELETE FROM formations WHERE id_form = :id_form");
   query.bindValue(":id_form", id_form);
   return query.exec();
}

QSqlQueryModel* formations::GETALL()
{
   QSqlQueryModel* model = new QSqlQueryModel();
   model->setQuery("SELECT ID_FORMATEUR,NUM_FORMATION,TYPE_FORMATION,DATE_FORMATION,NIVEAU_STAGIAIRE FROM formations");

   if (model->lastError().isValid()) {
       qDebug() << "Error in SQL Query: " << model->lastError().text();
       return nullptr;
   }



   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_form"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_form"));
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_form"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("niv_stag"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_form"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("evaluation"));


   return model;
}

bool formations::ControlSaisie()
{

    if (typeid(num_form) != typeid(int) || num_form==0) {
        qDebug() << "Erreur: num_form doit être un entier.";
        return false;
    }


    if (typeid(type_form) != typeid(QString)  || type_form.isEmpty()) {
        qDebug() << "Erreur: type_form doit être une QString de taille 3.";
        return false;
    }


    if (typeid(date_form) != typeid(QDate)) {
        qDebug() << "Erreur: date_form doit être une QDate.";
        return false;
    }


    if (typeid(id_form) != typeid(int) || id_form==0) {
        qDebug() << "Erreur: id_form doit être un entier.";
        return false;
    }


    if (typeid(niv_stag) != typeid(QString) || niv_stag.size() > 3  || niv_stag.isEmpty()) {
        qDebug() << "Erreur: niv_stag doit être une QString de taille 3.";
        return false;
    }


    return true;
}
