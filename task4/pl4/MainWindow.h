#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

#include "MyBall.h"

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_radio_valueChanged(int arg1);
    void on_spinBox_velo_valueChanged(int arg1);
    void on_pushButton_color_clicked();
    void on_checkBox_pausa_clicked();

    void OnTimer();

};
#endif // MAINWINDOW_H
