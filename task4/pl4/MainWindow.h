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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
     Ui::MainWindow *ui;

    bool pausa;
    QTimer myTimer;
    MyBall myBall;
    OpenFile myFile;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void load_data();
    QString XmlGetStr(const QString &textXml, const QString &tagXml);

private slots:
    void on_spinBox_radio_valueChanged(int arg1);
    void on_spinBox_velo_y_valueChanged(int arg_y);
    void on_spinBox_velo_x_valueChanged(int arg_x);
    void on_checkBox_pausa_clicked();

    void OnTimer();

    void draw_board();
    void draw_ball(int ball_pos_x, int ball_pos_y);
    float conv(int *x, int *y);


    void on_actionChange_Params_triggered();
    void on_actionOpen_triggered();

    virtual void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
