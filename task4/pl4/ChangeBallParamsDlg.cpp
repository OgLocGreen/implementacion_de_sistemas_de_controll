#include "ChangeBallParamsDlg.h"
#include "ui_ChangeBallParamsDlg.h"

ChangeBallParamsDlg::ChangeBallParamsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeBallParamsDlg)
{
    ui->setupUi(this);
    ui->comboBox_ball_color->setPlaceholderText(QStringLiteral("--Select Color--"));
    ui->comboBox_board_color->setPlaceholderText(QStringLiteral("--Select Color--"));


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

QString ChangeBallParamsDlg::get_value_board_color()
{
    return ui->comboBox_board_color->currentText();
}

void ChangeBallParamsDlg::set_value_board_color(QString color)
{
    ui->comboBox_board_color->setCurrentText(color);
}

QString ChangeBallParamsDlg::get_value_ball_color()
{
   return ui->comboBox_ball_color->currentText();
}

void ChangeBallParamsDlg::set_value_ball_color(QString color)
{
    ui->comboBox_ball_color->setCurrentText(color);
}





