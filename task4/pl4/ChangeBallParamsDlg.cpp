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

QColor ChangeBallParamsDlg::get_value_ball_color_dialog()
{
    return ball_color;
}

QColor ChangeBallParamsDlg::get_value_board_color_dialog()
{
    return board_color;
}



void ChangeBallParamsDlg::on_pushButton_ball_color_clicked()
{
    BallDialog.open();
    if(BallDialog.exec() == QColorDialog::Accepted)
        ball_color = BallDialog.selectedColor();
}

void ChangeBallParamsDlg::on_pushButton_board_color_clicked()
{
    BoardDialog.open();
    if(BoardDialog.exec() == QColorDialog::Accepted)
        board_color = BoardDialog.selectedColor();
}
