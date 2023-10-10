#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

extern "C" { // подключаем сишный файл извне
#include "../s21_smartcalc.h"
}

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private slots:
    void on_calculate_clicked();
    void correction();

private:
    Ui::Deposit *ui;
    double summa, deposit_stavka, nalog_stavka, dohodnost, total;
    int years, mounths, days, correct;
    QString total_sum, dohod;
};

#endif // DEPOSIT_H
