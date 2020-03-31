#include "gui.h"
#include "ui_gui.h"


GUI::GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
}

GUI::~GUI()
{
    delete ui;
}

void GUI::on_tr_clicked()
{
    ui->p3_l->setHidden(false);
    ui->p3->setHidden(false);
    ui->p2_l->setHidden(false);
    ui->p2->setHidden(false);
    ui->p2_l->setText("B");
}

void GUI::on_rbtr_clicked()
{
    ui->p3_l->setHidden(true);
    ui->p3->setHidden(true);
    ui->p3->setText("");
    ui->p2_l->setText("Angle");
}

void GUI::on_rstr_clicked()
{
    ui->p3_l->setHidden(true);
    ui->p3->setHidden(true);
    ui->p2_l->setHidden(true);
    ui->p2->setHidden(true);
    ui->p3->setText("");
    ui->p2->setText("");
}

void GUI::on_pushButton_clicked()
{
    SampleData data;
    ui->warning->clear();

    if (ui->tr->isChecked()) {
        data._type = SampleData::triangle;
        if (ui->p1->text().isEmpty() &&
            ui->p2->text().isEmpty() &&
            ui->p3->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>All sides can't be NULL.<FONT>");
            return;
        }
        if ((ui->p1->text().isEmpty() &&
             ui->p2->text().isEmpty()) ||
                (ui->p3->text().isEmpty() &&
                 ui->p1->text().isEmpty()) ||
                (ui->p3->text().isEmpty() &&
                 ui->p2->text().isEmpty())) {
            ui->warning->setText("<FONT COLOR=#800000>Two sides can't be NULL.<FONT>");
            return;
        }
    }
    else if (ui->rbtr->isChecked()) {
        data._type = SampleData::rbtriangle;
        if (ui->p1->text().isEmpty() &&
            ui->p2->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>Sides can't be NULL.<FONT>");
            return;
        }
    }
    else if (ui->rstr->isChecked()) {
        data._type = SampleData::rstriangle;
        if (ui->p1->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>Sides can't be NULL.<FONT>");
            return;
        }
    }
    else {
        ui->warning->setText("<FONT COLOR=#800000>Please, choose triangle type.<FONT>");
        return;
    }

    if (ui->p1->text().isEmpty() &&
        ui->p2->text().isEmpty() &&
        ui->p3->text().isEmpty()) {
        ui->warning->setText("<FONT COLOR=#800000>All points can't be NULL.<FONT>");
        return;
    }

    data._a = ui->p1->text().toDouble();
    data._b = ui->p2->text().toDouble();
    data._angle = ui->p3->text().toDouble();

    if (data._type == SampleData::rbtriangle)
        data._angle = ui->p2->text().toDouble();

    emit addSampleToList(Sample(data));
}
