#include "MainWindow.h"
#include "ui_ChangeBallParamsDlg.h"
#include "ui_MainWindow.h"
#include "ChangeBallParamsDlg.h"

#include <Utility.h>
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myLogger(log_path)
    , myUtiliy(xml_path)
{
    ui->setupUi(this);
    // Init the Timer for the Calcutaion of Ball
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    timer->start(100);
    // Init  the Timer for the Saving of the Position
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(OnTimer2()));
    timer2->start(50);

    // Init the the xml path
    // and load the defualt Settings form this file when staring the Program
    myUtiliy.set_xml_path(xml_path);
    QString xml = myUtiliy.ReadXml();
    QString xml_ball = myUtiliy.GetXmlStr(xml, "Ball");
    myBall.set_radio(myUtiliy.GetXmlStr(xml_ball, "radio").toInt());
    myBall.set_max_velo_x(myUtiliy.GetXmlStr(xml_ball, "max_velo_x").toDouble());
    myBall.set_max_velo_y(myUtiliy.GetXmlStr(xml_ball, "max_velo_y").toDouble());
    myBall.set_color(QColor(myUtiliy.GetXmlStr(xml_ball, "color_ball")));
    QString xml_board = myUtiliy.GetXmlStr(xml, "Board");
    board_color = QColor(myUtiliy.GetXmlStr(xml_board, "color_board"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_radio_valueChanged(int arg1)
{
    // function when the value of the radio spinbox is changed
   if (updateMyBallSpeed)
   {
        myBall.set_radio(arg1);
   }
}

void MainWindow::on_doubleSpinBox_velo_x_valueChanged(double arg_x)
{
   // function when the value of the velocity spinbox x is changed
   if (updateMyBallSpeed)
   {
        myBall.set_velo_x(arg_x);
   }
}

void MainWindow::on_doubleSpinBox_velo_y_valueChanged(double arg_y)
{
    // function when the value of the velocity spinbox y is changed
    if (updateMyBallSpeed)
    {
        myBall.set_velo_y(arg_y);
    }

}

void MainWindow::on_checkBox_pausa_clicked()
{
    // function when the value of the paus botton is clicked
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
    // This Timer Event is for Calculation the new Position of the Ball
    // also Draw the Ball on the new Position
    if(pausa==false)
    {
        myBall.cal_new_postion();
    }
    ui->label_x->setText(QString::number(myBall.get_postion_x()));
    ui->label_y->setText(QString::number(myBall.get_postion_y()));

    ui->label_x_2->setText(QString::number(myBall.get_max_velo_x()));
    ui->label_y_2->setText(QString::number(myBall.get_max_velo_x()));

    updateMyBallSpeed=false;
    ui->spinBox_radio->setValue(myBall.get_radio());
    ui->doubleSpinBox_velo_x->setValue(myBall.get_velo_x());
    ui->doubleSpinBox_velo_y->setValue(myBall.get_velo_y());
    updateMyBallSpeed=true;

   draw();
}

void MainWindow::OnTimer2()
{
    // This Timer Event is for Saving the Positions of the Ball
    // to a pos_log.txt file
    QString lastlog;
    QFile log("./pos_log.txt");
    QString log_msg = "X pos: " + QString::number(myBall.get_velo_x()) + " Y pos: " + QString::number(myBall.get_velo_y())+ "\n";

    if (log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        lastlog.append(leer.readAll());
        log.close();
    }
    if (log.open(QIODevice::WriteOnly)){
        QTextStream escribir(&log);
        escribir<<lastlog;
        escribir<<log_msg;
        log.close();
    }
}


void MainWindow::draw()
{
    // Draw our Board and Ball
    // Firt get all the values
    QPixmap pixmap(ui->label_board->size());
    QPainter painter(&pixmap);

    QSize board_size = ui->label_board->size();
    int board_hole_radius = 40;
    int board_wall_wide = 20;
    int board_wide = board_size.width();
    int board_hide = board_size.height();


    // Draw the Background of the Board
    painter.setBrush(board_color);
    painter.drawRect(0,0, board_wide, board_hide);     // painter.drawRect(x,y, w, h);

    // Draw the Walls
    painter.setBrush(Qt::darkYellow);
    painter.drawRect(0,0, board_wide, board_wall_wide);
    painter.drawRect(0,board_hide - board_wall_wide, board_wide, board_wall_wide);
    painter.drawRect(0,0, board_wall_wide, board_hide);
    painter.drawRect(board_wide - board_wall_wide ,0, board_wall_wide, board_hide);

    // Draw the Holes
    // Top
    painter.setBrush(Qt::darkGray);
    painter.drawEllipse(QPoint(0,0),board_hole_radius,board_hole_radius);
    painter.drawEllipse(QPoint(board_hide- board_wall_wide,0),int(board_hole_radius*0.75),int(board_hole_radius*0.75));
    painter.drawEllipse(QPoint(board_wide,0),board_hole_radius,board_hole_radius);

    // Lower
    painter.drawEllipse(QPoint(0,board_hide),board_hole_radius,board_hole_radius);
    painter.drawEllipse(QPoint(board_hide- board_wall_wide,board_hide),int(board_hole_radius*0.75),int(board_hole_radius*0.75));
    painter.drawEllipse(QPoint(board_wide,board_hide),board_hole_radius,board_hole_radius);

    // Draw the Ball
    ui->label_board->setPixmap(pixmap);
    QPen pen(Qt::DashLine);
    pen.setColor(Qt::green);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.setBrush(myBall.get_color());
    painter.drawEllipse(QPoint(myBall.get_postion_x(),myBall.get_postion_y()), myBall.get_radio(),myBall.get_radio());
    ui->label_board->setPixmap(pixmap);
}


void MainWindow::on_actionChange_Params_triggered()
{
    // Tap Options
    // Here the User can Change Options like Ball Color and Maximal Speed
    ChangeBallParamsDlg dlg;

    // Give the Current infos, Variables to the Option Menu
    dlg.set_value_radio(myBall.get_radio());
    dlg.set_max_value_velo_x(myBall.get_max_velo_x());
    dlg.set_max_value_velo_y(myBall.get_max_velo_y());
    dlg.set_value_ball_color(myBall.get_color());
    dlg.set_value_board_color(board_color);

    // If Accepted Read the Values and Log them
    if (dlg.exec() == QDialog::Accepted)
    {
        QString log_msg = "New Params: ";
        myBall.set_radio(dlg.get_value_radio());
        log_msg.append("Radio ");
        log_msg.append(QString::number(dlg.get_value_radio()));
        log_msg.append(", ");
        ui->spinBox_radio->setValue(myBall.get_radio());

        myBall.set_max_velo(dlg.get_max_value_velo_x(),dlg.get_max_value_velo_y());
        log_msg.append("velo_x_max ");
        log_msg.append( QString::number(dlg.get_max_value_velo_x()));
        log_msg.append(", ");

        log_msg.append("velo_y_max ");
        log_msg.append( QString::number(dlg.get_max_value_velo_y()));
        log_msg.append(", ");

        myBall.set_color(dlg.get_value_ball_color_dialog());
        log_msg.append("Color Ball ");
        log_msg.append(dlg.get_value_board_color_dialog().name());
        log_msg.append(", ");
        board_color = dlg.get_value_board_color_dialog();
        log_msg.append("Color Board ");
        log_msg.append(dlg.get_value_board_color_dialog().name());
        log_msg.append("\n");
        myLogger.OnAddToLog(log_msg);
    }
}


void MainWindow::on_actionOpen_triggered()
{
    // Tap Open File
    // Here the User can Open File for Reading in Data
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "./", tr("*.txt"));
    if (fileName == "./")
    {
        fileName = xml_path;
    }
    else {
        try {
            myUtiliy.set_xml_path(fileName);
            QString xml = myUtiliy.ReadXml();
            QString xml_ball = myUtiliy.GetXmlStr(xml, "Ball");
            myBall.set_radio(myUtiliy.GetXmlStr(xml_ball, "radio").toInt());
            myBall.set_max_velo_x(myUtiliy.GetXmlStr(xml_ball, "max_velo_x").toDouble());
            myBall.set_max_velo_y(myUtiliy.GetXmlStr(xml_ball, "max_velo_y").toDouble());
            myBall.set_color(QColor(myUtiliy.GetXmlStr(xml_ball, "color_ball")));
            QString xml_board = myUtiliy.GetXmlStr(xml, "Board");
            board_color = QColor(myUtiliy.GetXmlStr(xml_board, "color_board"));
        } catch (...) {
        }
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // When the User Clicks on the Board
    // checks the Possition of the click
    // calculate the distance to the Ball
    // change the velocity of the Ball accordingly
    QPoint pos_board = ui->label_board->pos();
    int mouse_x = event->x() - pos_board.x();
    int mouse_y = event->y() - pos_board.y();
    int ball_pos_x = myBall.get_postion_x();
    int ball_pos_y = myBall.get_postion_y();
    int distancia_x = (ball_pos_x - mouse_x);
    int distancia_y = (ball_pos_y - mouse_y);
    if(distancia_x<0)
     {
        myBall.set_dx(-1);
        distancia_x *= -1;
        distancia_y = distancia_y/2;
     }
    else
    {
        myBall.set_dx(1);
    }

    if(distancia_y<0)
     {
        myBall.set_dy(-1);
        distancia_y *= -1;
        distancia_y = distancia_y/2;
     }
    else
    {
        myBall.set_dy(1);
    }

    if(distancia_x > 99)
    {
        distancia_x = 99;
    }
    if(distancia_y > 99)
    {
        distancia_y = 99;
    }
    myBall.set_velo_x(distancia_x);
    myBall.set_velo_y(distancia_y);
}


void MainWindow::on_pushButton_reboot_clicked()
{
    // When Button reboot is clicked
    // Move Ball in the Middel of the Board
    // Set volcity to Zero
    myBall.set_velo(0,0);
    myBall.set_postion(220,120);
}

