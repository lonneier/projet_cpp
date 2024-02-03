#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "modify.h"
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

void MainWindow::on_lineEdit_textChanged(const QString &filterText) {

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
