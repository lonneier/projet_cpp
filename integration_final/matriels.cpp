#include "matriels.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
//#include <QPrinter>
//"#include <QPrintDialog>
#include <QPainter>
#include <QTextDocument>
Matriels::Matriels()
{
    id=0;
    nom=" ";
    type=" ";
    etat=" ";
    disponibilite=0;


}
Matriels::Matriels(int id,QString nom,QString type,QString etat,QDate garantie,int disponibilite)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->etat=etat;
    this->garantie=garantie;
    this->disponibilite=disponibilite;
}
int Matriels ::getid(){return id;}
QString Matriels:: getnom(){return nom;}
QString Matriels:: gettype(){return type;}
QString Matriels:: getetat(){return etat;}
QDate Matriels:: getgarantie(){return garantie;}
int Matriels ::getdisponibilite(){return disponibilite;}

void Matriels:: setid(int id){this->id=id;}
void Matriels:: setnom(QString nom){this->nom=nom;}
void Matriels:: settype(QString type){ this->type=type;}
void Matriels:: setetat(QString etat){ this->etat=etat;}
void Matriels:: setgarantie(QDate garantie){ this->garantie=garantie;}
void Matriels :: setdisponibilite(int disponibilite){this->disponibilite=disponibilite;}


bool Matriels:: ajouter()
{
    //bool test=false;
    QSqlQuery query;
       QString id_string=QString::number(id);
            query.prepare("INSERT INTO APP_MATRIELS (id, nom, type,etat,garantie,disponibilite) "
                          "VALUES (:id, :nom, :type, :etat ,:garantie,:disponibilite )");
            query.bindValue(":id", id_string);
            query.bindValue(":nom", nom);
            query.bindValue(":type", type);
            query.bindValue(":etat", etat);
            query.bindValue(":garantie", garantie);
            query.bindValue(":disponibilite",disponibilite);
            query.exec();
            return query.exec();
}

bool Matriels:: supprimer(int id)
{


    QSqlQuery query;
        //QString reference_string=QString::number(reference);
             query.prepare("Delete from APP_MATRIELS where id=:id");
             query.bindValue(0,id);
             return query.exec();

}





 QSqlQueryModel* Matriels:: afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();


        model->setQuery("SELECT * FROM APP_MATRIELS");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("garantie"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("disponibilite"));

        return model;
 }


 bool Matriels::modifier()
 {

    // bool test=false;
     QSqlQuery query;

     //QString id_string=QString::number(id);

     query.prepare("UPDATE APP_MATRIELS SET nom=:nom, type=:type, etat=:etat ,garantie=:garantie,disponibilite=:disponibilite WHERE id=:id");
     query.bindValue(":id", id);
     query.bindValue(":nom", nom);
     query.bindValue(":type",type);
     query.bindValue(":etat",etat);
     query.bindValue(":garantie", garantie);
     query.bindValue(":disponibilite", disponibilite);



           return query.exec();
          // return test;


 }
 QSqlQuery Matriels::rechercher(int id)
 {
     QSqlQuery query;
         query.prepare("SELECT * from APP_MATRIELS  WHERE id= :id");
         query.bindValue(":id", id);

        return query;
  }

 QSqlQueryModel * Matriels::tri()
          {
              QSqlQuery *q = new QSqlQuery();
              QSqlQueryModel *model = new QSqlQueryModel();
              q->prepare("SELECT * FROM APP_MATRIELS ORDER BY id ");
              q->exec();
              model->setQuery(*q);

              return model;
 }
 void Matriels::calculateEtatStatistics()
 {

     QSqlQuery Query("SELECT COUNT(*) FROM APP_MATRIELS");
     int totalCount = 0;
     if (Query.next())
         {
             totalCount = Query.value(0).toInt();
         }


     QSqlQuery query("SELECT COUNT(*) FROM APP_MATRIELS WHERE etat = 'en panne'");
     int panneCount = 0;

     if (query.next()) {
         panneCount = query.value(0).toInt();
     }


     query.exec("SELECT COUNT(*) FROM APP_MATRIELS WHERE etat = 'en bon etat'");
     int bonEtatCount = 0;

     if (query.next()) {
         bonEtatCount = query.value(0).toInt();
     }


     query.exec("SELECT COUNT(*) FROM APP_MATRIELS WHERE etat = 'a detruire'");
     int aDetruireCount = 0;

     if (query.next()) {
         aDetruireCount = query.value(0).toInt();
     }
     double percentagePanne = ((double)panneCount / totalCount) * 100;
     double percentageBonneetat = (bonEtatCount * 100.0) / totalCount;
     double percentageAdtruire = (aDetruireCount * 100.0) / totalCount;



     qDebug() << "Nombre de matériels en panne : " <<percentagePanne;
     qDebug() << "Nombre de matériels en bon etat : " << percentageBonneetat;
     qDebug() << "Nombre de matériels à détruire : " << percentageAdtruire;
 }





 bool Matriels::rechercher_arduino(int id)
 {

         QSqlQuery qry;
         QString sQuery = "SELECT * from APP_MATRIELS  WHERE id= :id";

         qry.prepare(sQuery);
         qry.bindValue(":id", id);

         if (qry.exec() && qry.next())
         {
             // Si la requête s'est exécutée avec succès et qu'il y a au moins une ligne de résultats
             return true;
         }

         // Aucun résultat trouvé
         return false;


 }
bool Matriels::modifierarduino(int disponibilite){
      QSqlQuery qry;
     qry.prepare("UPDATE APP_MATRIELS disponibilite=disponibilite WHERE id= :id");
     qry.bindValue(":disponibilite", disponibilite);
     return qry.exec();
 }




