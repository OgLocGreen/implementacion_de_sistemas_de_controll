#ifndef CHANGEBALLPARAMSDLG_H
#define CHANGEBALLPARAMSDLG_H

#include <QDialog>

namespace Ui {
class ChangeBallParamsDlg;
}

class ChangeBallParamsDlg : public QDialog
{
    Q_OBJECT
private:
    int radio;

public:
    explicit ChangeBallParamsDlg(QWidget *parent = nullptr);
    ~ChangeBallParamsDlg();

    double get_value_velo_x();
    double get_value_velo_y();
    void set_value_velo_x(double v);
    void set_value_velo_y(double v);

    int get_value_radio();
    void set_value_radio(int v);


private slots:
    void on_spinBox_Radio_valueChanged(int arg1);

    void on_doubleSpinBox_velo_x_2_valueChanged(double arg1);
    void on_doubleSpinBox_velo_y_2_valueChanged(double arg1);
private:
    Ui::ChangeBallParamsDlg *ui;

};

#endif // CHANGEBALLPARAMSDLG_H
