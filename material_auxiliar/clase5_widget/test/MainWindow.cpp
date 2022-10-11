#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->qSum_resulta_spinBox->setVisible(false);
    QObject::connect(&timer,SIGNAL(timeout()),this, SLOT(OnMyTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}p


void MainWindow::on_qSum_pushButton_clicked()
{
    int var_a = ui->qSum_a_spinBox->value();
    int var_b = ui->qSum_b_spinBox->value();
    result = var_a + var_b;
    ui->qSum_resulta_spinBox->setValue(result);
    ui->qSum_resulta_spinBox->setVisible(true);
    ui->qSum_resulta_spinBox->setEnabled(true);

    if(result<0)
    {
        timer.start(1000);
    }
    else if(result>20)
    {
        timer.stop();
    }
}

void MainWindow::on_qSum_a_spinBox_valueChanged(int arg1)
{
    ui->qSum_resulta_spinBox->setEnabled(false);
}

void MainWindow::OnMyTimer()
{
    counter++;
    QString txt=QString("Valor entero: %1").arg(counter);
}


void MainWindow::on_qMyData_listWidget_itemSelectionChanged()
{

}

