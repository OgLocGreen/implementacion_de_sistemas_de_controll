#ifndef MYBALL_H
#define MYBALL_H

#include <QString>
#include <QColor>

class MyBall
{
public:
    MyBall();
    MyBall(int init_x, int init_y, int init_color, int init_radio, int init_max_velo_x, int init_max_velo_y);
private:
    double velo_x = 0;
    double velo_y = 0;

    double max_velo_x = 99;
    double max_velo_y = 99;
    int radio = 25;
    QColor color_var = "black";
    double x = 220;
    double y = 120;
    int dx = 1;
    int dy = 1;



    double friccion = 0.05;
    int x_min = 20;
    int x_max = 420;
    int y_min = 20;
    int y_max = 220;

public:
    void set_postion(int arg_x, int arg_y);
    int get_postion(int *arg_x, int*arg_y); //Pointer Cause we "give back "return" two Variabels
    int get_postion_x();
    int get_postion_y();
    void cal_new_postion();
    bool check_rand();

    void set_color(QColor arg_color);
    QColor get_color();

    void set_radio(float arg_radio);
    int get_radio();


    void set_velo(double arg_velo_x, double arg_velo_y);
    void set_velo_x(double arg_velo_x);
    void set_velo_y(double arg_velo_y);
    double get_velo_x();
    double get_velo_y();
    void get_velo(double *arg_x, double*arg_y);

    void set_max_velo(double arg_max_velo_x, double arg_max_velo_y);
    void set_max_velo_x(double arg_max_velo_x);
    void set_max_velo_y(double arg_max_velo_y);
    double get_max_velo_x();
    double get_max_velo_y();
    void get_max_velo(double *arg_max_x, double*arg_max_y);

   void set_d(int arg_dx, int arg_dy);
   void set_dx(int arg_dx);
   void set_dy(int arg_dy);



};

#endif // MYBALL_H
