#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "modify.h"
#include "login.h"
#include "xlsxdocument.h"
#include "xlsxformat.h"
#include "xlsxworksheet.h"
#include "xlsxcellrange.h"
#include<QSortFilterProxyModel>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QtWidgets>
#include <QStyledItemDelegate>

#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlRecord>
#include <QTextDocument>

#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <QTimer>
#include "auditeur.h"
#include "penalite.h"
#include"formations.h"


//#include <QSmtp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(1267,692);

    QIcon icon(":/img/img/logo_app.png");
    this->setWindowIcon(icon);

    connect(ui->actionAbout, &QAction::triggered, [this](){ showPage(0); });

    connect(ui->actionHome, &QAction::triggered, [this](){ showPage(1); });
    connect(ui->actionLoad, &QAction::triggered, [this](){ showPage(1);on_pushButton_clicked();});
    connect(ui->actionAnomalies, &QAction::triggered, [this](){ showPage(1);on_pushButton_7_clicked();  });
    connect(ui->actionStats, &QAction::triggered, [this](){ showPage(1);on_pushButton_6_clicked();});
    connect(ui->actionCr_er_PDF, &QAction::triggered, [this](){ showPage(1);on_PDF_BUT_clicked(); });
    connect(ui->actionCreer_Excel, &QAction::triggered, [this](){ showPage(1);on_pushButton_5_clicked(); });
    connect(ui->actionDonn_es_entreprise, &QAction::triggered, [this](){ showPage(1);on_DATA_ENT_clicked(); });

    QPixmap pixMateriel(":/img/img/icons8-tools-100.png");
    QPixmap pixAudit(":/img/img/dispositifs.png");
    QPixmap pixPen(":/img/img/document.png");
    QPixmap pixForm(":/img/img/apprentissage-en-ligne.png");
    QPixmap pixEmp(":/img/img/employe.png");
    QPixmap pixEntrep(":/img/img/batiment.png");
    QPixmap pixMenu(":/img/img/utilisateurs-alt (2).png");
    QPixmap pixDec(":/img/img/partir.png");
    int height = ui->pbmenu1->height();
    int width = ui->pbmenu1->width();
    ui->pbmenu1->setIcon(pixMateriel.scaled(width,height,Qt::KeepAspectRatio));
    ui->pbmenu2->setIcon(pixAudit.scaled(width,height,Qt::KeepAspectRatio));
    ui->pbmenu3->setIcon(pixPen.scaled(width,height,Qt::KeepAspectRatio));
    ui->pbmenu4->setIcon(pixForm.scaled(width,height,Qt::KeepAspectRatio));
    ui->pbmenu5->setIcon(pixEmp.scaled(width,height,Qt::KeepAspectRatio));
    ui->pbmenu6->setIcon(pixEntrep.scaled(width,height,Qt::KeepAspectRatio));

    ui->label_2->setPixmap(pixMenu.scaled(width,height,Qt::KeepAspectRatio));
    ui->pushButton_14->setIcon(pixDec.scaled(width,height,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
    ui->tableView->setModel(Etemp.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    Modify m;
    m.setModal(true);
    m.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    Entrp c;
    c.generateExcelFile();
}



void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
      QString sortingOption = arg1;
      QSqlQueryModel* model = Etemp.afficher(sortingOption);
      ui->tableView->setModel(model);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    Entrp c;
    QChart* chart = c.LoadStats();

    QChartView* chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
    chartView->resize(600, 500);
    chartView->show();

}

void MainWindow::on_pushButton_9_clicked()
{
    int id= ui->s1->text().toInt();
    bool check=Etemp.CheckId(id);
    bool test=Etemp.supprimer(id);
    if(test && check)
    {
        QMessageBox::information(nullptr,QObject::tr("SUCCESSFULL"),QObject::tr("Suppression effectué\n"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("FAILED"),QObject::tr("Suppression non effectué\n"),QMessageBox::Ok);

    }
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 != 0){
        ui->fitler->hide();
        ui->recherche->hide();
        ui->comboBox->hide();
        ui->RECHERCHE->hide();
    }
    else
    {
        ui->fitler->show();
        ui->recherche->show();
        ui->comboBox->show();
        ui->RECHERCHE->show();

    }
}



void MainWindow::on_bout_ajout_clicked()
{
    int id = ui->IDLE->text().toInt();
    QString DS = ui->DSLE->text();
    QString DC = ui->DCLE->text();
    QString SECT = ui->SECTLE->text();
    QString SSECT = ui->SSECTLE->text();
    QString PAYS = ui->PAYSLE->text();
    double capital = ui->CAPLE->text().toDouble();
    int effectif = ui->EFFLE->text().toInt();
    double chaffaire = ui->CHAFFLE->text().toDouble();

    Entrp C(id, DC, DC, PAYS,SECT,SSECT ,effectif,capital, chaffaire);

    if (!C.CheckId(id)) {
        bool test = C.ajouter();

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("SUCCESSFUL"), QObject::tr("Ajout effectué\n"), QMessageBox::Ok);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("FAILED"), QObject::tr("Ajout non effectué\n"), QMessageBox::Ok);
        }
    } else {
         ui->DSLE->clear();
         ui->DCLE->clear();
         ui->PAYSLE->clear();
         ui->SECTLE->clear();
         ui->SSECTLE->clear();
         ui->CAPLE->clear();
         ui->EFFLE->clear();
         ui->CHAFFLE->clear();
        // Clear other line edits
        QMessageBox::critical(nullptr, QObject::tr("IMPOSSIBLE"), QObject::tr("ID already exists\n"), QMessageBox::Ok);
    }
}


void MainWindow::on_s1_textChanged(const QString &arg1)
{
    int companyId = arg1.toInt(); // Get the ID from the QLineEdit

    QSqlQuery query;
    query.prepare("SELECT DS, DC, DIRIGEANT, ADRESSE, CP, PAYS, GOUVERNORAT, VILLE, TELEPHONE, FAX, EMAIL, SECTEUR, SOUSSECT, DIVISION, CAPITAL, EFFECTIF, CHAFFAIRE, SITEWEB FROM BDTUN WHERE ID = :id");
    query.bindValue(":id", companyId);

    if (query.exec() && query.next()) {
        ui->DSLE_2->setText(query.value(0).toString());
        ui->DCLE_2->setText(query.value(1).toString());
        ui->DIRLE_2->setText(query.value(2).toString());
        ui->ADRESSELE_2->setText(query.value(3).toString());
        ui->CPLE_2->setText(query.value(4).toString());
        ui->PAYSLE_2->setText(query.value(5).toString());
        ui->GVTLE_2->setText(query.value(6).toString());
        ui->VILLELE_2->setText(query.value(7).toString());
        ui->TLPHLE_2->setText(query.value(8).toString());
        ui->FAXLE_2->setText(query.value(9).toString());
        ui->EMAILLE_2->setText(query.value(10).toString());
        ui->SECTLE_2->setText(query.value(11).toString());
        ui->SSECTLE_2->setText(query.value(12).toString());
        ui->DIVLE_2->setText(query.value(13).toString());
        ui->CAPLE_2->setText(query.value(14).toString());
        ui->EFFLE_2->setText(query.value(15).toString());
        ui->CHAFFLE_2->setText(query.value(16).toString());
        ui->SITELE_2->setText(query.value(17).toString());
    }else
    {
        ui->DSLE_2->setText("");
           ui->DCLE_2->setText("");
           ui->DIRLE_2->setText("");
           ui->ADRESSELE_2->setText("");
           ui->CPLE_2->setText("");
           ui->PAYSLE_2->setText("");
           ui->GVTLE_2->setText("");
           ui->VILLELE_2->setText("");
           ui->TLPHLE_2->setText("");
           ui->FAXLE_2->setText("");
           ui->EMAILLE_2->setText("");
           ui->SECTLE_2->setText("");
           ui->SSECTLE_2->setText("");
           ui->DIVLE_2->setText("");
           ui->CAPLE_2->setText("");
           ui->EFFLE_2->setText("");
           ui->CHAFFLE_2->setText("");
           ui->SITELE_2->setText("");

    }
}

void MainWindow::on_pushButton_7_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);

    QSqlQueryModel* model = Etemp.afficher_AN();

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, "Company ID");
    model->setHeaderData(1, Qt::Horizontal, "Company Name");
    model->setHeaderData(2, Qt::Horizontal, "Penalty Amount");
    model->setHeaderData(3, Qt::Horizontal, "Date Issued");
    model->setHeaderData(4, Qt::Horizontal, "Due Date");

    DateDelegate* dateDelegate = new DateDelegate(ui->tableView_AN);
    ui->tableView_AN->setItemDelegateForColumn(4, dateDelegate);

    ui->tableView_AN->setModel(model);

}


void MainWindow::on_PDF_BUT_clicked()
{ // Open a file dialog to choose the destination for the PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", QDir::homePath(), "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;  // User canceled the save operation
    }

    // Create a PDF writer
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));

    // Create a painter to draw on the PDF
    QPainter painter(&pdfWriter);

    // Set up the font and other painter settings
    QFont font;
    font.setPointSize(60);
    painter.setFont(font);

    //int rowHeight = 70;
    int spaceBetweenCompanies = 20;
    int companiesPerPage = 5;

    // Fetch all data from the BDTUN table
    QSqlQuery query("SELECT * FROM BDTUN");
    QSqlRecord record = query.record();

    // Create a QTextDocument for each page
    QTextDocument textDocument;

    // Iterate over the query result and build an HTML string
    QString html;
    html += "<html><body style='font-size: 60pt;'>"; // Set font size directly in HTML

    int rowCount = 0;

    while (query.next()) {
        html += "<div style='margin-bottom: " + QString::number(spaceBetweenCompanies) + "px;'>";

        // Display each line of data horizontally
        for (int col = 0; col < record.count(); ++col) {
            html += "<p><strong>" + record.fieldName(col) + ":</strong> " +
                    query.value(col).toString() + "</p>";
        }

        html += "</div>";

        rowCount++;

        // Break to a new page after displaying information for 'companiesPerPage' companies
        if (rowCount % companiesPerPage == 0) {
            html += "</body></html>";
            textDocument.setHtml(html);

            // Draw the QTextDocument onto the PDF
            textDocument.drawContents(&painter);

            // Start a new page
            pdfWriter.newPage();

            html = "<html><body style='font-size: 60pt;'>"; // Set font size directly in HTML
        }
    }

    // Close the last row if it's not already closed
    if (rowCount % companiesPerPage != 0) {
        html += "</body></html>";
        textDocument.setHtml(html);

        // Draw the QTextDocument onto the last page
        textDocument.drawContents(&painter);
    }

    // Inform the user that the PDF has been created
    QMessageBox::information(this, "PDF Created", "PDF file has been created successfully.");
}








void MainWindow::on_DATA_ENT_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);

    QSqlQueryModel* model = Etemp.afficher_DATA();


    ui->tableView_DATA->setModel(model);
}

void MainWindow::on_IMPORT_clicked()
{

    // Assume pdfId is the ID of the row you want to download
    int pdfId = getSelectedPDFId();  // Implement this function to get the selected PDF ID
    if(pdfId==0)
    {}
    else
    {
    // Fetch the PDF content from the database based on the PDF ID
    QByteArray pdfContent = Etemp.fetchPDFContentFromDatabase(pdfId);

    // Use QFileDialog to let the user choose a location to save the PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");

    if (!filePath.isEmpty()) {
        // Save the PDF content to the chosen file location
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(pdfContent);
            file.close();
            // Optionally, inform the user that the download was successful
            QMessageBox::information(this, "Download Successful", "PDF downloaded successfully.");
        } else {
            // Handle file write error
            QMessageBox::warning(this, "Error", "Failed to save the PDF.");
        }
    }
    }
}

void MainWindow::on_EXPORT_clicked()
{

    int pdfId = getSelectedPDFId();  // Implement this function to get the selected PDF ID
    if(pdfId ==0)
    {}
    else{
    QString filePath = QFileDialog::getOpenFileName(this, "Choose PDF", "", "PDF Files (*.pdf)");

    if (!filePath.isEmpty()) {
        // Read the content of the chosen file
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray pdfContent = file.readAll();
            file.close();

            // Assume pdfId is the ID where you want to export the PDF

            // Execute SQL query to update the PDF_CONTENT column in the database
            bool success = Etemp.exportPDFToDatabase(pdfId, pdfContent);

            if (success) {
                // Optionally, inform the user that the export was successful
                QMessageBox::information(this, "Export Successful", "PDF exported successfully.");
            } else {
                // Handle export error
                QMessageBox::warning(this, "Error", "Failed to export the PDF.");
            }}
        } else {
            // Handle file read error
            QMessageBox::warning(this, "Error", "Failed to read the PDF file.");
        }
    }
}

void MainWindow::on_ERASE_clicked()
{
    // Assume pdfId is the ID of the row you want to delete
    int pdfId = getSelectedPDFId();  // Implement this function to get the selected PDF ID
    if(pdfId ==0)
    {}
    else{
    // Execute SQL query to delete the row from the database
    bool success = Etemp.deletePDFFromDatabase(pdfId);

    if (success) {
        // Optionally, inform the user that the deletion was successful
        QMessageBox::information(this, "Deletion Successful", "PDF deleted successfully.");
    } else {
        // Handle deletion error
        QMessageBox::warning(this, "Error", "Failed to delete the PDF.");
    } }
}

int MainWindow::getSelectedPDFId() {

   int id=ui->ID_DATA->text().toInt();
   bool x= Etemp.CheckId(id);
   if(x)
   {
       return id;
   }
   else
   {
       QMessageBox::warning(this, "Error", "Selected ID non existent");
       return 0;
   }
}

void MainWindow::on_RECHERCHE_textChanged(const QString &arg1)
{
    QString sortingOption = ui->comboBox->currentText(); // Get the current sorting option from the combo box.
    QSqlQueryModel* model = Etemp.afficher(sortingOption, arg1); // Call the afficher function with sorting and filter parameters.
    ui->tableView->setModel(model); // Set the model to the table view to update the displayed data.
}

void MainWindow::on_pbmenu6_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pbmenu1_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);

}

void MainWindow::on_pbmenu2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(8);
    ui->table_auditeur->setModel(aud.GETALL());


}

void MainWindow::on_pbmenu3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(7);

}

void MainWindow::on_pbmenu4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
    ui->stackedWidget_4->setCurrentIndex(1);



}

void MainWindow::on_pbmenu5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
    ui->stackedWidget_3->setCurrentIndex(0);


}

void MainWindow::showPage(int n) {
    ui->stackedWidget_2->setCurrentIndex(n);  // Assuming the "About" page is at index 0
}





void MainWindow::showPageEntrep(int n) {
    ui->stackedWidget->setCurrentIndex(n);  // Assuming the "About" page is at index 0
}









// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK
// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK


// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK
// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK


// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK
// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK


// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK
// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK// IHEB WORK











bool MainWindow::controlSaisie_ayoub()
{
    if (ui->numero_penalite->text().isEmpty() ||
        ui->date_penalite->text().isEmpty() ||
        ui->montant->text().isEmpty() ||
        ui->nature->currentText().isEmpty() ||
        ui->id_auditeur->text().isEmpty() ||
        ui->notes->text().isEmpty())
    {
        return false;
    }

    return true;
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



void MainWindow::on_pushButton_16_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{



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


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
    ui->stackedWidget_3->setCurrentIndex(3);
}







void MainWindow::on_nouraffichertableau_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);

    formations formationsObj;
    QSqlQueryModel *model = formationsObj.GETALL();
    if (model)
        {

            ui->tableView_2->setModel(model);
    }
    else
    {

        qDebug() << "Error in SQL Query: " << model->lastError().text();
    }

}




/*void MainWindow::on_nourbouttsupp_clicked()
{
    QString idFormateurASupprimer = ui->lineEditIDFormateur->text();

    // Vérifier si la formation avec l'ID spécifié existe
    formations formationExistante;
    QSqlQueryModel *modelExist = formationExistante.GETALL();
    bool formationExiste = false;
    for (int row = 0; row < modelExist->rowCount(); ++row) {
        if (modelExist->data(modelExist->index(row, 0)) == idFormateurASupprimer) {
            formationExiste = true;
            break;
        }
    }

    if (!formationExiste) {
        QMessageBox::critical(this, "Erreur de suppression", "La formation avec l'ID spécifié n'existe pas.");
        return;
    }

    // Supprimer la formation uniquement si elle existe
    QSqlQuery query;
    QString requeteSuppression = "DELETE FROM formations WHERE ID_FORMATEUR = " + idFormateurASupprimer;

    if (query.exec(requeteSuppression))
    {
        qDebug() << "Suppression réussie.";
    }
    else
    {
        qDebug() << "Échec de la suppression : " << query.lastError().text();
    }

    // Mettre à jour la vue
    formations formationsObj;
    QSqlQueryModel *model = formationsObj.GETALL();
    if (model)
    {
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
    }
}



*/




void MainWindow::on_nourajouterfor_clicked()
{
    QMessageBox msgBox;
    //ui->stackedWidget->setCurrentIndex(1);


    int num_form = ui->lineEditNumForm->text().toInt();
    QString type_form = ui->lineEditTypeForm->text();
    QDate date_form = ui->dateEditDateForm->date();
    int id_form = ui->lineEditIdForm->text().toInt();
    QString niv_stag = ui->lineEditNivStag->text();


    formations nouvelleFormation(num_form, type_form, date_form, id_form, niv_stag);
    if (nouvelleFormation.ControlSaisie()){


    bool ajoutReussi = nouvelleFormation.ADD();

    if (ajoutReussi) {
        QMessageBox::information(nullptr, "Ajout Success", " ajout reussi.");
    } else {
        QMessageBox::critical(nullptr, "Echec d'ajout ", "verifier vos donnes.");
    }
    }
    else{

        QMessageBox::critical(nullptr, "Echec d'ajout ", "verifier vos donnes..");

    }

        ui->stackedWidget_4->setCurrentIndex(0);

        formations formationsObj;
        QSqlQueryModel *model = formationsObj.GETALL();
        if (model)
            {
                // Assign the model to the QTableView
                ui->tableView->setModel(model);
        }
        else
        {

            qDebug() << "Error in SQL Query: " << model->lastError().text();
        }



}





void MainWindow::on_nourmodifierfor_clicked()
{
    QMessageBox msgBox;

    // Récupérer les valeurs depuis les LineEdits
    int num_form = ui->LNUMF->text().toInt();
    QString type_form = ui->LTYPEF->text();
    QDate date_form = ui->LDATEF->date();
    int id_form = ui->LID->text().toInt();
    QString niv_stag = ui->LNIVSTG->text();

    // Vérifier la validité des champs
    if (num_form <= 0) {
        msgBox.critical(this, "Erreur de modification", "Numéro de formation invalide.");
        return;
    }

    if (type_form.isEmpty()) {
        msgBox.critical(this, "Erreur de modification", "Type de formation ne peut pas être vide.");
        return;
    }

    // Vérifier si la formation avec l'ID spécifié existe
    formations formationExistante;
    QSqlQueryModel *modelExist = formationExistante.GETALL();
    bool formationExiste = false;
    for (int row = 0; row < modelExist->rowCount(); ++row) {
        if (modelExist->data(modelExist->index(row, 0)).toInt() == id_form) {
            formationExiste = true;
            break;
        }
    }

    if (!formationExiste) {
        msgBox.critical(this, "Erreur de modification", "La formation avec l'ID spécifié n'existe pas.");
        return;
    }

    // Créer une instance de formations
    formations nouvelleFormation(num_form, type_form, date_form, id_form, niv_stag);

    // Effectuer la modification uniquement si la saisie est valide
    if (nouvelleFormation.ControlSaisie()) {
        // Modifier la ligne dans votre tableau Oracle
        bool modificationReussie = nouvelleFormation.UPDATE();

        if (modificationReussie) {
            msgBox.information(this, "Modification réussie", "La formation a été modifiée avec succès.");
        } else {
            msgBox.critical(this, "Échec de modification", "Échec de la modification de la formation.");
        }
    } else {
        msgBox.critical(this, "Erreur de saisie", "Veuillez remplir tous les champs requis.");
    }

    // Recharger les données dans le QTableView
    ui->stackedWidget_4->setCurrentIndex(0);
    formations formationsObj;
    QSqlQueryModel *model = formationsObj.GETALL();
    if (model) {
        ui->tableView->setModel(model);
    } else {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
    }
}







void MainWindow::on_nourchangerpage2a1_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);

}




// Dans mainwindow.cpp
void MainWindow::on_nourtriacsendant_clicked()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM formations ORDER BY NIVEAU_STAGIAIRE ASC"))
    {

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << "Erreur lors du tri ascendant : " << query.lastError().text();
    }
}

void MainWindow::on_nourtridecendant_clicked()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM formations ORDER BY NIVEAU_STAGIAIRE DESC"))
    {
        // Mettez à jour le modèle de la vue avec le résultat du tri
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << "Erreur lors du tri descendant : " << query.lastError().text();
    }
}



/*// Dans mainwindow.cpp
void MainWindow::on_statistiqueButton_clicked()
{
    // Effectuer une requête SQL pour obtenir les statistiques
    QSqlQuery query;
    if (query.exec("SELECT NIVEAU_STAGIAIRE, COUNT(*) FROM formations GROUP BY NIVEAU_STAGIAIRE"))
    {
        QString statistiques;
        while (query.next())
        {
            QString niveau = query.value(0).toString();
            int count = query.value(1).toInt();
            statistiques += QString("Niveau %1 : %2 formations\n").arg(niveau).arg(count);
        }

        // Afficher les statistiques dans une boîte de message
        QMessageBox::information(this, "Statistiques des niveaux des stagiaires", statistiques);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des statistiques : " << query.lastError().text();
    }
}*/
void MainWindow::afficherGraphiqueCirculaire(QMap<QString, int> statistiques)
{
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QtCharts::QPieSlice *slice = series->append(it.key(), it.value());
        slice->setExploded();
        slice->setLabel(QString("%1: %2 formations").arg(it.key()).arg(it.value()));
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des niveaux des stagiaires");

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(700, 500);


    chartView->show();
}
void MainWindow::on_nourstatistiqueButton_clicked()
{

    QSqlQuery query;
    if (query.exec("SELECT NIVEAU_STAGIAIRE, COUNT(*) FROM formations GROUP BY NIVEAU_STAGIAIRE"))
    {
        QMap<QString, int> statistiques;
        while (query.next())
        {
            QString niveau = query.value(0).toString();
            int count = query.value(1).toInt();
            statistiques.insert(niveau, count);
        }


        afficherGraphiqueCirculaire(statistiques);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des statistiques : " << query.lastError().text();
    }


}





void MainWindow::on_nourpdf_clicked()
{


        QSqlQuery query;
        query.prepare("SELECT * FROM formations");


        if (query.exec())
        {

            QPdfWriter pdfWriter("reportnour.pdf");
            QPainter painter(&pdfWriter);

            QTextDocument doc;

            QString report = "<p style='font-size:250pt;'>Rapport général sur les formations :</p>";

            int totalFormations = 0;


            while (query.next())
            {

                totalFormations++;


                QString typeFormation = query.value("TYPE_FORMATION").toString();
                report += "<p style='font-size:200pt;'><strong>Type de formation :</strong> " + typeFormation + "</p>";
            }


            report += "<p style='font-size:200pt;'><strong>Nombre total de formations :</strong> " + QString::number(totalFormations) + "</p>";


            doc.setHtml(report);


            doc.drawContents(&painter);
        }
        else
        {

            qDebug() << "Erreur lors de la génération du rapport : " << query.lastError();
        }
    }




void MainWindow::on_nourabsenceformateurs_clicked()
{
      ui->stackedWidget_4->setCurrentIndex(0);
        formations formationsObj;
        QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery("SELECT ID_FORMATEUR FROM formations WHERE NIVEAU_STAGIAIRE IS NULL ");


        if (model)
        {

            ui->tableView->setModel(model);


        }
        else
        {
            qDebug() << "Erreur dans la requête SQL : " << model->lastError().text();
        }


    }










void MainWindow::on_nourpushButtonDatesFormations_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT DATE_FORMATION FROM formations ");

    if (model->lastError().isValid())
    {
        qDebug() << "Erreur lors de la récupération des dates de formations : " << model->lastError().text();
    }
    else
    {

        ui->tableViewDatesFormations->setModel(model);


        ui->stackedWidget_4->setCurrentIndex(1);
    }
}

void MainWindow::on_nourchangerpage3a2_clicked()
{
     ui->stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString query = "SELECT * FROM FORMATIONS ";
    query += "WHERE ID_FORMATEUR LIKE '%"+arg1+"%' ";
    model->setQuery(query);

    if (model->lastError().isValid())
    {
        qDebug() << "Erreur lors de la récupération des dates de formations : " << model->lastError().text();
    }
    else
    {
        ui->tableView->setModel(model);

    }
}



void MainWindow::on_nourclear1_clicked()
{
    // Effacer le contenu des champs
    ui->lineEditNumForm->clear();
    ui->lineEditTypeForm->clear();
   // ui->dateEditDateForm->setDate(QDate::currentDate()); // Réinitialiser la date à la date actuelle
    ui->lineEditIdForm->clear();
    ui->lineEditNivStag->clear();




    // Vous pouvez ajouter d'autres champs à effacer ici selon vos besoins
}


void MainWindow::on_nourclear2_clicked()
{
    ui->LNUMF->clear();
    ui->LTYPEF->clear();
    //  ui->LDATEF->clear();

    // ui->dateEditDateForm->setDate(QDate::currentDate()); // Réinitialiser la date à la date actuelle
    ui->LNIVSTG->clear();
    ui->LID->clear();
}


void MainWindow::on_nouraffichermoyenne_clicked()
{
    // Récupérer les données nécessaires de la base de données
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT NIVEAU_STAGIAIRE FROM formations");

    if (model->lastError().isValid())
    {
        qDebug() << "Erreur lors de la récupération des niveaux des stagiaires : " << model->lastError().text();
        return;
    }

    // Initialiser les variables pour le calcul de la moyenne
    int totalStagiaires = model->rowCount();
    int totalPoints = 0;

    // Parcourir les données pour calculer la somme des points
    for (int row = 0; row < totalStagiaires; ++row)
    {
        QString niveau = model->data(model->index(row, 0)).toString();

        // Ajouter les points correspondants au niveau
        if (niveau == "a")
            totalPoints += 20;
        else if (niveau == "b")
            totalPoints += 15;
        else if (niveau == "c")
            totalPoints += 10;
        else if (niveau == "d")
            totalPoints += 5;
    }

    // Calculer la moyenne
    double nouraffichermoyenne = static_cast<double>(totalPoints) / totalStagiaires;

    // Afficher la moyenne
    QMessageBox::information(this, "Moyenne des niveaux des stagiaires", QString("La moyenne est : %1").arg(nouraffichermoyenne));
}



int MainWindow::calculerNombreEtoiles(const QString& niveau)
{
    int points = 0;

    // Ajoutez votre logique pour attribuer des points en fonction du niveau
    // Par exemple, si le niveau est "A", attribuez 20 points, etc.

    if (niveau == "A") {
        points = 20;
    } else if (niveau == "B") {
        points = 15;
    } else if (niveau == "C") {
        points = 10;
    } else if (niveau == "D") {
        points = 5;
    }

    return points;
}




void MainWindow::on_etoile_clicked() {
     formations formationsObj;
    // Obtenez le modèle
    QSqlQueryModel *model = formationsObj.GETALL();

    // Vérifiez si le modèle est valide
    if (model && model->columnCount() > 0) {
        int rowCount = model->rowCount();

        // Vérifiez s'il y a des données à traiter
        if (rowCount > 0) {
            int totalPoints = 0;

            // Obtenez l'index de la colonne "NIVEAU_STAGIAIRE" en utilisant roleNames()
            int niveauColumnIndex = model->roleNames().key("NIVEAU_STAGIAIRE");

            // Parcourez toutes les lignes du modèle
            for (int row = 0; row < rowCount; ++row) {
                // Obtenez la valeur de la colonne "NIVEAU_STAGIAIRE" à l'aide de data()
                QString niveau = model->data(model->index(row, niveauColumnIndex)).toString();

                qDebug() << "Niveau pour la ligne " << row << " : " << niveau;

                int points = calculerNombreEtoiles(niveau);

                // Ajoutez les points au total
                totalPoints += points;
            }

            // Calculez la moyenne de la classe
            double moyenneClasse = static_cast<double>(totalPoints) / rowCount;

            qDebug() << "Moyenne de la classe : " << moyenneClasse;

            // ... (restez avec le reste de votre code)

        } else {
            QMessageBox::warning(this, "Aucune donnée", "Aucune donnée à traiter.");
        }
    } else {
        qDebug() << "Erreur dans la requête SQL ou modèle invalide.";
    }
}








    void MainWindow::on_pushButtonAfficherPhoto_clicked()
    {
            // Récupérer les données nécessaires de la base de données
            QSqlQueryModel* model = new QSqlQueryModel();
            model->setQuery("SELECT NIVEAU_STAGIAIRE FROM formations");

            // Si la récupération des niveaux des stagiaires échoue, afficher un message d'erreur et retourner
            if (model->lastError().isValid())
            {
                qDebug() << "Erreur lors de la récupération des niveaux des stagiaires : " << model->lastError().text();
                QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des niveaux des stagiaires.");
                return;
            }

            // Initialiser les variables pour le calcul de la moyenne
            int totalStagiaires = model->rowCount();
            int totalPoints = 0;

            // Parcourir les données pour calculer la somme des points
            for (int row = 0; row < totalStagiaires; ++row)
            {
                QString niveau = model->data(model->index(row, 0)).toString();

                // Ajouter les points correspondants au niveau
                if (niveau == "a")
                    totalPoints += 20;
                else if (niveau == "b")
                    totalPoints += 15;
                else if (niveau == "c")
                    totalPoints += 10;
                else if (niveau == "d")
                    totalPoints += 5;
            }

            // Calculer la moyenne
            double nouraffichermoyenne = 0.0;

            // Si le nombre total de stagiaires est différent de zéro, calculer la moyenne
            if (totalStagiaires != 0)
            {
                nouraffichermoyenne = static_cast<double>(totalPoints) / totalStagiaires;

                // Spécifiez les chemins complets des fichiers pour chaque cas
                QString cheminPhoto;

                if (nouraffichermoyenne > 15.0) {
                    cheminPhoto = "C:/Users/melek/Desktop/3et";
                } else if (nouraffichermoyenne >= 10.0 && nouraffichermoyenne <= 15.0) {
                    cheminPhoto = "C:/Users/melek/Desktop/2et";
                } else {
                    cheminPhoto = "C:/Users/melek/Desktop/1et";
                }

                // Chargez l'image et affichez-la dans le QLabel
                QPixmap image(cheminPhoto);

                if (!image.isNull()) {
                    // Redimensionnez l'image si nécessaire (facultatif)

                    //image = image.scaled(ui->labelPhoto->size(), Qt::KeepAspectRatio);
                    int labelWidth = ui->labelPhoto->width();
                           image = image.scaledToWidth(labelWidth, Qt::SmoothTransformation);

                    // Affichez l'image dans le QLabel
                    ui->labelPhoto->setPixmap(image);
                    ui->labelPhoto->setScaledContents(true);
                } else {
                    // Affichez un avertissement si le chargement de l'image échoue
                    QMessageBox::warning(this, "Erreur", "Impossible de charger l'image.");
                }
            }
            else
            {
                qDebug() << "Aucun stagiaire trouvé pour calculer la moyenne.";
                QMessageBox::warning(this, "Avertissement", "Aucun stagiaire trouvé pour calculer la moyenne.");
            }

            // Afficher la moyenne
            QMessageBox::information(this, "Moyenne des niveaux des stagiaires", QString("La moyenne est : %1").arg(nouraffichermoyenne));
        }





void MainWindow::on_pushButton_2000_clicked()
{
      ui->stackedWidget_4->setCurrentIndex(1);
}






void MainWindow::on_nourbouttsupp_clicked()
{

    QString idFormateurASupprimer = ui->lineEditIDFormateur->text();

    // Vérifier si la formation avec l'ID spécifié existe
    formations formationExistante;
    QSqlQueryModel *modelExist = formationExistante.GETALL();
    bool formationExiste = false;
    for (int row = 0; row < modelExist->rowCount(); ++row) {
        if (modelExist->data(modelExist->index(row, 0)) == idFormateurASupprimer) {
            formationExiste = true;
            break;
        }
    }

    if (!formationExiste) {
        QMessageBox::critical(this, "Erreur de suppression", "La formation avec l'ID spécifié n'existe pas.");
        return;
    }

    // Supprimer la formation uniquement si elle existe
    QSqlQuery query;
    QString requeteSuppression = "DELETE FROM formations WHERE ID_FORMATEUR = " + idFormateurASupprimer;

    if (query.exec(requeteSuppression))
    {
        qDebug() << "Suppression réussie.";
    }
    else
    {
        qDebug() << "Échec de la suppression : " << query.lastError().text();
    }

    // Mettre à jour la vue
    formations formationsObj;
    QSqlQueryModel *model = formationsObj.GETALL();
    if (model)
    {
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
}
}

//Ayoub

void MainWindow::on_pushButton_10_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(6);
   ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_ajouter_ayoub_clicked()
{
    QMessageBox msgBox;

    if (controlSaisie_ayoub())
    {
        bool ok;
        int numero_penalite = ui->numero_penalite->text().toInt(&ok);
        if (ok)
        {
            if (!pen.penaliteExists(numero_penalite)) // Vérifie si la pénalité n'existe pas
            {
                pen.set_numero_penalite(numero_penalite);
                pen.set_date_penalite(ui->date_penalite->date());
                pen.set_id_auditeur(ui->id_auditeur->text().toInt());
                pen.set_nature(ui->nature->currentText());
                pen.set_montant(ui->montant->text().toDouble());
                pen.set_notes(ui->notes->text());
                bool test = pen.ADD();
                if (test){
                    msgBox.setText("Ajout réussi.");
                    ui->stackedWidget_5->setCurrentIndex(1); // Redirige vers la deuxième page
                }
                else
                    msgBox.setText("!! L'ajout a échoué !!");
            }
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
            QObject::tr("Please fill all fields.\n !!! There are EMPTY or INCORRECT fields !!!\n"
            "Click cancel to EXIT."), QMessageBox::Cancel);
    }

    ui->table_penaliter->setModel(pen.GETALL());

    msgBox.exec();
}

void MainWindow::on_modifier_ayoub_clicked()
{
    // Crée une boîte de message pour afficher des messages à l'utilisateur
    QMessageBox msgBox;

    // Vérifie la validité des saisies à l'aide de la fonction controlSaisie()
    if (controlSaisie_ayoub())
    {
        // Convertit la QString en int
        bool ok;
        int numero_penalite = ui->numero_penalite->text().toInt(&ok);

        // Vérifie si la conversion a réussi
        if (ok)
        {
            // Vérifie si la penalite avec le numero spécifié existe
            if (pen.penaliteExists(numero_penalite))
            {
                // L'auditeur existe, procède à la modification

                // Récupère les données saisies dans l'interface et les attribue à un objet penalite (pen)
                pen.set_numero_penalite(numero_penalite);
                pen.set_date_penalite(ui->date_penalite->date());  // Utilisez la méthode date() pour récupérer la date
                pen.set_id_auditeur(ui->id_auditeur->text().toInt());
                pen.set_nature(ui->nature->currentText());
                pen.set_montant(ui->montant->text().toDouble());
                pen.set_notes(ui->notes->text());

                // Met à jour l'affichage dans une table (ui->table_penaliter) avec toutes les données des penalites
                ui->table_penaliter->setModel(pen.GETALL());

                // Tente de mettre à jour les données de la penalite en appelant la méthode UPDATE() de l'objet penalite
                bool test = pen.UPDATE();

                // Affiche un message indiquant si la modification a réussi ou échoué
                if (test)
                {
                    msgBox.setText("Modification successful.");
                    ui->stackedWidget_5->setCurrentIndex(1);
                }
                else
                {
                    msgBox.setText("!! Modification failed !!");
                }
            }
            else
            {
                // La penalite n'existe pas, affiche un message indiquant qu'il n'est pas possible de la modifier
                msgBox.setText("Penalite with numero " + QString::number(numero_penalite) + " does not exist.\nCannot modify.");
            }
        }
        else
        {
            // Affiche un message d'erreur si les saisies ne sont pas valides
            msgBox.setText("Veuillez entrer un numéro de penalite valide.");
        }
    }
    else
    {
        // Affiche un message d'erreur si les saisies ne sont pas valides
        msgBox.setText("Veuillez remplir tous les champs.");
    }

    // Affiche la boîte de message
    msgBox.exec();

    // Met à jour l'affichage dans une table (ui->table_penaliter) avec toutes les données des penalites
    ui->table_penaliter->setModel(pen.GETALL());
}

void MainWindow::on_supprimer_ayoub_clicked()
{
    // Récupère le numéro de la pénalité à supprimer à partir de l'interface
    int numero_penalite = ui->num_penalite_supp->text().toInt();

    // Crée une boîte de message pour afficher des messages à l'utilisateur
    QMessageBox msgBox;

    // Vérifie si la pénalité avec le numéro spécifié existe
    if (pen.penaliteExists(numero_penalite))
    {
        bool test = pen.DELETEE(numero_penalite);
        if (test)
        {
            msgBox.setText("Suppression réussie.");
            ui->table_penaliter->setModel(pen.GETALL());
        }
        else
        {
            msgBox.setText("!! La suppression a échoué !!");
        }

        // Affiche la boîte de message
        msgBox.exec();
    }
    else
    {
        // La pénalité n'existe pas, affiche un message indiquant qu'il n'est pas possible de la supprimer
        QMessageBox::warning(this, "Pénalité non trouvée", "La pénalité avec le numéro " + QString::number(numero_penalite) + " n'existe pas.\nImpossible de supprimer.");
    }
}

void MainWindow::on_back_ayoub_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_suivant_1_ayoub_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
    ui->table_penaliter->setModel(pen.GETALL());
}


void MainWindow::on_PDF_ayoub_clicked()
{
    int numero_penalite = ui->pdf_numero->text().toInt();

            pen.writeToPDF(numero_penalite);

}
void MainWindow::afficherGraphiqueCirculaire_2(QMap<QString, int> statistiques)
{
    QPieSeries *series = new QPieSeries();

    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setLabelVisible();
        slice->setLabel(QString("%1: %2 formations").arg(it.key()).arg(it.value()));
    }

    // Ajouter une annotation pour la partie "Amendes" avec une couleur spécifique
    QPieSlice *amendesSlice = series->slices().at(0);  // Remplacez 0 par l'index de la partie "Amendes"
    amendesSlice->setExploded();
    amendesSlice->setLabelVisible();
    amendesSlice->setLabel("Amendes");
    amendesSlice->setBrush(QColor("#f37b78"));  // Couleur spécifique pour "Amendes"

    // Ajouter une annotation pour la partie "Sursi" avec une couleur spécifique
    QPieSlice *sursiSlice = series->slices().at(1);  // Remplacez 1 par l'index de la partie "Sursi"
    sursiSlice->setExploded();
    sursiSlice->setLabelVisible();
    sursiSlice->setLabel("Sursi");
    sursiSlice->setBrush(QColor("#663333"));  // Couleur spécifique pour "Sursi"

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques ");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajuster la taille de la fenêtre du graphique circulaire
    chartView->resize(800, 600);  // Ajustez les dimensions selon vos besoins

    // Afficher la fenêtre du graphique circulaire
    chartView->show();
}


void MainWindow::on_STAT_clicked()
{
    QSqlQuery query;
    if (query.exec("SELECT nature, COUNT(*) FROM penaliter GROUP BY nature"))
    {
        QMap<QString, int> statistiques;
        while (query.next())
        {
            QString nature = query.value(0).toString();
            int count = query.value(1).toInt();
            statistiques.insert(nature, count);
        }


        afficherGraphiqueCirculaire_2(statistiques);
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des statistiques : " << query.lastError().text();
    }
}

void MainWindow::on_ASC_clicked()
{
    QString currentCriteria = ui->triebox->currentText();
    qDebug() << "Critère de tri : " << currentCriteria;

    if(currentCriteria != "Choisir") {
        QSqlQueryModel* modeleTriee = pen.trie("ASC", currentCriteria);
        qDebug() << "Nombre de lignes dans le modèle trié : " << modeleTriee->rowCount();
        ui->table_penaliter->setModel(modeleTriee);
    } else {
        QSqlQueryModel* modeleNonTrie = pen.GETALL();
        qDebug() << "Nombre de lignes dans le modèle non trié : " << modeleNonTrie->rowCount();
        ui->table_penaliter->setModel(modeleNonTrie);
    }
}

void MainWindow::on_DESC_clicked()
{
    QString currentCriteria = ui->triebox->currentText();
    qDebug() << "Critère de tri : " << currentCriteria;

    if(currentCriteria != "Choisir") {
        QSqlQueryModel* modeleTriee = pen.trie("DESC", currentCriteria);
        qDebug() << "Nombre de lignes dans le modèle trié : " << modeleTriee->rowCount();
        ui->table_penaliter->setModel(modeleTriee);
    } else {
        QSqlQueryModel* modeleNonTrie = pen.GETALL();
        qDebug() << "Nombre de lignes dans le modèle non trié : " << modeleNonTrie->rowCount();
        ui->table_penaliter->setModel(modeleNonTrie);
    }
}
void MainWindow::on_qr_clicked()
{
    QString numero_penalite_str = ui->numero_penalite_2->text();
    int numero_penalite = numero_penalite_str.toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM penaliter WHERE numero_penalite = :numero_penalite");
    query.bindValue(":numero_penalite", numero_penalite);

    if (query.exec() && query.next()) {
        QString text = "<h2>Détails de la pénalité :</h2>"
                "<b>Numéro :</b> " + query.value(0).toString() + "<br>"
                "<b>Date :</b> " + query.value(1).toDate().toString() + "<br>"
                "<b>Montant :</b> " + query.value(2).toString() + "<br>"
                "<b>Nature :</b> " + query.value(3).toString() + "<br>"
                "<b>ID Auditeur :</b> " + query.value(4).toString() + "<br>"
                "<b>Notes :</b> " + query.value(5).toString();

        using namespace qrcodegen;
        QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);
        qint32 sz = qr.getSize();
        QImage im(sz, sz, QImage::Format_RGB32);
        QRgb black = qRgb(0, 0, 0);
        QRgb white = qRgb(255, 255, 255);

        for (int y = 0; y < sz; y++)
            for (int x = 0; x < sz; x++)
                im.setPixel(x, y, qr.getModule(x, y) ? black : white);

        ui->qr_code->setPixmap(QPixmap::fromImage(im.scaled(256, 256, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
    } else {
        QMessageBox::information(this, "Erreur", "Le numéro de pénalité n'existe pas dans la base de données.");
    }
}
void MainWindow::on_table_penaliter_activated(const QModelIndex &index)
{
    // Met à jour l'affichage dans la table des auditeurs avec toutes les données des auditeurs
    ui->table_penaliter->setModel(pen.GETALL());
}




void MainWindow::on_pdf_2_clicked(){
// Ouvre une boîte de dialogue pour permettre à l'utilisateur de sélectionner un fichier image
QString imagePath = QFileDialog::getOpenFileName(this,
    tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));

// Affiche le chemin du fichier sélectionné dans un widget texte (ui->photopath)
ui->photopath->setText(imagePath);

// Maintenant, la variable imagePath contient le chemin complet de l'image sélectionnée
// Vous pouvez utiliser cette variable selon les besoins de votre programme
}


bool MainWindow::controlSaisiemelek()
{
    // Vérifie si certains champs obligatoires sont vides
    if (ui->sexecombo->currentText().isEmpty() ||      // Vérifie le champ de texte pour le sexe
        ui->telephone_2->text().isEmpty() ||            // Vérifie le champ de texte pour le numéro de téléphone
        ui->email->text().isEmpty() ||                // Vérifie le champ de texte pour l'adresse e-mail
        ui->departement_2->text().isEmpty() ||          // Vérifie le champ de texte pour le département
        ui->salaire_2->text().isEmpty() ||              // Vérifie le champ de texte pour le salaire
        ui->secteur->text().isEmpty() ||              // Vérifie le champ de texte pour le secteur
        ui->missioncombo->currentText().isEmpty() ||  // Vérifie le champ de texte pour la mission actuelle
        ui->grade_2->text().isEmpty() ||                // Vérifie le champ de texte pour le grade
        ui->id_auditeur_2->text().isEmpty() ||          // Vérifie le champ de texte pour l'identifiant de l'auditeur
        ui->nom_auditeur->text().isEmpty() ||        // Vérifie le champ de texte pour le nom de l'auditeur
        ui->prenom_auditeur->text().isEmpty() ||     // Vérifie le champ de texte pour le prénom de l'auditeur
        ui->adresse_2->text().isEmpty() ||             // Vérifie le champ de texte pour l'adresse de l'auditeur
        ui->arrchivie->text().isEmpty()||              // Vérifie le champ de texte pour l'archive (peut-être une faute de frappe, peut-être "archive")
    ui->photopath->text().isEmpty()
            )
    {
        // Retourne false si au moins un des champs obligatoires est vide
        return false;
    }

    // Retourne true si tous les champs obligatoires sont remplis
    return true;
}
void MainWindow::on_ajouter_auditeur_clicked()

{
    // Crée une boîte de message pour afficher des messages à l'utilisateur
    QMessageBox msgBox;

    // Vérifie la validité des saisies à l'aide de la fonction controlSaisie()
    if (controlSaisiemelek())
    {
        // Récupère l'identifiant de l'auditeur à partir de l'interface
        QString id_auditeur = ui->id_auditeur_2->text();

        // Vérifie si l'auditeur avec l'identifiant spécifié existe déjà
        if (aud.auditeurexiste(id_auditeur))
        {
            // Affiche un message indiquant que l'auditeur existe déjà
            msgBox.setText("Auditeur with ID " + id_auditeur + " already exists.");
        }
        else
        {
            // L'auditeur n'existe pas, procède à l'ajout

            // Récupère les données saisies dans l'interface et les attribue à un objet auditeur (aud)
            aud.set_id_auditeur(id_auditeur.toInt());
            aud.set_nom_auditeur(ui->nom_auditeur->text());
            aud.set_prenom_auditeur(ui->prenom_auditeur->text());
            aud.set_sexe(ui->sexecombo->currentText());
            aud.set_telephone(ui->telephone_2->text().toInt());
            aud.set_adresse(ui->adresse_2->text());
            aud.set_email(ui->email->text());
            aud.set_departement(ui->departement_2->text());
            aud.set_salaire(ui->salaire_2->text().toDouble());
            aud.set_secteur(ui->secteur->text());
            aud.set_mission(ui->missioncombo->currentText());
            aud.set_grade(ui->grade_2->text());
            aud.set_archive(true);  // Peut-être une valeur par défaut pour le champ "archive"
            aud.set_image(ui->photopath->text());
            // Appelle la méthode ADD() de l'objet auditeur pour ajouter les données à une source de données (base de données, fichier, etc.)
            bool test = aud.ADD();

            // Affiche un message selon le succès ou l'échec de l'ajout
            if (test){
                msgBox.setText("Added successfully.");
             ui->stackedWidget->setCurrentIndex(1);}
            else
                msgBox.setText("!! Addition failed !!");
        }
    }
    else
    {
        // Affiche un message d'erreur si les saisies ne sont pas valides
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
            QObject::tr("Please fill all fields.\n !!! There are EMPTY or INCORRECT fields !!!\n"
            "Click cancel to EXIT."), QMessageBox::Cancel);
    }

    // Met à jour l'affichage dans une table (ui->table_auditeur) avec toutes les données des auditeurs
    ui->table_auditeur->setModel(aud.GETALL());

    // Affiche la boîte de message
    msgBox.exec();
}


void MainWindow::on_modifier_auditeur_clicked()

{
    // Crée une boîte de message pour afficher des messages à l'utilisateur
    QMessageBox msgBox;

    // Vérifie la validité des saisies à l'aide de la fonction controlSaisie()
    if (controlSaisiemelek())
    {
        // Récupère l'identifiant de l'auditeur à partir de l'interface
        QString id_auditeur = ui->id_auditeur_2->text();

        // Vérifie si l'auditeur avec l'identifiant spécifié existe
        if (aud.auditeurexiste(id_auditeur))
        {
            // L'auditeur existe, procède à la modification

            // Récupère les données saisies dans l'interface et les attribue à un objet auditeur (aud)
            aud.set_id_auditeur(id_auditeur.toInt());
            aud.set_nom_auditeur(ui->nom_auditeur->text());
            aud.set_prenom_auditeur(ui->prenom_auditeur->text());
            aud.set_sexe(ui->sexecombo->currentText());
            aud.set_telephone(ui->telephone_2->text().toInt());
            aud.set_adresse(ui->adresse_2->text());
            aud.set_email(ui->email->text());
            aud.set_departement(ui->departement_2->text());
            aud.set_salaire(ui->salaire_2->text().toDouble());
            aud.set_secteur(ui->secteur->text());
            aud.set_mission(ui->missioncombo->currentText());
            aud.set_grade(ui->grade_2->text());
            aud.set_image(ui->photopath->text());
            aud.set_archive(true);  // Peut-être une valeur par défaut pour le champ "archive"

            // Met à jour l'affichage dans une table (ui->table_auditeur) avec toutes les données des auditeurs
            ui->table_auditeur->setModel(aud.GETALL());

            // Tente de mettre à jour les données de l'auditeur en appelant la méthode UPDATE() de l'objet auditeur
            bool test = aud.UPDATE();

            // Affiche un message indiquant si la modification a réussi ou échoué
            if (test)
            {
                msgBox.setText("Modification successful.");
                ui->stackedWidget->setCurrentIndex(1);
            }
            else
            {
                msgBox.setText("!! Modification failed !!");
            }
        }
        else
        {
            // L'auditeur n'existe pas, affiche un message indiquant qu'il n'est pas possible de le modifier
            msgBox.setText("Auditeur with ID " + id_auditeur + " does not exist.\nCannot modify.");
        }
    }
    else
    {
        // Affiche un message d'erreur si les saisies ne sont pas valides
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
            QObject::tr("Please fill all fields.\n !!! There are EMPTY or INCORRECT fields !!!\n"
            "Click cancel to EXIT."), QMessageBox::Cancel);
    }

    // Affiche la boîte de message
    msgBox.exec();

    // Met à jour l'affichage dans une table (ui->table_auditeur) avec toutes les données des auditeurs
    ui->table_auditeur->setModel(aud.GETALL());
}


void MainWindow::on_pdf_clicked()

{


        // Prépare une requête SQL pour sélectionner toutes les colonnes de la table "auditeur"
        QSqlQuery query;
        query.prepare("SELECT * FROM auditeur");

        // Exécute la requête SQL
        if(query.exec())
        {
            // Initialise un objet QPdfWriter pour écrire dans un fichier PDF nommé "report.pdf"
            QPdfWriter pdfWriter("reportelek.pdf");
            QPainter painter(&pdfWriter);
            QTextDocument doc;

            // Crée une chaîne de caractères HTML pour le contenu du rapport
            QString report = "<p style='font-size:250pt;'>Rapport général sur les auditeurs :</p>";

            int totalAuditeurs = 0;
            int totalHommes = 0;
            int totalFemmes = 0;
            double totalSalaire = 0;

            // Parcourt les résultats de la requête
            while(query.next())
            {
                // Incrémente le compteur totalAuditeurs
                totalAuditeurs++;

                // Récupère le sexe de l'auditeur et met à jour les compteurs totalHommes et totalFemmes
                QString sexe = query.value("sexe").toString();
                if(sexe == "homme")
                    totalHommes++;
                else if(sexe == "femme")
                    totalFemmes++;

                // Ajoute le salaire de l'auditeur au totalSalaire
                totalSalaire += query.value("salaire").toDouble();
            }

            // Ajoute des informations au rapport HTML
            report += "<p style='font-size:200pt;'><strong>Nombre total d'auditeurs :</strong> " + QString::number(totalAuditeurs) + "</p>";
            report += "<p style='font-size:200pt;'><strong>Nombre total d'hommes :</strong> " + QString::number(totalHommes) + "</p>";
            report += "<p style='font-size:200pt;'><strong>Nombre total de femmes :</strong> " + QString::number(totalFemmes) + "</p>";
            report += "<p style='font-size:200pt;'><strong>Salaire moyen :</strong> " + QString::number(totalSalaire / totalAuditeurs) + "</p>";

            // Définit le contenu HTML du document QTextDocument
            doc.setHtml(report);

            // Dessine le contenu du document dans le QPainter associé au QPdfWriter
            doc.drawContents(&painter);
        }
        else
        {
            // Affiche un message d'erreur dans la console en cas d'échec de la requête SQL
            qDebug() << "Erreur lors de la génération du rapport : " << query.lastError();
        }


}


void MainWindow::on_suivant_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(8);
}

void MainWindow::on_back_9_clicked()
{
       ui->stackedWidget_2->setCurrentIndex(7);
}

void MainWindow::on_suivant_9_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pb_supprimer_clicked()

{
    // Récupère l'ID de l'auditeur à supprimer à partir de l'interface
    aud.set_id_auditeur(ui->id_auditeur_supp->text().toInt());

    // Vérifie si l'auditeur avec l'identifiant spécifié existe
    if (aud.auditeurexiste(QString::number(aud.get_id_auditeur())))
    {
        // L'auditeur existe, procède à la suppression

        // Récupère les données de l'auditeur avant la suppression en utilisant la méthode findbyid()
        QSqlQueryModel *model = aud.findbyid(aud.get_id_auditeur());

        // Attribue les données récupérées à l'objet auditeur (aud)
        aud.set_nom_auditeur(model->record(0).value("nom_auditeur").toString());
        aud.set_prenom_auditeur(model->record(0).value("prenom_auditeur").toString());
        aud.set_sexe(model->record(0).value("sexe").toString());
        aud.set_telephone(model->record(0).value("telephone").toInt());
        aud.set_adresse(model->record(0).value("adresse").toString());
        aud.set_email(model->record(0).value("email").toString());
        aud.set_departement(model->record(0).value("departement").toString());
        aud.set_salaire(model->record(0).value("salaire").toDouble());
        aud.set_secteur(model->record(0).value("secteur").toString());
        aud.set_mission(model->record(0).value("mission").toString());
        aud.set_grade(model->record(0).value("grade").toString());
        aud.set_archive(model->record(0).value("archive").toBool());
        aud.set_grade(model->record(0).value("image").toString());
        // Sauvegarde les données de l'auditeur dans un fichier
        QFile file("backup.txt");
        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "ID: " << aud.get_id_auditeur() << "\n";
            out << "Name: " << aud.get_nom_auditeur() << "\n";
            out << "Surname: " << aud.get_prenom_auditeur() << "\n";
            out << "Sex: " << aud.get_sexe() << "\n";
            out << "Phone: " << aud.get_telephone() << "\n";
            out << "Address: " << aud.get_adresse() << "\n";
            out << "Email: " << aud.get_email() << "\n";
            out << "Department: " << aud.get_departement() << "\n";
            out << "Salary: " << aud.get_salaire() << "\n";
            out << "Sector: " << aud.get_secteur() << "\n";
            out << "Mission: " << aud.get_mission() << "\n";
            out << "Grade: " << aud.get_grade() << "\n";
            out << "Archive: " << aud.get_archive() << "\n";
            out << "image: " << aud.get_image() << "\n";
            out << "----------------------------------------\n";  // Ligne de séparation
            file.close();
        }

        // Tente de supprimer l'auditeur en appelant la méthode DELETEE()
        bool test = aud.DELETEE(aud.get_id_auditeur());
        QMessageBox msgBox;

        // Affiche un message indiquant si la suppression a réussi ou échoué
        if (test)
        {
            msgBox.setText("Deletion successful.");
            ui->table_auditeur->setModel(aud.GETALL());
        }
        else
        {
            msgBox.setText("!! Deletion failed !!");
        }

        // Affiche la boîte de message
        msgBox.exec();
    }
    else
    {
        // L'auditeur n'existe pas, affiche un message indiquant qu'il n'est pas possible de le supprimer
        QMessageBox::warning(this, "Auditeur Not Found", "Auditeur with ID " + QString::number(aud.get_id_auditeur()) + " does not exist.\nCannot delete.");
    }
}

void MainWindow::on_stat_buttion_2_clicked()
{
    QSqlDatabase bd = QSqlDatabase::database();
QString mission;
        QSqlQuery query;
        query.prepare("SELECT mission FROM auditeur WHERE id_auditeur =:code");
        query.bindValue(":code", ui->mission_id->text());

        query.exec();
        if (query.next())
        {

            mission=query.value(0).toString();
           A.write_to_arduino(mission.toUtf8());

         }
        else {
            A.write_to_arduino("0");
        }
}

void MainWindow::on_ASC_2_clicked()
{


        // Vérifie si l'option sélectionnée dans le comboBox (triebox) est différente de "Choisir"
        if(ui->triebox_2->currentText() != "Choisir")
            // Trie les données de la table des auditeurs en ordre ascendant en fonction de la colonne sélectionnée
            ui->table_auditeur->setModel(aud.trie("ASC", ui->triebox_2->currentText()));
        else
            // Si "Choisir" est sélectionné, affiche toutes les données non triées
            ui->table_auditeur->setModel(aud.GETALL());


}

void MainWindow::on_DESC_2_clicked()
{
    // Vérifie si l'option sélectionnée dans le comboBox (triebox) est différente de "Choisir"
    if(ui->triebox_2->currentText() != "Choisir")
        // Trie les données de la table des auditeurs en ordre descendant en fonction de la colonne sélectionnée
        ui->table_auditeur->setModel(aud.trie("DESC", ui->triebox_2->currentText()));
    else
        // Si "Choisir" est sélectionné, affiche toutes les données non triées
        ui->table_auditeur->setModel(aud.GETALL());
}

void MainWindow::on_stat_buttion_clicked()
{
    // Appelle la fonction stat_capacite() qui semble retourner un objet QChartView
    QChartView *chartView = aud.stat_capacite();

    // Affiche la vue du graphique
    chartView->show();
}


void MainWindow::test()
{
    QByteArray data;
    data = A.read_from_arduino();

    if (!data.isEmpty()) {
        QString nom = A.chercher(data);
        if (!nom.isEmpty()) {
            QMessageBox::information(this, tr("Welcome"), tr("Bienvenue %1").arg(nom));
            qDebug() << "valid";
              A.write_to_arduino(nom.toUtf8());
        }else {
            A.write_to_arduino("0");
        }
    } else {
        QMessageBox::information(this, tr("Error"), tr("Failed to read data from arduino"));
        qDebug() << "invalid";

}
}








