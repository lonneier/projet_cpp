#include "employe.h"

employe::employe()
{

}
employe:: employe(int id_employe, QString nom, QString prenom, QString sexe, int telephone, QString adresse, QString departement, QString grade, double salaire)
{
    this->id_employe = id_employe;
    this->nom = nom;
    this->prenom = prenom;
    this->sexe = sexe ;
    this->telephone = telephone;
    this->adresse = adresse;
    this->departement = departement;
    this->grade = grade;
    this->salaire = salaire;
}
bool employe::UPDATE()
{
    QSqlQuery query;
    query.prepare("UPDATE employe SET nom=:nom, prenom=:prenom, sexe=:sexe, telephone=:telephone, adresse=:adresse, departement=:departement ,grade=:grade , salaire=:salaire  WHERE id_employe=:id_employe");
    query.bindValue(":id_employe", id_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":departement", departement);
    query.bindValue(":grade", grade);
    query.bindValue(":salaire", salaire);
    return query.exec();
}
bool employe::employeExists(int id_employe)
{
    bool exists = false;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_employe FROM employe WHERE id_employe = :id_employe");
    checkQuery.bindValue(":id_employe", id_employe);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "employe not found: " << checkQuery.lastError();
    }

    return exists;
}
bool employe::ADD()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employe (id_employe, nom, prenom, sexe, telephone, adresse, departement, grade, salaire) "
                   "VALUES (:id_employe, :nom, :prenom, :sexe, :telephone, :adresse, :departement, :grade, :salaire)");
    query.bindValue(":id_employe", id_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":departement", departement);
    query.bindValue(":grade", grade);
    query.bindValue(":salaire", salaire);

    if (query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Error adding employee: " << query.lastError();
        return false;
    }
}


bool employe::DELETEE(int id_employe)
{
    QSqlQuery query;
    query.prepare("DELETE FROM employe WHERE id_employe = :id_employe");
    query.bindValue(":id_employe", id_employe);
    return query.exec();
}
QSqlQueryModel* employe::GETALL()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_employe, nom, prenom, sexe, telephone, adresse, departement, grade, salaire FROM employe");

    if (model->lastError().isValid()) {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employe"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("grade"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}
QSqlTableModel* employe::getSortedModel()
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("employe");
    model->setSort(0, Qt::AscendingOrder);
    model->select();
    return model;
}
employe employe::getEmployeById(int id_employe)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE id_employe = :id_employe");
    query.bindValue(":id_employe", id_employe);
    query.exec();

    if (query.next()) {
        employe emp;
        emp.setIdEmploye(query.value(0).toInt());
        emp.setNom(query.value(2).toString());
        emp.setPrenom(query.value(6).toString());
        emp.setTelephone(query.value(1).toInt());
        emp.setDepartement(query.value(3).toString());
        emp.setGrade(query.value(4).toString());
        emp.setSexe(query.value(8).toString());
        emp.setAdresse(query.value(7).toString());
        emp.setSalaire(query.value(5).toInt());
        return emp;
    }
    else
        return employe();
}


void employe::writeToPDF(int id)
{
    QTextDocument document;
    employe emp=getEmployeById(id);

    document.setHtml("<h1>Employé</h1>"
                     "<p>ID : " + QString::number(emp.id_employe) + "</p>"
                     "<p>Nom : " + emp.nom + "</p>"
                     "<p>Prénom : " + emp.prenom + "</p>"
                     "<p>Sexe : " + emp.sexe + "</p>"
                     "<p>Telephone: " + QString::number(emp.telephone) + "</p>"
                     "<p>Adresse : " + emp.adresse + "</p>"
                     "<p>departement: " + emp.departement + "</p>"
                     "<p>Grade : " + emp.grade + "</p>"
                     "<p>Salaire : " + QString::number(emp.salaire) + "</p>"

                     );


    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("C:/Users/melek/employe.pdf");

    document.print(&printer);
}
void employe::stat(double *malePercentage,double *femalePercentage)
{
    QSqlQuery query;
    int total, males, females;
    query.exec("SELECT COUNT(*) FROM employe");
    if (query.next()) {
        total = query.value(0).toInt();
    }
    query.exec("SELECT COUNT(*) FROM employe WHERE sexe = 'homme'");
    if (query.next()) {
        males = query.value(0).toInt();
    }

    query.exec("SELECT COUNT(*) FROM employe WHERE sexe = 'femme'");
    if (query.next()) {
        females = query.value(0).toInt();
    }

     *malePercentage =(double) males / total * 100;
    *femalePercentage = (double)females / total * 100;

    qDebug() << "Pourcentage d'hommes : " << malePercentage << "%";
    qDebug() << "Pourcentage de femmes : " << femalePercentage << "%";

}
bool employe::isValidEmail(QString email) {
    QRegularExpression regex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");

       // We use QRegularExpressionMatch to test if the email matches the regex pattern
       QRegularExpressionMatch match = regex.match(email);

       // If the match is valid, return true. Otherwise, return false.
       return match.hasMatch();}


// setters for the attributes
void employe::setIdEmploye(int id_employe)
{
    this->id_employe = id_employe;
}

void employe::setNom(QString nom)
{
    this->nom = nom;
}

void employe::setPrenom(QString prenom)
{
    this->prenom = prenom;
}

void employe::setSexe(QString sexe)
{
    this->sexe = sexe;
}

void employe::setTelephone(int telephone)
{
    this->telephone = telephone;
}

void employe::setAdresse(QString adresse)
{
    this->adresse = adresse;
}

void employe::setDepartement(QString departement)
{
    this->departement = departement;
}

void employe::setGrade(QString grade)
{
    this->grade = grade;
}

void employe::setSalaire(double salaire)
{
    this->salaire = salaire;
}

// Getters for the attributes
int employe::getIdEmploye() const
{
    return id_employe;
}

QString employe::getNom() const
{
    return nom;
}

QString employe::getPrenom() const
{
    return prenom;
}

QString employe::getSexe() const
{
    return sexe;
}

int employe::getTelephone() const
{
    return telephone;
}

QString employe::getAdresse() const
{
    return adresse;
}

QString employe::getDepartement() const
{
    return departement;
}

QString employe::getGrade() const
{
    return grade;
}

double employe::getSalaire() const
{
    return salaire;
}
