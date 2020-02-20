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
    ui->p3height_l->setHidden(false);
    ui->p3height_l->setText("Point 3");
    ui->p3->setHidden(false);
    ui->p3_2->setHidden(false);
}

void GUI::on_rbtr_clicked()
{
    ui->p3height_l->setHidden(false);
    ui->p3height_l->setText("Height");
    ui->p3->setHidden(false);
    ui->p3_2->setHidden(true);
    ui->p3_2->setText("");
}

void GUI::on_rstr_clicked()
{
    ui->p3height_l->setHidden(true);
    ui->p3->setHidden(true);
    ui->p3_2->setHidden(true);
    ui->p3->setText("");
    ui->p3_2->setText("");
}

void GUI::on_pushButton_clicked()
{
    SampleData data;
    ui->warning->clear();

    if (ui->tr->isChecked()) {
        data._type = SampleData::triangle;
        if (ui->p1->text().isEmpty() &&
                ui->p1_2->text().isEmpty() &&
                ui->p2->text().isEmpty() &&
                ui->p2_2->text().isEmpty() &&
                ui->p3->text().isEmpty() &&
                ui->p3_2->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>All points can't be NULL.<FONT>");
            return;
        }
        if ((ui->p1->text().isEmpty() &&
             ui->p1_2->text().isEmpty() &&
             ui->p2->text().isEmpty() &&
             ui->p2_2->text().isEmpty()) ||
                (ui->p3->text().isEmpty() &&
                 ui->p3_2->text().isEmpty() &&
                 ui->p1->text().isEmpty() &&
                 ui->p1_2->text().isEmpty()) ||
                (ui->p3->text().isEmpty() &&
                 ui->p3_2->text().isEmpty() &&
                 ui->p2->text().isEmpty() &&
                 ui->p2_2->text().isEmpty())) {
            ui->warning->setText("<FONT COLOR=#800000>Two points can't be NULL.<FONT>");
            return;
        }
    }
    else if (ui->rbtr->isChecked()) {
        data._type = SampleData::rbtriangle;
        if (ui->p3->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>Height can't be NULL.<FONT>");
            return;
        }
        if (ui->p1->text().isEmpty() &&
                ui->p1_2->text().isEmpty() &&
                ui->p2->text().isEmpty() &&
                ui->p2_2->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>All points can't be NULL.<FONT>");
            return;
        }
    }
    else if (ui->rstr->isChecked()) {
        data._type = SampleData::rstriangle;
        if (ui->p1->text().isEmpty() &&
                ui->p1_2->text().isEmpty() &&
                ui->p2->text().isEmpty() &&
                ui->p2_2->text().isEmpty()) {
            ui->warning->setText("<FONT COLOR=#800000>All points can't be NULL.<FONT>");
            return;
        }
    }
    else {
        ui->warning->setText("<FONT COLOR=#800000>Please, choose triangle type.<FONT>");
        return;
    }

    if (ui->p1->text().isEmpty() &&
            ui->p1_2->text().isEmpty() &&
            ui->p2->text().isEmpty() &&
            ui->p2_2->text().isEmpty() &&
            ui->p3->text().isEmpty() &&
            ui->p3_2->text().isEmpty()) {
        ui->warning->setText("<FONT COLOR=#800000>All points can't be NULL.<FONT>");
        return;
    }

    data._x_a = ui->p1->text().toDouble();
    data._y_a = ui->p1_2->text().toDouble();
    data._x_b = ui->p2->text().toDouble();
    data._y_b = ui->p2_2->text().toDouble();
    data._x_c = ui->p3->text().toDouble();
    data._y_c = ui->p3_2->text().toDouble();

    emit addSampleToList(Sample(data));
}
