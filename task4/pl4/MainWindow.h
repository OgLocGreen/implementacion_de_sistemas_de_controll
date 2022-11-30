#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include "MyBall.h"
#include "OpenFile.h"
#include "Utility.h"
#include <Log.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
     Ui::MainWindow *ui;
    bool updateMyBallSpeed=true;
    bool pausa;
    QTimer myTimer;
    MyBall myBall;
    OpenFile myFile;
    int mouse_x;
    int mouse_y;
    QColor board_color = "darkGreen";
    Utility myUtilityManager;

    QString log_path = "./log_file.txt";  // #7
    Log myLogger;

    QString xml_path = "./xml_file.txt"; // #7
    Utility myUtiliy;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void load_data();
    QString XmlGetStr(const QString &textXml, const QString &tagXml);

private slots:
    void on_spinBox_radio_valueChanged(int arg1);
    void on_doubleSpinBox_velo_y_valueChanged(double arg_y);
    void on_doubleSpinBox_velo_x_valueChanged(double arg_x);
    void on_checkBox_pausa_clicked();

    void OnTimer();

    void draw();
    float conv(int *x, int *y);


    void on_actionChange_Params_triggered();
    void on_actionOpen_triggered();

    virtual void mousePressEvent(QMouseEvent *event);

    void on_checkBox_reboot_stateChanged(int arg1);
    void on_checkBox_reboot_clicked();
};
#endif // MAINWINDOW_H
