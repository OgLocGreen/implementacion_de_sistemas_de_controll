#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    int result;
    int timeOut_ms;
    int counter = 0;

public slots:

private slots:
    void on_qSum_pushButton_clicked();
    void on_qSum_a_spinBox_valueChanged(int arg1);
    void OnMyTimer();
    void on_qMyData_listWidget_itemSelectionChanged();
};
#endif // MAINWINDOW_H
