#include "MainWindow.h"
#include "ui_ChangeBallParamsDlg.h"
#include "ui_MainWindow.h"
#include "ChangeBallParamsDlg.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    timer->start(100);
    MyBall myBall;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_radio_valueChanged(int arg1)
{
   myBall.set_radio(arg1);
}

void MainWindow::on_spinBox_velo_x_valueChanged(int arg_x)
{
   myBall.set_velo_x(arg_x);
}

void MainWindow::on_spinBox_velo_y_valueChanged(int arg_y)
{
   myBall.set_velo_y(arg_y);
}

void MainWindow::on_checkBox_pausa_clicked()
{
    if(pausa == true)
    {
        pausa = false;
    }
    else{
        pausa = true;
    }
}

void MainWindow::OnTimer()
{
    if(pausa==false)
    {
        myBall.cal_new_postion();
    }

    ui->label_x->setText(QString::number(myBall.get_postion_x()));
    ui->label_y->setText(QString::number(myBall.get_postion_y()));

    ui->spinBox_radio->setValue(myBall.get_radio());
    ui->spinBox_velo_x->setValue(myBall.get_velo_x());
    ui->spinBox_velo_y->setValue(myBall.get_velo_y());

    draw_board();
    draw_ball(myBall.get_postion_x(),myBall.get_postion_y());
}

void MainWindow::draw_ball(int ball_pos_x, int ball_pos_y)
{

    QPixmap pixmap(ui->label_board->size());
    QPainter painter(&pixmap);
    QPen pen(Qt::DashLine);
    pen.setColor(Qt::green);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPoint(ball_pos_x,ball_pos_y), myBall.get_radio(),myBall.get_radio());
    ui->label_board->setPixmap(pixmap);
}

void MainWindow::draw_board()
{
    QPixmap pixmap(ui->label_board->size());
    QPainter painter(&pixmap);

    int board_hole_radius = 40;
    int board_wall_wide = 20;
    int board_wide = 440;
    int board_hide = 240;

    // painter.drawRect(x,y, w, h);

    painter.setBrush( Qt::darkGreen);
    painter.drawRect(0,0, board_wide, board_hide);

    painter.setBrush(Qt::darkYellow);
    painter.drawRect(0,0, board_wide, board_wall_wide);
    painter.drawRect(0,board_hide - board_wall_wide, board_wide, board_wall_wide);
    painter.drawRect(0,0, board_wall_wide, board_hide);
    painter.drawRect(board_wide - board_wall_wide ,0, board_wall_wide, board_hide);

    painter.setBrush(Qt::darkGray);
    painter.drawEllipse(QPoint(0,0),board_hole_radius,board_hole_radius);
    painter.drawEllipse(QPoint(board_hide- board_wall_wide,0),int(board_hole_radius*0.75),int(board_hole_radius*0.75));
    painter.drawEllipse(QPoint(board_wide,0),board_hole_radius,board_hole_radius);

    painter.drawEllipse(QPoint(0,board_hide),board_hole_radius,board_hole_radius);
    painter.drawEllipse(QPoint(board_hide- board_wall_wide,board_hide),int(board_hole_radius*0.75),int(board_hole_radius*0.75));
    painter.drawEllipse(QPoint(board_wide,board_hide),board_hole_radius,board_hole_radius);


    //pen.setColor(Qt::yellow);
    //painter.setPen(pen);
    //painter.drawText(20,30, "Prueba");

    ui->label_board->setPixmap(pixmap);
}


void MainWindow::on_actionChange_Params_triggered()
{
    ChangeBallParamsDlg dlg;    //öffnet die Falsche Spinbox_Main window brauchen aber die spinbox second window (Change Params);

    //dlg.set_value(myBall.get_radio());
    ui->spinBox_radio->setValue(myBall.get_radio());
    dlg.set_value(myBall.get_radio());   //how to get to the second window?

    if (dlg.exec() == QDialog::Accepted)
    {
        //dass hier wird in einer zeile gemacht und ohne zwischen speichern
        //dlg.set_value(ui->spinBox_radio_2->value());

        myBall.set_radio(dlg.get_value());
        ui->spinBox_radio->setValue(myBall.get_radio());

    }
}



void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "./", tr("*.txt"));

    QFile file(fileName);
    QByteArray arr;
    if(file.open(QIODevice::ReadOnly)){
    arr = file.readAll();
    file.close();
    }
    myBall.set_color(XmlGetStr(arr, "color").toInt());
    myBall.set_radio(XmlGetStr(arr, "radio").toInt());
    myBall.set_velo_x(XmlGetStr(arr, "velo_x").toInt());
    myBall.set_velo_y(XmlGetStr(arr, "velo_y").toInt());
    // hier dann die Datenauslesen und an die richtigen stellen übergeben.
    // vlt dann im nachhinein in die eigene klasse OpenFile Übergeben falls zu viel

}


QString MainWindow::XmlGetStr(const QString &textXml, const QString &tagXml)
{
    QString ret;
    int istart, iend;
    int indexStart, lengStr;


    istart = textXml.indexOf("<"+tagXml+">");
    iend = textXml.indexOf("</"+tagXml+">");
    indexStart = istart+tagXml.length()+2;
    lengStr = iend - indexStart;
    ret = textXml.mid(indexStart, lengStr);

    return ret;
}


float MainWindow::conv(int *x, int*y)
{
    // wird nicht gebraucht da wir das Fenster eh relativ angeben und nicht absolut
    int relativ_x = *x;
    int relativ_y = *y;
    *x = relativ_x + 100;
    *y = relativ_y + 200;
    return (0);
}









/*
void MainWindow::on_actionChange_Params_triggered()
{
    ChangeBallParamsDlg dlg;
    dlg.set_value(radio);
    int result = dlg.exec();

    if (result ==QDialog::Accepted)
    {
        radio = dlg.get_value();
        ui->spinBox_radio->set_value(radio*2);
    }
}


void MainWindow::on_actionOpen_triggered()
{
    QFileDialog dlg;
    dlg.setLoQueSea(...);

    if(dlg.exec() == QDialog::Accepted)
    {
        QString filenmae )
    }

    QString result = QFileDialog::getOpenFileName(this,"Seleccione archvo de Datos", "/Path/to/file/");
    if(! result.isEmpty())
    {^
            QFile fid(result);
            if(fid.open(QIODevice::ReadOnly()))
            {
                int datio =QString(fid.readAll().toInt());
                ui->qNumA_spinbox->set_value(dato);
             }
}
}

*/
