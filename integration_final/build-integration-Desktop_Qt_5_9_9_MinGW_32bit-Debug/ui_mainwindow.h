/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QPushButton *login_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLineEdit *password;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *username;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_7;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_14;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_15;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_16;
    QStackedWidget *stackedWidget_2;
    QWidget *page_8;
    QLabel *label_12;
    QWidget *page_3;
    QPushButton *modifier;
    QPushButton *ajouter;
    QComboBox *le_type;
    QLineEdit *le_id;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *le_id_2;
    QLabel *label_9;
    QPushButton *suivant;
    QPushButton *pushButton_19;
    QLineEdit *lineEdit_2;
    QLineEdit *le_nom;
    QComboBox *le_etat_mod_3;
    QPushButton *modifier_2;
    QDateEdit *dateEdit_2;
    QWidget *page_4;
    QTableView *table_matriels;
    QPushButton *suivant_2;
    QLineEdit *le_id_supp;
    QPushButton *PDF;
    QPushButton *supprimer;
    QPushButton *back;
    QLineEdit *lineEdit;
    QPushButton *supprimer_2;
    QPushButton *supprimer_3;
    QWidget *page_5;
    QLabel *stat_matriel;
    QPushButton *back_2;
    QWidget *page_6;
    QWidget *page_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1016, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 0, 991, 618));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(170, 80, 701, 481));
        login_2 = new QPushButton(groupBox);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(250, 380, 141, 41));
        login_2->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"	font: 14pt \"MS Shell Dlg 2\";\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 160, 91, 41));
        label_13->setStyleSheet(QLatin1String("font: 75 18pt \"Rockwell Condensed\";\n"
"color: rgb(0, 48, 0);"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 20, 56, 41));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/logo.jpg")));
        label_14->setScaledContents(true);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(580, 20, 101, 91));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/308382982_615546510197972_8922151083998088599_n.png")));
        label_15->setScaledContents(true);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 290, 221, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(21, 21));
        label_11->setMaximumSize(QSize(21, 21));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/passworf.png")));
        label_11->setScaledContents(true);

        horizontalLayout_4->addWidget(label_11);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(password);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 240, 221, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(31, 21));
        label_10->setMaximumSize(QSize(31, 21));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/user-login-icon-14.png")));
        label_10->setScaledContents(true);

        horizontalLayout_5->addWidget(label_10);

        username = new QLineEdit(layoutWidget1);
        username->setObjectName(QStringLiteral("username"));

        horizontalLayout_5->addWidget(username);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(page_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QString::fromUtf8("/* styles.qss */\n"
"\n"
"/* Style pour le widget principal (fen\303\252tre) */\n"
"QWidget {\n"
"    background-color: #001f3f; /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    border: 2px solid #00274d; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 50));
        label->setMaximumSize(QSize(70, 50));
        label->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/387499943_313261994748138_6582694327079011443_n.png")));
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../OneDrive/Pictures/projet/matriels.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));
        pushButton->setCheckable(true);
        pushButton->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../OneDrive/Pictures/projet/auditeur.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(30, 30));
        pushButton_3->setCheckable(true);
        pushButton_3->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../OneDrive/Pictures/projet/penalite.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(40, 40));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../OneDrive/Pictures/projet/employe.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(40, 40));
        pushButton_5->setCheckable(true);
        pushButton_5->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../OneDrive/Pictures/projet/formation.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_2->setCheckable(true);
        pushButton_2->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../OneDrive/Pictures/projet/entreprise.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(35, 35));
        pushButton_6->setCheckable(true);
        pushButton_6->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_6);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 192, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../Downloads/login-xxl.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(30, 20));

        verticalLayout_3->addWidget(pushButton_7);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("/* styles.qss */\n"
"\n"
"/* Style pour le widget principal (fen\303\252tre) */\n"
"QWidget {\n"
"    background-color: #001f3f; /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    border: 2px solid #00274d; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(90, 49));
        label_2->setMaximumSize(QSize(90, 49));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Pictures/projet/387499943_313261994748138_6582694327079011443_n.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(15);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_8 = new QPushButton(widget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 50));
        pushButton_8->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(20, 20));
        pushButton_8->setCheckable(true);
        pushButton_8->setAutoExclusive(true);

        verticalLayout_2->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 50));
        pushButton_9->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_9->setIcon(icon1);
        pushButton_9->setCheckable(true);
        pushButton_9->setAutoExclusive(true);

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(widget_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 50));
        pushButton_10->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_10->setIcon(icon2);
        pushButton_10->setIconSize(QSize(25, 25));
        pushButton_10->setCheckable(true);
        pushButton_10->setAutoExclusive(true);

        verticalLayout_2->addWidget(pushButton_10);

        pushButton_12 = new QPushButton(widget_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 50));
        pushButton_12->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_12->setIcon(icon4);
        pushButton_12->setIconSize(QSize(25, 25));
        pushButton_12->setCheckable(true);
        pushButton_12->setAutoExclusive(true);

        verticalLayout_2->addWidget(pushButton_12);

        pushButton_11 = new QPushButton(widget_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(0, 50));
        pushButton_11->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_11->setIcon(icon3);
        pushButton_11->setIconSize(QSize(20, 20));
        pushButton_11->setCheckable(true);
        pushButton_11->setAutoExclusive(true);

        verticalLayout_2->addWidget(pushButton_11);

        pushButton_13 = new QPushButton(widget_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(0, 50));
        pushButton_13->setAutoFillBackground(false);
        pushButton_13->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_13->setIcon(icon5);
        pushButton_13->setCheckable(true);
        pushButton_13->setAutoExclusive(true);

        verticalLayout_2->addWidget(pushButton_13);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 172, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        pushButton_14 = new QPushButton(widget_2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #001f3f; /* Utilise la m\303\252me couleur que la fen\303\252tre principale */\n"
"    color: white;\n"
"    border: 2px solid #001f3f; /* Utilise la m\303\252me couleur pour la bordure */\n"
"    border-radius: 5px; /* Coins arrondis pour les boutons */\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* Style pour les QPushButton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #005cbf; /* Couleur plus claire au survol */\n"
"}\n"
"\n"
"/* Style pour les QPushButton appuy\303\251s */\n"
"QPushButton:pressed {\n"
"    background-color: #003366; /* Couleur plus fonc\303\251e lorsque le bouton est appuy\303\251 */\n"
"}"));
        pushButton_14->setIcon(icon6);
        pushButton_14->setIconSize(QSize(20, 20));

        verticalLayout_4->addWidget(pushButton_14);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(page_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(20, 50));
        layoutWidget2 = new QWidget(widget_4);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 641, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_15 = new QPushButton(layoutWidget2);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../../OneDrive/Pictures/projet/choix.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon7);
        pushButton_15->setCheckable(true);

        horizontalLayout_3->addWidget(pushButton_15);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_16 = new QPushButton(layoutWidget2);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../../OneDrive/Pictures/projet/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon8);

        horizontalLayout_3->addWidget(pushButton_16);


        verticalLayout_5->addWidget(widget_4);

        stackedWidget_2 = new QStackedWidget(widget_3);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        label_12 = new QLabel(page_8);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(70, 70, 521, 391));
        stackedWidget_2->addWidget(page_8);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        modifier = new QPushButton(page_3);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(270, 460, 161, 41));
        modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        ajouter = new QPushButton(page_3);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(80, 460, 171, 41));
        ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        le_type = new QComboBox(page_3);
        le_type->setObjectName(QStringLiteral("le_type"));
        le_type->setGeometry(QRect(200, 160, 201, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Semilight"));
        font1.setPointSize(9);
        le_type->setFont(font1);
        le_id = new QLineEdit(page_3);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(200, 40, 201, 31));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 140, 61, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("NSimSun"));
        font2.setPointSize(14);
        label_4->setFont(font2);
        label_4->setCursor(QCursor(Qt::ArrowCursor));
        label_4->setMouseTracking(false);
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 20, 51, 61));
        label_5->setFont(font2);
        label_5->setCursor(QCursor(Qt::ArrowCursor));
        label_5->setMouseTracking(false);
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 90, 51, 61));
        label_6->setFont(font2);
        label_6->setCursor(QCursor(Qt::ArrowCursor));
        label_6->setMouseTracking(false);
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 220, 61, 51));
        label_7->setFont(font2);
        label_7->setCursor(QCursor(Qt::ArrowCursor));
        label_7->setMouseTracking(false);
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 290, 101, 61));
        label_8->setFont(font2);
        label_8->setCursor(QCursor(Qt::ArrowCursor));
        label_8->setMouseTracking(false);
        le_id_2 = new QLineEdit(page_3);
        le_id_2->setObjectName(QStringLiteral("le_id_2"));
        le_id_2->setGeometry(QRect(200, 370, 201, 31));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 350, 191, 61));
        label_9->setFont(font2);
        label_9->setCursor(QCursor(Qt::ArrowCursor));
        label_9->setMouseTracking(false);
        suivant = new QPushButton(page_3);
        suivant->setObjectName(QStringLiteral("suivant"));
        suivant->setGeometry(QRect(550, 30, 93, 28));
        suivant->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        pushButton_19 = new QPushButton(page_3);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(540, 320, 93, 28));
        pushButton_19->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        lineEdit_2 = new QLineEdit(page_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(530, 280, 113, 20));
        le_nom = new QLineEdit(page_3);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(200, 100, 201, 31));
        le_etat_mod_3 = new QComboBox(page_3);
        le_etat_mod_3->setObjectName(QStringLiteral("le_etat_mod_3"));
        le_etat_mod_3->setGeometry(QRect(200, 240, 201, 31));
        le_etat_mod_3->setFont(font1);
        modifier_2 = new QPushButton(page_3);
        modifier_2->setObjectName(QStringLiteral("modifier_2"));
        modifier_2->setGeometry(QRect(450, 460, 161, 41));
        modifier_2->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        dateEdit_2 = new QDateEdit(page_3);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(200, 300, 201, 31));
        dateEdit_2->setStyleSheet(QStringLiteral("font: 8pt \"MS Shell Dlg 2\";"));
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        table_matriels = new QTableView(page_4);
        table_matriels->setObjectName(QStringLiteral("table_matriels"));
        table_matriels->setGeometry(QRect(20, 60, 561, 241));
        table_matriels->setStyleSheet(QLatin1String("QTableView {\n"
"\n"
"background-color: #FFFFFF; /* Background color similar to Windows */\n"
"\n"
"border: 1px solid #C0C0C0; /* Border color */\n"
"\n"
"selection-background-color: #0078D4; /* Selection background color similar to Windows */\n"
"\n"
"selection-color: #FFFFFF; /* Selection text color similar to Windows */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QHeaderView::section {\n"
"\n"
"background-color: #0078D4; /* Header section background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Header section text color similar to Windows */\n"
"\n"
"padding: 5px; /* Padding around header sections */\n"
"\n"
"}"));
        suivant_2 = new QPushButton(page_4);
        suivant_2->setObjectName(QStringLiteral("suivant_2"));
        suivant_2->setGeometry(QRect(560, 20, 93, 28));
        suivant_2->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        le_id_supp = new QLineEdit(page_4);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(130, 330, 221, 21));
        PDF = new QPushButton(page_4);
        PDF->setObjectName(QStringLiteral("PDF"));
        PDF->setGeometry(QRect(430, 450, 161, 41));
        PDF->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        supprimer = new QPushButton(page_4);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(360, 320, 161, 41));
        supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        back = new QPushButton(page_4);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 460, 93, 28));
        back->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        lineEdit = new QLineEdit(page_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 380, 221, 21));
        supprimer_2 = new QPushButton(page_4);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(360, 370, 161, 41));
        supprimer_2->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        supprimer_3 = new QPushButton(page_4);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setGeometry(QRect(250, 450, 161, 41));
        supprimer_3->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stat_matriel = new QLabel(page_5);
        stat_matriel->setObjectName(QStringLiteral("stat_matriel"));
        stat_matriel->setGeometry(QRect(40, 70, 581, 371));
        back_2 = new QPushButton(page_5);
        back_2->setObjectName(QStringLiteral("back_2"));
        back_2->setGeometry(QRect(20, 460, 93, 28));
        back_2->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color: #0078D4; /* Button background color similar to Windows */\n"
"\n"
"color: #FFFFFF; /* Button text color */\n"
"\n"
"border: 1px solid #0078D4; /* Button border color */\n"
"\n"
"border-radius: 4px; /* Button border radius */\n"
"\n"
"padding: 6px 12px; /* Button padding */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #00559B; /* Hovered button background color */\n"
"\n"
"border: 1px solid #00559B; /* Hovered button border color */\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #003C75; /* Pressed butt}"));
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget_2->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        stackedWidget_2->addWidget(page_7);

        verticalLayout_5->addWidget(stackedWidget_2);


        gridLayout->addWidget(widget_3, 0, 2, 1, 1);

        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1016, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_15, SIGNAL(toggled(bool)), widget, SLOT(setVisible(bool)));
        QObject::connect(pushButton_15, SIGNAL(toggled(bool)), widget_2, SLOT(setHidden(bool)));
        QObject::connect(pushButton, SIGNAL(toggled(bool)), pushButton_8, SLOT(setChecked(bool)));
        QObject::connect(pushButton_3, SIGNAL(toggled(bool)), pushButton_9, SLOT(setChecked(bool)));
        QObject::connect(pushButton_4, SIGNAL(toggled(bool)), pushButton_10, SLOT(setChecked(bool)));
        QObject::connect(pushButton_5, SIGNAL(toggled(bool)), pushButton_11, SLOT(setChecked(bool)));
        QObject::connect(pushButton_2, SIGNAL(toggled(bool)), pushButton_12, SLOT(setChecked(bool)));
        QObject::connect(pushButton_6, SIGNAL(toggled(bool)), pushButton_13, SLOT(setChecked(bool)));
        QObject::connect(pushButton_13, SIGNAL(toggled(bool)), pushButton_6, SLOT(setChecked(bool)));
        QObject::connect(pushButton_12, SIGNAL(toggled(bool)), pushButton_2, SLOT(setChecked(bool)));
        QObject::connect(pushButton_11, SIGNAL(toggled(bool)), pushButton_5, SLOT(setChecked(bool)));
        QObject::connect(pushButton_10, SIGNAL(toggled(bool)), pushButton_4, SLOT(setChecked(bool)));
        QObject::connect(pushButton_9, SIGNAL(toggled(bool)), pushButton_3, SLOT(setChecked(bool)));
        QObject::connect(pushButton_8, SIGNAL(toggled(bool)), pushButton, SLOT(setChecked(bool)));

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "sign in", Q_NULLPTR));
        login_2->setText(QApplication::translate("MainWindow", "login", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Sign in:", Q_NULLPTR));
        label_14->setText(QString());
        label_15->setText(QString());
        label_11->setText(QString());
        password->setPlaceholderText(QApplication::translate("MainWindow", "inserer le mot de passe", Q_NULLPTR));
        label_10->setText(QString());
        username->setPlaceholderText(QApplication::translate("MainWindow", "inserer votre login", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_2->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "MENU", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "MATERIEL", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "AUDITEUR", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "PENALITE", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "FORMATION", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "EMPLOYE", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "ENTREPRISE", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "D\303\251connexion", Q_NULLPTR));
        pushButton_15->setText(QString());
        pushButton_16->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "ABOUT US:", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        le_type->clear();
        le_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "commun", Q_NULLPTR)
         << QApplication::translate("MainWindow", "personnalise", Q_NULLPTR)
        );
        le_id->setPlaceholderText(QApplication::translate("MainWindow", "taper id", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Etat", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Garantie", Q_NULLPTR));
        le_id_2->setPlaceholderText(QApplication::translate("MainWindow", "0 disponible  1 non disponible", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Disponibilite", Q_NULLPTR));
        suivant->setText(QApplication::translate("MainWindow", "Suivant", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("MainWindow", "arduino", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "taper id arduino", Q_NULLPTR));
        le_nom->setPlaceholderText(QApplication::translate("MainWindow", "taper nom", Q_NULLPTR));
        le_etat_mod_3->clear();
        le_etat_mod_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "en panne", Q_NULLPTR)
         << QApplication::translate("MainWindow", "en bon etat", Q_NULLPTR)
         << QApplication::translate("MainWindow", "a detruire", Q_NULLPTR)
        );
        modifier_2->setText(QApplication::translate("MainWindow", "annuler", Q_NULLPTR));
        suivant_2->setText(QApplication::translate("MainWindow", "Suivant", Q_NULLPTR));
        PDF->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        back->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        supprimer_3->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        stat_matriel->setText(QString());
        back_2->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
