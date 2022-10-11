#ifndef MYBALL_H
#define MYBALL_H

#include <QString>

class MyBall
{
public:
    MyBall();
    MyBall(float init_x, float init_y, int init_color, float init_radio, float init_velo);
private:
    float velo = 0;
    float radio = 0;
    int color_var = 1;
    float x = 0;
    float y = 0;
    float dx = 1;
    float dy = 1;

    enum color {red = 1, yellow = 2, green = 3};

public:
    void set_postion(float arg_x, float arg_y);
    float get_postion();
    float get_postion_x();
    float get_postion_y();
    void cal_new_postion();

    void set_color(int arg_color);
    int get_color();

    void set_radio(float arg_radio);
    float get_radio();


    void set_velo(float arg_velo);
    float get_velo();
};

#endif // MYBALL_H
