#include "auditeur.h"

// Constructeur par défaut
auditeur::auditeur()
{
    // Ce constructeur ne fait rien car il est par défaut.
    // Il est utilisé pour créer des objets auditeur sans paramètres.
}

// Constructeur paramétré
auditeur::auditeur(int id_auditeur, QString nom_auditeur, QString prenom_auditeur, QString sexe, int telephone,
                   QString adresse, QString email, QString departement, double salaire, QString secteur,
                   QString mission, QString grade, bool archive,QString image)
{
    // Initialise les attributs de la classe avec les valeurs passées en paramètres
    this->id_auditeur = id_auditeur;
    this->nom_auditeur = nom_auditeur;
    this->prenom_auditeur = prenom_auditeur;
    this->sexe = sexe;
    this->telephone = telephone;
    this->adresse = adresse;
    this->email = email;
    this->departement = departement;
    this->salaire = salaire;
    this->secteur = secteur;
    this->mission = mission;
    this->grade = grade;
    this->archive = archive;
    this->image=image;
}


// Fonction pour mettre à jour les informations d'un auditeur dans la base de données
bool auditeur::UPDATE()
{
    // Prépare une requête SQL pour mettre à jour les informations de l'auditeur dans la table "auditeur"
    QSqlQuery query;
    query.prepare("UPDATE auditeur SET nom_auditeur=:nom_auditeur, prenom_auditeur=:prenom_auditeur, sexe=:sexe, telephone=:telephone, adresse=:adresse, email=:email, departement=:departement, salaire=:salaire, secteur=:secteur, mission=:mission, grade=:grade, archive=:archive,image=:image WHERE id_auditeur=:id_auditeur");

    // Lie les valeurs des paramètres de la requête aux attributs de l'objet auditeur
    query.bindValue(":id_auditeur", id_auditeur);
    query.bindValue(":nom_auditeur", nom_auditeur);
    query.bindValue(":prenom_auditeur", prenom_auditeur);
    query.bindValue(":sexe", sexe);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":departement", departement);
    query.bindValue(":salaire", salaire);
    query.bindValue(":secteur", secteur);
    query.bindValue(":mission", mission);
    query.bindValue(":grade", grade);
    query.bindValue(":archive", archive);
     query.bindValue(":image", image);

    // Exécute la requête SQL et retourne true si elle réussit, sinon false
    return query.exec();
}


// Fonction pour générer un graphique de statistiques de capacité et retourner une vue QChartView
QChartView *auditeur::stat_capacite()
{
    // Initialise les compteurs pour les missions réussies et échouées
    int reussi = 0;
    int echoue = 0;

    // Effectue une requête SQL pour compter le nombre d'auditeurs ayant réussi leur mission
    QSqlQuery query;
    query.prepare("SELECT * FROM auditeur WHERE mission='reussi'");
    query.exec();

    // Incrémente le compteur pour chaque résultat de la requête
    while (query.next())
        reussi++;

    // Effectue une requête SQL pour compter le nombre d'auditeurs ayant échoué leur mission
    query.prepare("SELECT * FROM auditeur WHERE mission='echoue'");
    query.exec();

    // Incrémente le compteur pour chaque résultat de la requête
    while (query.next())
        echoue++;

    // Affiche les résultats dans la console de débogage
    qDebug() << "Réussi:" << reussi << "Échoué:" << echoue;

    // Crée un objet QPieSeries pour représenter les données du graphique
    QPieSeries *series = new QPieSeries();
    series->append("Réussi", reussi);
    series->append("Échoué", echoue);

    // Modifie l'apparence du premier segment du diagramme (Réussi)
    QPieSlice *slice = series->slices().at(0);
    slice->setExploded(true);
    slice->setColor("#f37b78");

    // Modifie l'apparence du deuxième segment du diagramme (Échoué)
    QPieSlice *slice2 = series->slices().at(1);
    slice2->setColor("#663333");

    // Crée un objet QChart pour représenter le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique du Capacite");

    // Rend les étiquettes des segments visibles
    series->setLabelsVisible();

    // Crée une vue QChartView et configure ses propriétés
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setAnimationOptions(QChart::AllAnimations);
    chartView->chart()->legend()->hide();
    chartView->resize(1000, 500);

    // Retourne la vue du graphique
    return chartView;
}



// Fonction pour trouver un auditeur par son identifiant dans la base de données
QSqlQueryModel* auditeur::findbyid(int NUMERO)
{
    // Crée un nouveau modèle QSqlQueryModel
    QSqlQueryModel *modal = new QSqlQueryModel();

    // Construit la requête SQL pour sélectionner tous les auditeurs dont l'identifiant correspond à NUMERO
    modal->setQuery("SELECT * FROM auditeur WHERE id_auditeur LIKE '%" + QString::number(NUMERO) + "%'");

    // Retourne le modèle contenant les résultats de la requête
    return modal;
}

// Fonction pour ajouter un nouvel auditeur à la base de données
bool auditeur::ADD()
{
    // Prépare une requête SQL d'INSERT pour ajouter les informations de l'auditeur à la table "auditeur"
    QSqlQuery query;
    query.prepare("INSERT INTO auditeur (id_auditeur, nom_auditeur, prenom_auditeur, sexe, telephone, adresse, email, departement, salaire, secteur, mission, grade, archive,image) "
                  "VALUES (:id_auditeur, :nom_auditeur, :prenom_auditeur, :sexe, :telephone, :adresse, :email, :departement, :salaire, :secteur, :mission, :grade, :archive, :image)");

    // Lie les valeurs des paramètres de la requête aux attributs de l'objet auditeur
    query.bindValue(":id_auditeur", id_auditeur);
    query.bindValue(":nom_auditeur", nom_auditeur);
    query.bindValue(":prenom_auditeur", prenom_auditeur);
    query.bindValue(":sexe", sexe);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":departement", departement);
    query.bindValue(":salaire", salaire);
    query.bindValue(":secteur", secteur);
    query.bindValue(":mission", mission);
    query.bindValue(":grade", grade);
    query.bindValue(":archive", archive);
    query.bindValue(":image", image);
    // Exécute la requête SQL et retourne true si elle réussit, sinon false
    return query.exec();
}



// Fonction pour supprimer un auditeur de la base de données par son identifiant
bool auditeur::DELETEE(int id_auditeur)
{
    // Prépare une requête SQL de type DELETE pour supprimer l'auditeur de la table "auditeur"
    QSqlQuery query;
    query.prepare("DELETE FROM auditeur WHERE id_auditeur = :id_auditeur");

    // Lie la valeur du paramètre de la requête à l'identifiant de l'auditeur
    query.bindValue(":id_auditeur", id_auditeur);

    // Exécute la requête SQL et retourne true si elle réussit, sinon false
    return query.exec();
}


// Fonction pour récupérer tous les enregistrements de la table "auditeur"
QSqlQueryModel* auditeur::GETALL()
{
    // Crée un nouveau modèle QSqlQueryModel
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécute une requête SQL pour sélectionner tous les champs de la table "auditeur"
    model->setQuery("SELECT id_auditeur, nom_auditeur, prenom_auditeur, sexe, telephone, adresse, email, departement, salaire, secteur, mission, grade, archive,image FROM auditeur");

    // Vérifie s'il y a une erreur dans la dernière requête SQL exécutée
    if (model->lastError().isValid()) {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
        return nullptr;  // Retourne nullptr en cas d'erreur
    }

    // Définit les noms de colonnes dans le modèle
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_auditeur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_auditeur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_auditeur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("departement"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("secteur"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("mission"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("grade"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("archive"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("image"));
    // Retourne le modèle contenant les résultats de la requête
    return model;
}

// Fonction pour trier les enregistrements de la table "auditeur" en fonction du critère et de l'ordre spécifiés
QSqlQueryModel* auditeur::trie(QString croissance, QString critere)
{
    // Crée un nouveau modèle QSqlQueryModel
    QSqlQueryModel* modal = new QSqlQueryModel();

    // Sélectionne la requête SQL en fonction du critère et de l'ordre de tri
    if (critere == "nom" && croissance == "ASC")
        modal->setQuery("SELECT * FROM auditeur ORDER BY nom_auditeur ASC ");
    else if (critere == "nom" && croissance == "DESC")
        modal->setQuery("SELECT * FROM auditeur ORDER BY nom_auditeur DESC ");
    else if (critere == "prenom" && croissance == "ASC")
        modal->setQuery("SELECT * FROM auditeur ORDER BY prenom_auditeur ASC ");
    else if (critere == "prenom" && croissance == "DESC")
        modal->setQuery("SELECT * FROM auditeur ORDER BY prenom_auditeur DESC ");
    else if (critere == "salaire" && croissance == "ASC")
        modal->setQuery("SELECT * FROM auditeur ORDER BY salaire ASC ");
    else if (critere == "salaire" && croissance == "DESC")
        modal->setQuery("SELECT * FROM auditeur ORDER BY salaire DESC ");

    // Retourne le modèle contenant les résultats de la requête de tri
    return modal;
}
// Fonction pour vérifier si un auditeur avec un identifiant spécifique existe déjà dans la base de données
bool auditeur::auditeurexiste(QString idauditeur)
{
    // Initialise une variable booléenne à false (par défaut, l'auditeur n'existe pas)
    bool exists = false;

    // Prépare une requête SQL SELECT pour vérifier l'existence de l'auditeur avec l'identifiant spécifié
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_auditeur FROM auditeur WHERE id_auditeur=:id_auditeur");
    checkQuery.bindValue(":id_auditeur", idauditeur);

    // Exécute la requête SELECT
    if (checkQuery.exec())
    {
        // Si la requête a été exécutée avec succès, vérifie s'il y a au moins une ligne dans le résultat
        if (checkQuery.next())
        {
            exists = true;  // L'auditeur existe s'il y a au moins une ligne dans le résultat
        }
    }
    else
    {
        qDebug() << "Error checking if auditeur exists:" << checkQuery.lastError();
    }

    // Retourne la valeur de la variable booléenne indiquant si l'auditeur existe ou non
    return exists;
}


// Setters for the new attributes
void auditeur::set_id_auditeur(int id_auditeur)
{
    this->id_auditeur = id_auditeur;
}

void auditeur::set_nom_auditeur(QString nom_auditeur)
{
    this->nom_auditeur = nom_auditeur;
}

void auditeur::set_prenom_auditeur(QString prenom_auditeur)
{
    this->prenom_auditeur = prenom_auditeur;
}

void auditeur::set_sexe(QString sexe)
{
    this->sexe = sexe;
}

void auditeur::set_telephone(int telephone)
{
    this->telephone = telephone;
}

void auditeur::set_adresse(QString adresse)
{
    this->adresse = adresse;
}

void auditeur::set_email(QString email)
{
    this->email = email;
}

void auditeur::set_departement(QString departement)
{
    this->departement = departement;
}

void auditeur::set_salaire(double salaire)
{
    this->salaire = salaire;
}

void auditeur::set_secteur(QString secteur)
{
    this->secteur = secteur;
}

void auditeur::set_mission(QString mission)
{
    this->mission = mission;
}

void auditeur::set_grade(QString grade)
{
    this->grade = grade;
}

void auditeur::set_archive(bool archive)
{
    this->archive = archive;
}
void auditeur::set_image(QString image){

    this->image=image;
};

// Getters for the new attributes
int auditeur::get_id_auditeur() const
{
    return id_auditeur;
}

QString auditeur::get_nom_auditeur() const
{
    return nom_auditeur;
}

QString auditeur::get_prenom_auditeur() const
{
    return prenom_auditeur;
}

QString auditeur::get_sexe() const
{
    return sexe;
}

int auditeur::get_telephone() const
{
    return telephone;
}

QString auditeur::get_adresse() const
{
    return adresse;
}

QString auditeur::get_email() const
{
    return email;
}

QString auditeur::get_departement() const
{
    return departement;
}

double auditeur::get_salaire() const
{
    return salaire;
}

QString auditeur::get_secteur() const
{
    return secteur;
}

QString auditeur::get_mission() const
{
    return mission;
}

QString auditeur::get_grade() const
{
    return grade;
}

bool auditeur::get_archive() const
{
    return archive;
}

QString auditeur::get_image() const
{
    return image;
}

