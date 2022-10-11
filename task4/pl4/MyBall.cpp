#include "MyBall.h"

MyBall::MyBall()
{

}

MyBall::MyBall(float init_x, float init_y, int init_color, float init_radio, float init_velo)
{
    velo = init_velo;
    radio = init_radio;
    x = init_x;
    y = init_y;
    color_var = init_color;
}

void MyBall::set_postion(float arg_x, float arg_y)
{
    x = arg_x;
    y = arg_y;
}

float MyBall::get_postion()
{
    return (x,y);
}

float MyBall::get_postion_x()
{
    return x;
}
float MyBall::get_postion_y()
{
    return y;
}

void MyBall::cal_new_postion()
{
    x = dx*velo+x;
    y = dy*velo+y;
}

void MyBall::set_color(int arg_color)
{
    color_var = arg_color;
}

int MyBall::get_color()
{
    return color_var;
}

void MyBall::set_radio(float arg_radio)
{
    radio = arg_radio;
}

float MyBall::get_radio()
{
    return radio;
}


void MyBall::set_velo(float arg_velo)
{
    velo = arg_velo;
}

float MyBall::get_velo()
{
    return velo;
}

