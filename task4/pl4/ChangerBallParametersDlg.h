#ifndef CHANGERBALLPARAMETERSDLG_H
#define CHANGERBALLPARAMETERSDLG_H

#include <QDialog>

namespace Ui {
class ChangerBallParametersDlg;
}

class ChangerBallParametersDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChangerBallParametersDlg(QWidget *parent = nullptr);
    ~ChangerBallParametersDlg();

private:
    Ui::ChangerBallParametersDlg *ui;
};

#endif // CHANGERBALLPARAMETERSDLG_H
