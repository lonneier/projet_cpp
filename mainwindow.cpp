#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "matriels.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExp>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QSqlRecord>
#include <QTableWidgetSelectionRange>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExp>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QSqlRecord>
#include <QTableWidgetSelectionRange>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QFont>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QtGlobal>
#include <QPainter>
#include <QVector>
#include "arduino.h"
#include "alerte.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Arduino A;
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                break;
        case(-1):qDebug() << "arduino is not available";
                }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données)
    QByteArray responseData = A.getserial()->readAll();
    qDebug() << "Réponse reçue:" << responseData;
    Matriels m;





    ui->le_id->setValidator(new QIntValidator(0,999,this));
    ui->table_matriels->setModel(m.afficher());

    ui->le_id->setClearButtonEnabled(true);
    ui->le_nom->setClearButtonEnabled(true);
    //ui->le_etat_mod_3->setClearButtonEnabled(true);
    //ui->le_type->setClearButtonEnabled(true);

    //ui->le_id->setClearButtonEnabled(true);
    //ui->le_nom->setClearButtonEnabled(true);
    //ui->le_etat_mod->setClearButtonEnabled(true);
    //ui->le_type_mod->setClearButtonEnabled(true);
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
    QBarSet *set0 = new QBarSet("Percentage de matériels en panne");
        QBarSet *set1 = new QBarSet("Percentage de matériels en bon etat ");
        QBarSet *set2 = new QBarSet("Percentage de matériels a detruire");

            * set0 <<percentagePanne<<100 ;
            * set1 << percentageBonneetat<<100  ;
            * set2 <<percentageAdtruire <<100  ;




            QBarSeries *series = new QBarSeries();
            series->append(set0);
            series->append(set1);
            series->append(set2);
            //series->append(set3);
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("stats");
            chart->setAnimationOptions(QChart:: SeriesAnimations);
            chart->resize(450,420);
            QStringList categories;
            categories << " matriels" ;
            QBarCategoryAxis *axis = new QBarCategoryAxis();
            axis->append(categories);
            chart->createDefaultAxes();
            chart->setAxisX(axis,series);
            QChartView *chartView = new QChartView(chart);
            chartView->setParent(ui->stat_matriel);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString type=ui->le_type->currentText();
    QString etat=ui->le_etat_mod_3->currentText();
    QDate garantie=ui->dateEdit_2->date();
    int disponibilite=ui->le_id_2->text().toInt();
    Matriels m(id,nom,type,etat,garantie,disponibilite);
    bool test=m.ajouter();
     QMessageBox msgBox;
      if(test)
         { msgBox.setText("echec");
        ui->table_matriels->setModel(m.afficher());
      }
      else
          ui->table_matriels->setModel(m.afficher());
          ui->le_id->clear();
          ui->le_nom->clear();

          msgBox.setText("Ajout avec sucees.");
          msgBox.exec();

}

void MainWindow::on_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString type=ui->le_type->currentText();
    QString etat=ui->le_etat_mod_3->currentText();
    QDate garantie=ui->dateEdit_2->date();
    int disponibilite=ui->le_id_2->text().toInt();
    Matriels m(id,nom,type,etat,garantie,disponibilite);
    bool test=m.modifier();
    QMessageBox msgbox;
    if(test)
    {
        msgbox.setText("ecehck");
        ui->table_matriels->setModel(m.afficher());
    }
    else
        ui->table_matriels->setModel(m.afficher());
        msgbox.setText("reussi");
        msgbox.exec();
}

void MainWindow::on_modifier_2_clicked()
{
    ui->le_id->clear();
    ui->le_nom->clear();
}

void MainWindow::on_supprimer_clicked()
{
    Matriels m;
    m.setid(ui->le_id_supp->text().toInt());
    bool test=m.supprimer(m.getid());
    QMessageBox msgBox;
     if(!test)
        { msgBox.setText("echec");
       ui->table_matriels->setModel(m.afficher());
     }
     else
         ui->table_matriels->setModel(m.afficher());
         msgBox.setText("supprim avec sucees.");
         msgBox.exec();

}

void MainWindow::on_supprimer_2_clicked()
{
    int id = ui->lineEdit->text().toUInt();
   Matriels m;
    QSqlQuery query = m.rechercher(id);

   if (query.exec() && query.next())
   {
      QStandardItemModel *model = new QStandardItemModel();

       model->setColumnCount(query.record().count());


      ui->table_matriels->setModel(model);


        model->removeRows(0, model->rowCount());


        for (int i = 0; i < query.record().count(); i++)
        {
            model->setHorizontalHeaderItem(i, new QStandardItem(query.record().fieldName(i)));
       }
        do
       {
           QList<QStandardItem*> rowItems;
            for (int col = 0; col < query.record().count(); col++)
            {
                rowItems << new QStandardItem(query.value(col).toString());
            }
           model->appendRow(rowItems);
        } while (query.next());
    }
    else
       ui->table_matriels->setModel(m.afficher());

}

void MainWindow::on_supprimer_3_clicked()
{
    Matriels m;
    QSqlQueryModel *model = m.tri();
    ui->table_matriels->setModel(model);

}

void MainWindow::on_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/mahdi/OneDrive/Desktop/ppp/pdf");
    int i = 4000;
    QPainter painter(&pdf);
    QString strStream;

    QTextStream out(&strStream);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Time New Roman", 25));
    painter.drawText(3000,1400,"Liste Des Matriels");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Time New Roman", 7));
    painter.setPen(Qt::darkCyan);
    painter.drawRect(100,100,9400,2500);
    painter.drawRect(100,3000,9400,500);
    painter.setPen(Qt::black);
    painter.drawText(300,3300," id");
    painter.drawText(1300,3300,"nom");
    painter.drawText(2300,3300,"type");
    painter.drawText(3300,3300,"etat");
    painter.drawText(4300,3300,"garantie");
    painter.drawText(5300,3300,"disponibilite");
    //painter.drawText(6300,3300,"ID_CLIENT");
    painter.setPen(Qt::darkCyan);
    painter.drawRect(100,3000,9400,9000);
    painter.setPen(Qt::black);
    QSqlQuery query;
    query.prepare("select * from APP_MATRIELS");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(1300,i,query.value(1).toString());
        painter.drawText(2300,i,query.value(2).toString());
        painter.drawText(3300,i,query.value(3).toString());
        painter.drawText(4300,i,query.value(4).toString());
        painter.drawText(5300,i,query.value(5).toString());
        painter.drawText(6300,i,query.value(6).toString());

        i +=350;
    }
       // QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
        //QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_suivant_clicked()
{
    Matriels m;
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->table_matriels->setModel(m.afficher());

}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_supprimer_4_clicked()
{
    Matriels m;
    ui->table_matriels->setModel(m.afficher());
}

void MainWindow::on_login_2_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();

    if (username=="admin" && password=="admin")
    {
        QMessageBox::information(this,"login","admin mode");
        //MainWindow *mainwindow =new MainWindow(this);
        //mainwindow->show();
        //Alerte = new alerte(this);
        //Alerte->show();
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_2->setCurrentIndex(0);


    }
    else if (username=="notAdmin" && password=="notAdmin")
    {
        QMessageBox::information(this,"login","not admin mode");

        //Affichage=new affichage(this);
        //Affichage->show();

        //Alerte = new alerte(this);
        //Alerte->show();
    }
    else
    {
        QMessageBox::warning(this,"login","username or password is not correct");
        //Alerte = new alerte(this);
        //Alerte->show();
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    Alerte = new alerte(this);
    Alerte->show();


}

void MainWindow::on_pushButton_19_clicked()
{
    QMessageBox msgBox;
        int id = ui->lineEdit_2->text().toInt();
         Matriels m;
         Arduino A;

        if (m.rechercher_arduino(id))
        {
            //QByteArray data = A.getserial()->readAll();
              //          qDebug() << "Données reçues depuis Arduino :" << data;
            //QByteArray responseData = A.getserial()->readAll();
                       // qDebug() << "Réponse reçue:" << responseData;
            qDebug() << "Réponse reçue:" << A.read_from_arduino();
            int disponibilite=0;

            bool test=m.modifierarduino(disponibilite);
            QMessageBox msgbox;
            if(test)
            {
                msgbox.setText("ecehck");
                ui->table_matriels->setModel(m.afficher());
            }
            else
                ui->table_matriels->setModel(m.afficher());
                msgbox.setText("reussi");
                msgbox.exec();


                    A.write_to_arduino("1");
                    msgBox.setText("*\n bienvenue  \n*");
                    msgBox.exec();

         }
        else {
            msgBox.setText("*\n acces interdit\n*");
            msgBox.exec();
        }

}

void MainWindow::on_suivant_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

/*void MainWindow::on_suivant_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}*/

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_employ_buttom_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_ajouter_2_clicked()
{
    QMessageBox msgBox;

    if (controlSaisie())
    {
        bool ok;
        int id_employe = ui->id_employe->text().toInt(&ok);

        if (ok)
        {
            if (!emp.employeExists(id_employe)) // Vérifie si la pénalité n'existe pas
            {
                 emp.setIdEmploye( id_employe);
                 emp.setNom(ui-> nom->text());
                 emp.setPrenom(ui-> prenom->text());
                 emp.setSexe(ui-> sexe->text());
                 emp.setTelephone(ui-> telephone->text().toInt());
                 emp.setAdresse(ui-> adresse->text());
                 emp.setDepartement(ui-> departement->text());
                 emp.setGrade(ui-> grade->text());
                 emp.setSalaire(ui-> salaire->text().toInt());

                bool test = emp.ADD();

                if (test){
                    msgBox.setText("Ajout réussi.");
                    ui->stackedWidget_3->setCurrentIndex(1);
                    ui->id_employe->clear();
                     ui-> nom->clear();
                     ui-> prenom->clear();
                     ui-> sexe->clear();
                     ui-> telephone->clear();
                     ui-> adresse->clear();
                     ui-> departement->clear();
                     ui-> grade->clear();
                     ui-> salaire->clear();
                }
                else
                {
                    msgBox.setText("!! L'ajout a échoué !!");
                    ui->id_employe->clear();
                     ui-> nom->clear();
                      ui-> prenom->clear();
                     ui-> sexe->clear();
                     ui-> telephone->clear();
                     ui-> adresse->clear();
                     ui-> departement->clear();
                     ui-> grade->clear();
                     ui-> salaire->clear();
                 }
            }
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
            QObject::tr("Please fill all fields.\n !!! There are EMPTY or INCORRECT fields !!!\n"
            "Click cancel to EXIT."), QMessageBox::Cancel);
    }

    ui->table_employe->setModel(emp.GETALL());
    ui->table_employe->setModel(emp.getSortedModel());

    msgBox.exec();
}
bool MainWindow::controlSaisie()
{
    if (ui->id_employe->text().isEmpty() ||
        ui->nom->text().isEmpty() ||
        ui->prenom->text().isEmpty() ||
        ui->sexe->text().isEmpty() ||
        ui->telephone->text().isEmpty() ||
        ui->adresse->text().isEmpty() ||
        ui->departement->text().isEmpty() ||
        ui->grade->text().isEmpty() ||
        ui->salaire->text().isEmpty())
    {
        return false;
    }

    return true;
}

void MainWindow::on_modifier_3_clicked()
{
    QMessageBox msgBox;


    if (controlSaisie())
    {
        bool ok;
        int id_employe = ui->id_employe->text().toInt(&ok);

        if (ok)
        {
            if (emp.employeExists(id_employe))
            {
                 emp.setIdEmploye( id_employe);
                 emp.setNom(ui-> nom->text());
                 emp.setPrenom(ui-> prenom->text());
                 emp.setSexe(ui-> sexe->text());
                 emp.setTelephone(ui-> telephone->text().toInt());
                 emp.setAdresse(ui-> adresse->text());
                 emp.setDepartement(ui-> departement->text());
                 emp.setGrade(ui-> grade->text());
                 emp.setSalaire(ui-> salaire->text().toInt());



                ui->table_employe->setModel(emp.GETALL());

                bool test = emp.UPDATE();

                if (test)
                {
                    msgBox.setText("Modification successful.");
                    ui->stackedWidget_3->setCurrentIndex(1);
                    ui->id_employe->clear();
                     ui-> nom->clear();
                      ui-> prenom->clear();
                     ui-> sexe->clear();
                     ui-> telephone->clear();
                     ui-> adresse->clear();
                     ui-> departement->clear();
                     ui-> grade->clear();
                     ui-> salaire->clear();
                }
                else
                {
                    msgBox.setText("!! Modification failed !!");
                    ui->id_employe->clear();
                     ui-> nom->clear();
                     ui-> sexe->clear();
                     ui-> telephone->clear();
                     ui-> adresse->clear();
                     ui-> departement->clear();
                      ui-> prenom->clear();
                     ui-> grade->clear();
                     ui-> salaire->clear();
                }
            }
            else
            {
                // La penalite n'existe pas, affiche un message indiquant qu'il n'est pas possible de la modifier
                msgBox.setText("employe with numero " + QString::number(id_employe) + " does not exist.\nCannot modify.");
            }
        }
        else
        {

            msgBox.setText("Veuillez entrer un numéro de penalite valide.");
        }
    }
    else
    {

        msgBox.setText("Veuillez remplir tous les champs.");
    }
    msgBox.exec();
    ui->table_employe->setModel(emp.GETALL());
    ui->table_employe->setModel(emp.getSortedModel());
}
void MainWindow::on_table_employe_activated(const QModelIndex &index)
{
    ui->table_employe->setModel(emp.GETALL());
    ui->table_employe->setModel(emp.getSortedModel());


}


void MainWindow::on_suprimer_clicked()
{
    int id_employe = ui->employe_supp->text().toInt();


    QMessageBox msgBox;
    if (emp.employeExists(id_employe))
    {

        bool test = emp.DELETEE(id_employe);


        if (test)
        {
            msgBox.setText("Suppression réussie.");
            ui->table_employe->setModel(emp.GETALL());
        }
        else
        {
            msgBox.setText("!! La suppression a échoué !!");
        }


        msgBox.exec();
    }
    else
    {

        QMessageBox::warning(this, "Employe non trouvée", "L'employe avec l " + QString::number(id_employe) + " n'existe pas.\nImpossible de supprimer.");
    }
}

void MainWindow::on_suivant_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->table_employe->setModel(emp.GETALL());
}

void MainWindow::on_back_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_suivant_4_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_back_4_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->table_employe->setModel(emp.GETALL());
}

void MainWindow::on_exportpdfb_clicked()
{
    int id_employe = ui->ll->text().toInt();
    employe emp;
    emp.writeToPDF(id_employe);
}

void MainWindow::on_stat_clicked()
{
    employe e;
    double malePercentage=0;
    double femalePercentage=0;

    e.stat(&malePercentage,&femalePercentage);
    ui->malelabel->setText(QString::number(malePercentage) + "%");
    ui->femalelabel->setText(QString::number(femalePercentage) + "%");

}

void MainWindow::on_suivant_5_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
}

void MainWindow::on_bac_4_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    static QDate firstDate;

    if (firstDate.isNull()) {
        // C'est la première date sélectionnée
        firstDate = ui->calendarWidget->selectedDate();
    } else {
        // C'est la deuxième date sélectionnée
        QDate secondDate = ui->calendarWidget->selectedDate();

        // Calculez la différence entre les deux dates
        int daysDifference = firstDate.daysTo(secondDate);

        // Vérifiez si la différence est inférieure ou égale à 21
        if (daysDifference <= 21) {
            QMessageBox::information(this, "Congé", "Congé disponible");
        } else {
            QMessageBox::information(this, "Congé", "Congé pas possible");
        }

        // Réinitialisez firstDate pour la prochaine paire de sélections
        firstDate = QDate();

        // Désactivez le QCalendarWidget
        ui->calendarWidget->setEnabled(false);
    }
}

void MainWindow::on_suivant_6_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(4);
}

void MainWindow::on_back_5_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_pushButton_17_clicked()
{
    employe  c;
    smtp* ssmtp = new smtp("wadhah.hmissi@esprit.tn", "221JMT6233", "smtp.gmail.com", 465);

                   connect(ssmtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                   QString email=ui->lll2->text();

                   QString b=ui->lll3->text();

                   QString ob=ui->lll4->text();

                    if(email!="" && b!="" && ob!="" )
                       {
                                     if (c.isValidEmail(email))
                                     {
                                         ssmtp->sendMail("wadhah.hmissi@esprit.tn", email , b,ob);
                                         QMessageBox::information(nullptr, QObject::tr("EMAIL"),
                                         QObject::tr("Email Envoyé avec succees.\n"
                                         "click Cancel to exit"),QMessageBox::Cancel);
                                     }
                                     else
                                     {
                                         QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                                         QObject::tr("Email is wrong in.\n"
                                         "click Cancel to exit."),QMessageBox::Cancel);
                                     }
                       }
                    else
                       {
                               QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                               QObject::tr("something is empty.\n"
                               "click Cancel to exit."),QMessageBox::Cancel);
                       }
}

void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(3);
}
