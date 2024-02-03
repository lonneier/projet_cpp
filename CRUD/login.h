#ifndef LOGIN_H
#define LOGIN_H
#include<string>
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts>
#include<QMessageBox>
#include "mainwindow.h"
#include<vector>
namespace Ui {
class LOGIN;
}

class LOGIN : public QWidget
{
    Q_OBJECT
public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();
    bool getAccess(){return access;};
    void setAccess(bool acc){ access=acc;};

private slots:
    void on_login_but_clicked();

private:
    bool access;
    int access_code;
    Ui::LOGIN *ui;
    MainWindow w;
};

class User {
private:
    QString name;
    QString password;
    int accessLevel;
    std::vector<User> USERS;

public:
    // Constructors
    User() : accessLevel(0) {}  // Default constructor

    User(const QString& newName, const QString& newPassword, int newAccessLevel)
        : name(newName), password(newPassword), accessLevel(newAccessLevel) {}

    User getUserFromDatabase(QString inputName, QString inputPassword);

    // Getter functions
    QString getName() const {
        return name;
    }

    QString getPassword() const {
        return password;
    }

    int getAccessLevel() const {
        return accessLevel;
    }

    // Setter functions
    void setName(const QString& newName) {
        name = newName;
    }

    void setPassword(const QString& newPassword) {
        password = newPassword;
    }

    void setAccessLevel(int newAccessLevel) {
        accessLevel = newAccessLevel;
    }
};

#endif // LOGIN_H
