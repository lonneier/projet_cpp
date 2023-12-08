#ifndef FORMATIONS_H
#define FORMATIONS_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlError>

class formations
{
private:
    int num_form;
    QString type_form;
    QDate date_form;
    int id_form;
    QString niv_stag;
    int evaluation;

public:
    int getEvaluation() const;
     void setEvaluation(int value);

     bool ControlSaisie();

     bool evaluerFormation(int id_form, int evaluation);
      bool checkPresence(int id_form);
    //bool formationsExists(int id_form);
    formations(int num_form, const QString& type_form, const QDate& date_form, int id_form, const QString& niv_stag);
    formations(); // Default constructor
    ~formations();
   // bool insertData(int num_form, const QString& type_form, const QDate& date_form, int id_form, const QString& niv_stag);


    int getNumForm() const;
    void setNumForm(int value);
    QString getTypeForm() const;
    void setTypeForm(const QString& value);
    QDate getDateForm() const;
    void setDateForm(const QDate& value);
    int getIdForm() const;
    void setIdForm(int value);
    QString getNivStag() const;
    void setNivStag(const QString& value);

    bool UPDATE();
   // bool formationsExists(int id_form);
    bool ADD();
    QSqlQueryModel* FINDBYIdForm(int id_form);
    bool DELETEE(int id_form);
    QSqlQueryModel* GETALL();
  //  void sortStagiairesAsc();
 //   void sortStagiairesDesc();

    //bool formationsExists(int id_form);



};



#endif // FORMATIONS_H
