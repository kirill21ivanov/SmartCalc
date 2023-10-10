#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}



void Deposit::on_calculate_clicked()
{
    if(!ui->sum->text().isEmpty() && (!ui->years->text().isEmpty() || !ui->mounths->text().isEmpty()) && !ui->stavka->text().isEmpty()) {
        summa = ui->sum->text().toDouble();
        years = mounths = 0;
        if(!ui->years->text().isEmpty()) years = ui->years->text().toInt();
        if(years > 3) {
            int ostatok = years % 4;
            years -= ostatok;
            int visokos = years / 4;
            years = 3 * visokos + ostatok;
            days = years * 365 + visokos * 366;

        } else {
            days = years * 365;
        }
        if(!ui->mounths->text().isEmpty()) {
            mounths = ui->mounths->text().toInt();
            correction();
            days += 31;
            mounths--;
            while(mounths) {
                days += 30;
                mounths--;
            }
            days += correct;
        }
        deposit_stavka = ui->stavka->text().toDouble();
        dohodnost = 0, total = 0;
        if (ui->no->isChecked()) {
        deposit_calc(summa, days, deposit_stavka, &dohodnost, &total, 1);
        dohod = QString::number(dohodnost, 'g', 7);
        total_sum = QString::number(total, 'g', 7);
        ui->dohod->setText(dohod);
        ui->total->setText(total_sum);
        }
    }
}

void Deposit::correction()
{
    correct = 0;
    if(mounths == 2) correct = -2;
    if(mounths == 3 || mounths == 4) correct = -1;
    if(mounths == 7) correct = 1;
    if(mounths == 8 || mounths == 9) correct = 2;
    if(mounths == 10 || mounths == 11) correct = 3;

}
