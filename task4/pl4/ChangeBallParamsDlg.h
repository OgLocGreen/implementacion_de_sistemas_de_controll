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

    int get_value();
    void set_value(int v);

private slots:
    void on_spinBox_Radio_valueChanged(int arg1);

private:
    Ui::ChangeBallParamsDlg *ui;

};

#endif // CHANGEBALLPARAMSDLG_H
