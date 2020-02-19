#include "Interface.h"
#include "ui_Interface.h"
Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    udp = new UdpClient(this);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::setText(QString &poly)
{
    ui->textBrowser->append(poly);
}

void Interface::setText(QString &x1, QString &x2)
{
    ui->textBrowser->append(QString("X1 = " + x1));
    ui->textBrowser->append(QString("X2 = " + x2));
}

void Interface::on_pushButton_clicked()
{
    if (ui->a_r->text().toDouble() == 0 && ui->a_i->text().toDouble() == 0) {
        ui->textBrowser->append("Coefficient A cannot be NULL. Fill in the fields.");
        return;
    }

    QStringList data;
    data.append("CALC");
    data.append(ui->a_r->text());
    data.append(ui->a_i->text());
    data.append(ui->b_r->text());
    data.append(ui->b_i->text());
    data.append(ui->c_r->text());
    data.append(ui->c_i->text());

    emit sendData(data);
}

void Interface::on_pushButton_2_clicked()
{
    QStringList data;
    data.append("SHOW");

    emit sendData(data);
}




