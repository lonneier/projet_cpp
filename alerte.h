#ifndef ALERTE_H
#define ALERTE_H

#include <QDialog>
#include "matriels.h"

namespace Ui {
class alerte;
}

class alerte : public QDialog
{
    Q_OBJECT

public:
    explicit alerte(QWidget *parent = nullptr);
    ~alerte();

private:
    Ui::alerte *ui;
};

#endif // ALERTE_H
