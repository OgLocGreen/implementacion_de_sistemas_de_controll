#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include "MyBall.h"
#include "Utility.h"
#include <Log.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    // Init all needed Classes and Variables
     Ui::MainWindow *ui;

    // Bool Variable to block the Update of the speed till the Calculaction is done
    bool updateMyBallSpeed=true;

    // Bool Variable for doing a Paus when the User want it
    bool pausa;

    // Init the Ball Class
    // This Class does alle the Ball Stuff
    // For example: Calculation the Pos, getter and setter functions for the Variabales
    MyBall myBall;
    // Init the Board Color couse we dont have a Board Class
    QColor board_color = "darkGreen";

    // Init the Logger Class with the right Path
    // This Class does the Logging of the Options and what changed when
    QString log_path = "./log_file.txt";
    Log myLogger;

    // Init the Utility Class with the right path
    // This Class is using diffrent small funcitons
    QString xml_path = "./../xml_file.txt";
    Utility myUtiliy;

public:
    // Here Declare our Main Window
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_radio_valueChanged(int arg1);
    void on_doubleSpinBox_velo_y_valueChanged(double arg_y);
    void on_doubleSpinBox_velo_x_valueChanged(double arg_x);
    void on_checkBox_pausa_clicked();

    void OnTimer();
    void OnTimer2();
    void draw();

    void on_actionChange_Params_triggered();
    void on_actionOpen_triggered();

    virtual void mousePressEvent(QMouseEvent *event);
    void on_pushButton_reboot_clicked();
};
#endif // MAINWINDOW_H
