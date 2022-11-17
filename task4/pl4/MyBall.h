#ifndef MYBALL_H
#define MYBALL_H

#include <QString>

class MyBall
{
public:
    MyBall();
    MyBall(int init_x, int init_y, int init_color, int init_radio, int init_velo_x, int init_velo_y);
private:
    double long velo_x = 0;
    double long velo_y = 0;
    int radio = 25;
    QString color_var = "darkgreen";
    int x = 220;
    int y = 120;
    int dx = 1;
    int dy = 1;

    //double long friccion = 0.001;
    float slow_friccion = 0.001;
    float slow_down_friccion = 0;

    int x_min = 20;
    int x_max = 420;

    int y_min = 20;
    int y_max = 220;

    QString color = "darkGreen";

public:
    void set_postion(int arg_x, int arg_y);
    int get_postion(int *arg_x, int*arg_y); //Pointer Cause we "give back "return" two Variabels
    int get_postion_x();
    int get_postion_y();
    void cal_new_postion();
    bool check_rand();

    void set_color(int arg_color);
    QString get_color();

    void set_radio(float arg_radio);
    int get_radio();


    void set_velo(int arg_velo_x, int arg_velo_y);
    void set_velo_x(int arg_velo_x);
    void set_velo_y(int arg_velo_y);
    int get_velo_x();
    int get_velo_y();
    void get_velo(int *arg_x, int*arg_y);

};

#endif // MYBALL_H
