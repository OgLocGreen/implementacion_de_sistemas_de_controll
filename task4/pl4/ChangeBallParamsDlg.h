#ifndef CHANGEBALLPARAMSDLG_H
#define CHANGEBALLPARAMSDLG_H

#include <QDialog>
#include <QColorDialog>


namespace Ui {
class ChangeBallParamsDlg;
}

class ChangeBallParamsDlg : public QDialog
{
    Q_OBJECT
private:
    int radio;
    QColorDialog BallDialog;
    QColorDialog BoardDialog;

    QColor ball_color;
    QColor board_color;

public:
    explicit ChangeBallParamsDlg(QWidget *parent = nullptr);
    ~ChangeBallParamsDlg();

    double get_value_velo_x();
    double get_value_velo_y();
    void set_value_velo_x(double v);
    void set_value_velo_y(double v);

    int get_value_radio();
    void set_value_radio(int v);

    QString get_value_board_color();
    void set_value_board_color(QString color);

    QString get_value_ball_color();
    void set_value_ball_color(QString color);

    QColor get_value_ball_color_dialog();

    QColor get_value_board_color_dialog();

private slots:

    void on_pushButton_ball_color_clicked();
    void on_pushButton_board_color_clicked();

private:
    Ui::ChangeBallParamsDlg *ui;

};

#endif // CHANGEBALLPARAMSDLG_H
