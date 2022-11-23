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

double ChangeBallParamsDlg::get_value_velo_x()
{
return(ui->doubleSpinBox_velo_x_2->value());
}

double ChangeBallParamsDlg::get_value_velo_y()
{
    return(ui->doubleSpinBox_velo_y_2->value());
}

void ChangeBallParamsDlg::set_value_velo_x(double arg1)
{
    ui->doubleSpinBox_velo_x_2->setValue(arg1);
}

void ChangeBallParamsDlg::set_value_velo_y(double arg1)
{
    ui->doubleSpinBox_velo_y_2->setValue(arg1);
}

int ChangeBallParamsDlg::get_value_radio()
{
    return(ui->spinBox_radio->value());
}

void ChangeBallParamsDlg::set_value_radio(int v)
{
    ui->spinBox_radio->setValue(v);
}



void ChangeBallParamsDlg::on_spinBox_Radio_valueChanged(int arg1)
{
    /*
    if (updateMyBallSpeed)
    {
         myBall.set_radio(arg1);
    }
    */
}


void ChangeBallParamsDlg::on_doubleSpinBox_velo_x_2_valueChanged(double arg1)
{

}

void ChangeBallParamsDlg::on_doubleSpinBox_velo_y_2_valueChanged(double arg1)
{

}

