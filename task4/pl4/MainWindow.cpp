#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    timer->start(1000);
    MyBall myBall;
    //ui->label_circle->setGeometry(10,10,30,80);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_radio_valueChanged(int arg1)
{
   myBall.set_radio(arg1);
}

void MainWindow::on_spinBox_velo_valueChanged(int arg1)
{
   myBall.set_velo(arg1);
}

void MainWindow::on_pushButton_color_clicked()
{
    myBall.set_color(myBall.get_color()+1);
}

void MainWindow::on_checkBox_pausa_clicked()
{
    pausa = true;
}

void MainWindow::OnTimer()
{
    myBall.cal_new_postion();
    ui->label_x->setText(QString::number(myBall.get_postion_x()));
    ui->label_y->setText(QString::number(myBall.get_postion_y()));

    //Draw all the shit
    QPixmap pixmap("/home/oglocgreen/Desktop/gijon/implementacion_de_sistemas_de_controll/task4/pl4/sunny.png");
    QPainter painter(&pixmap);
    ui->label_circle->setGeometry(200+myBall.get_postion_x(),200+myBall.get_postion_y(),50,50);
    ui->label_circle->setPixmap(pixmap);

    //painter.drawPixmap(20,20,50,50, pixmap);
}



