/********************************************************************************
** Form generated from reading UI file 'alerte.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTE_H
#define UI_ALERTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_alerte
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QTableView *tableView;
    QLabel *label_3;
    QLabel *label_2;

    void setupUi(QDialog *alerte)
    {
        if (alerte->objectName().isEmpty())
            alerte->setObjectName(QStringLiteral("alerte"));
        alerte->resize(561, 263);
        groupBox = new QGroupBox(alerte);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-10, -20, 571, 281));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 160, 371, 61));
        label->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(400, 80, 161, 171));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 50, 111, 81));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/images.jpg")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 171, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/alerteee.png")));
        label_2->setScaledContents(true);

        retranslateUi(alerte);

        QMetaObject::connectSlotsByName(alerte);
    } // setupUi

    void retranslateUi(QDialog *alerte)
    {
        alerte->setWindowTitle(QApplication::translate("alerte", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("alerte", "GroupBox", Q_NULLPTR));
        label->setText(QApplication::translate("alerte", "attention la garantie des matriels experira bientot", Q_NULLPTR));
        label_3->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class alerte: public Ui_alerte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTE_H
