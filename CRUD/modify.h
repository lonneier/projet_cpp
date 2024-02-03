#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>
#include "client.h"

namespace Ui {
class Modify;
}

class Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();
    void onIDTextChanged(const QString &text);


private slots:
    void on_pushButton_clicked();

    void on_IDLE_returnPressed();

    void on_IDLE_textChanged(const QString &arg1);

private:
    Ui::Modify *ui;
    Entrp Ctemp;

};

#endif // MODIFY_H
