#include "penalite.h"


penalite::penalite()
{

}
penalite::penalite(int numero_penalite, QDate date_penalite, double montant, QString nature, int id_auditeur, QString notes)
{
    this->numero_penalite = numero_penalite;
    this->date_penalite = date_penalite;
    this->montant = montant;
    this->nature = nature ;
    this->id_auditeur = id_auditeur;
    this->notes = notes;
}
bool penalite::UPDATE()
{
    QSqlQuery query;
    query.prepare("UPDATE penaliter SET date_penalite=:date_penalite, montant=:montant, nature=:nature, id_auditeur=:id_auditeur, notes=:notes WHERE numero_penalite=:numero_penalite");
    query.bindValue(":numero_penalite", numero_penalite);
    query.bindValue(":date_penalite", date_penalite);
    query.bindValue(":montant", montant);
    query.bindValue(":nature", nature);
    query.bindValue(":id_auditeur", id_auditeur);
    query.bindValue(":notes", notes);

    return query.exec();
}
bool penalite::penaliteExists(int numero_penalite)
{
    bool exists = false;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT NUMERO_PENALITE FROM PENALITER WHERE NUMERO_PENALITE = :numero_penalite");
    checkQuery.bindValue(":numero_penalite", numero_penalite);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Penalite not found: " << checkQuery.lastError();
    }

    return exists;
}
bool penalite::ADD()
{
    QSqlQuery query;
    query.prepare("INSERT INTO penaliter (numero_penalite, date_penalite, montant, nature, id_auditeur, notes) "
                   "VALUES (:numero_penalite, :date_penalite, :montant, :nature, :id_auditeur, :notes)");
    query.bindValue(":numero_penalite", numero_penalite);
    query.bindValue(":date_penalite", date_penalite);
    query.bindValue(":montant", montant);
    query.bindValue(":nature", nature);
    query.bindValue(":id_auditeur", id_auditeur);
    query.bindValue(":notes", notes);

    if(query.exec())
        return true;
    else
    {
        qDebug() << "Error adding penalty: " << query.lastError();
        return false;
    }
}

bool penalite::DELETEE(int numero_penalite)
{
    QSqlQuery query;
    query.prepare("DELETE FROM penaliter WHERE numero_penalite = :numero_penalite");
    query.bindValue(":numero_penalite", numero_penalite);
    return query.exec();
}

QSqlQueryModel* penalite::GETALL()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT numero_penalite, date_penalite, montant, nature, id_auditeur, notes FROM penaliter");

    if (model->lastError().isValid()) {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_penalite"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_penalite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nature"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_auditeur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("notes"));

    return model;
}
penalite penalite::getPenaliteByNum(int numero_penalite)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM penaliter WHERE numero_penalite = :numero_penalite");
    query.bindValue(":numero_penalite", numero_penalite);
    query.exec();

    if (query.next()) {
        penalite pen;
               pen.set_numero_penalite(query.value(0).toInt());
               pen.set_date_penalite(query.value(1).toDate());
               pen.set_montant(query.value(2).toDouble());
               pen.set_nature(query.value(3).toString());
               pen.set_id_auditeur(query.value(4).toInt());
               pen.set_notes(query.value(5).toString());
               return pen;
    }
    else
        return penalite();
}

void penalite::writeToPDF(int numero_penalite)
{
    penalite pen = getPenaliteByNum(numero_penalite);

    // Vérifiez si les données de la pénalité sont correctes
    qDebug() << "Numéro : " << pen.get_numero_penalite();
    qDebug() << "Date : " << pen.get_date_penalite().toString("dd.MM.yyyy");
    qDebug() << "Montant : " << pen.get_montant();
    qDebug() << "Nature : " << pen.get_nature();
    qDebug() << "ID Auditeur : " << pen.get_id_auditeur();
    qDebug() << "Notes : " << pen.get_notes();

    QTextDocument document;
    document.setHtml("<h1>Pénalité</h1>"
                        "<p>Numéro : " + QString::number(pen.get_numero_penalite()).toHtmlEscaped() + "</p>"
                        "<p>Date : " + pen.get_date_penalite().toString("dd.MM.yyyy").toHtmlEscaped() + "</p>"
                        "<p>Montant : " + QString::number(pen.get_montant()).toHtmlEscaped() + "</p>"
                        "<p>Nature : " + pen.get_nature().toHtmlEscaped() + "</p>"
                        "<p>ID Auditeur : " + QString::number(pen.get_id_auditeur()).toHtmlEscaped() + "</p>"
                        "<p>Notes : " + pen.get_notes().toHtmlEscaped() + "</p>"
                        );

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("C:/Users/melek/Desktop/pdf penalite.pdf");
    document.print(&printer);
}
QSqlQueryModel* penalite::trie(QString croissance, QString critere)
{
    // Crée un nouveau modèle QSqlQueryModel
    QSqlQueryModel* model = new QSqlQueryModel();

    qDebug() << "Critère de tri : " << critere.trimmed();
    qDebug() << "Croissance : " << croissance.trimmed();

    // Sélectionne la requête SQL en fonction du critère et de l'ordre de tri
    if (critere.trimmed().compare("nature", Qt::CaseInsensitive) == 0 && croissance.trimmed().compare("ASC", Qt::CaseInsensitive) == 0)
        model->setQuery("SELECT * FROM penaliter ORDER BY nature ASC ");
    else if (critere.trimmed().compare("nature", Qt::CaseInsensitive) == 0 && croissance.trimmed().compare("DESC", Qt::CaseInsensitive) == 0)
        model->setQuery("SELECT * FROM penaliter ORDER BY nature DESC ");
    else if (critere.trimmed().compare("numero_penalite", Qt::CaseInsensitive) == 0 && croissance.trimmed().compare("ASC", Qt::CaseInsensitive) == 0)
        model->setQuery("SELECT * FROM penaliter ORDER BY numero_penalite ASC ");
    else if (critere.trimmed().compare("numero_penalite", Qt::CaseInsensitive) == 0 && croissance.trimmed().compare("DESC", Qt::CaseInsensitive) == 0)
        model->setQuery("SELECT * FROM penaliter ORDER BY numero_penalite DESC ");
    else
        qDebug() << "Aucune condition remplie pour définir la requête.";

    qDebug() << "Requête SQL : " << model->query().lastQuery();

    // Retourne le modèle contenant les résultats de la requête de tri
    return model;
}
/*void penalite::chatbot(QTextEdit *chat, QLineEdit *user_input)
{
    QString message = user_input->text();
    if (!message.isEmpty())
    {
        chat->append("Utilisateur: " + message);
        user_input->clear();

        if (message.toLower() == "hi")
        {
            chat->append("Chatbot: Hi, comment puis-je vous aider ?");
        }
        else if (message.toLower() == "bonjour")
        {
            chat->append("Chatbot: Bonjour, comment puis-je vous aider ?");
        }
    }
}*/


/*void penalite::generateQRCode(QLabel *qr_code, QLineEdit *numero_penalite_2)
{
    // Récupérer le numéro de pénalité du QLineEdit
    int numero_penalite = numero_penalite_2->text().toInt();

    // Vérifier si la pénalité existe
    if (penaliteExists(numero_penalite)) {
        // Générer le QR code
        const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(numero_penalite_2->text().toStdString().c_str(), qrcodegen::QrCode::Ecc::LOW);

        // Convertir le QR code en QImage
        QImage image(qr.getSize(), qr.getSize(), QImage::Format_Mono);
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                image.setPixel(x, y, qr.getModule(x, y) ? 0 : 1);
            }
        }

        // Convertir l'image en QPixmap et l'afficher dans le QLabel
        QPixmap pixmap = QPixmap::fromImage(image).scaled(100, 100);
        qr_code->setPixmap(pixmap);
    } else {
        // Afficher un message d'erreur
        QMessageBox::warning(nullptr, "Erreur", "La pénalité n'existe pas.");
    }
}*/

















// setters for the attributes
void penalite::set_numero_penalite(int numero_penalite)
{
    this->numero_penalite = numero_penalite;
}

void penalite::set_date_penalite(QDate date_penalite)
{
    this->date_penalite = date_penalite;
}

void penalite::set_montant(double montant)
{
    this->montant = montant;
}

void penalite::set_nature(QString nature)
{
    this->nature = nature;
}

void penalite::set_id_auditeur(int id_auditeur)
{
    this->id_auditeur = id_auditeur;
}

void penalite::set_notes(QString notes)
{
    this->notes = notes;
}

// Getters for the attributes
int penalite::get_numero_penalite() const
{
    return numero_penalite;
}

QDate penalite::get_date_penalite() const
{
    return date_penalite;
}

double penalite::get_montant() const
{
    return montant;
}

QString penalite::get_nature() const
{
    return nature;
}

int penalite::get_id_auditeur() const
{
    return id_auditeur;
}

QString penalite::get_notes() const
{
    return notes;
}

