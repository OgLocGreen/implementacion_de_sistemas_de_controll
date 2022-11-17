#include "ChangeBallParamsDlg.h"
#include "ui_ChangeBallParamsDlg.h"

ChangeBallParamsDlg::ChangeBallParamsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeBallParamsDlg)
{
    ui->setupUi(this);
}

ChangeBallParamsDlg::~ChangeBallParamsDlg()
{
    delete ui;
}

int ChangeBallParamsDlg::get_value()
{
    return ui->spinBox_radio->value();
}

void ChangeBallParamsDlg::set_value(int v)
{
    radio = v;
    ui->spinBox_radio->setValue(v);
}

void ChangeBallParamsDlg::on_spinBox_Radio_valueChanged(int arg1)
{
    //this->set_value(arg1);
}

