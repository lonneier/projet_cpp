#ifndef SUPPRIME_H
#define SUPPRIME_H

#include <QDialog>
#include "client.h"

namespace Ui {
class Supprime;
}

class Supprime : public QDialog
{
    Q_OBJECT

public:
    explicit Supprime(QWidget *parent = nullptr);
    ~Supprime();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Supprime *ui;
    Entrp Ctemp;

};

#endif // SUPPRIME_H
