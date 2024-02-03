#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include <QStyledItemDelegate>
#include <QDate>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onDownloadButtonClicked();
    int getSelectedPDFId();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_8_clicked();

    void on_bout_ajout_clicked();

    void on_s1_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_PDF_BUT_clicked();

    void on_DATA_ENT_clicked();

    void on_IMPORT_clicked();

    void on_EXPORT_clicked();

    void on_ERASE_clicked();

    void on_RECHERCHE_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Entrp Etemp;
};



class DateDelegate : public QStyledItemDelegate {
public:
    DateDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void initStyleOption(QStyleOptionViewItem* option, const QModelIndex& index) const override {
        QStyledItemDelegate::initStyleOption(option, index);

        // Check if the item corresponds to the "Due Date" column
        if (index.column() == 4) {
            QVariant value = index.data(Qt::DisplayRole);
            QDate dueDate = value.toDate();

            // Compare the due date with today's date
            if (dueDate < QDate::currentDate()) {
                // Set the text color to red
                option->palette.setColor(QPalette::Text, Qt::red);
            }
        }
    }
};


#endif // MAINWINDOW_H
