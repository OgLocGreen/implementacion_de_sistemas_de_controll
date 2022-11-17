#include "ChangerBallParametersDlg.h"
#include "ChangerBallParametersDlg.h"

ChangerBallParametersDlg::ChangerBallParametersDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangerBallParametersDlg)
{
    ui->setupUi(this);
}

ChangerBallParametersDlg::~ChangerBallParametersDlg()
{
    delete ui;
}
