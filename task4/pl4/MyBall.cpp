#include "MyBall.h"

MyBall::MyBall()
{

}

MyBall::MyBall(int init_x, int init_y, int init_color, int init_radio, int init_velo_x, int init_velo_y)
{
    velo_x = init_velo_x;
    velo_y = init_velo_y;
    radio = init_radio;
    x = init_x;
    y = init_y;
    color_var = init_color;
}

void MyBall::set_postion(int arg_x, int arg_y)
{
    x = arg_x;
    y = arg_y;
}

int MyBall::get_postion(int *arg_x, int*arg_y)
{
    // is this right?
    // its better because we dont use a second Variable and just Write it direkt in the arg_x?
    // and also we can get two Variables back
    // but to run this Variable you have to give a arg the adresse like:
    // example:     int x,y;
    //              get_position(&x, &y)
    *arg_x = x;
    *arg_y = y;
    return (0);
}

int MyBall::get_postion_x()
{
    return x;
}
int MyBall::get_postion_y()
{
    return y;
}

void MyBall::cal_new_postion()
{

   // First Calculate dirrection of the Ball then what Wall its going to hit ...

    if (dx > 0 and dy > 0) // Diagonal Down Right
    {
        if(y + radio >= y_max) // Bottom Side
        {
            dy = -1;
        }
        else if(x + radio >= x_max) // Right Side
        {
           dx = -1;
        }
    }

    if (dx > 0 and dy <0) // Diagonal Top Right
    {
        if(y - radio <= y_min) // Top Side
        {
            dy = 1;
        }
        else if(x + radio >= x_max) // Right Side
        {
           dx = -1;
        }
    }

    if (dx < 0 and dy <0) // Diagonal Top Left
    {
        if(y - radio <= y_min) // Top Side
        {
            dy = 1;
        }
        else if(x - radio <= x_min) // Left Side
        {
            dx = 1;
        }
    }

    if (dx < 0 and dy > 0) // Diagonal Down Left
    {
        if(y + radio >= y_max) // Bottom Side
        {
            dy = -1;
        }
        else if(x - radio <= x_min) // Left Side
        {
            dx = 1;
        }
    }


    /*
   // Calculate Position
   if(y + radio == y_max) // Bottom Side
   {
       dy = -1;
   }
    else if(x + radio == x_max) // Right Side
   {
       dx = -1;
   }
   else if(y - radio == y_min) // Top Side
   {
       dy = 1;
   }
   else if(x - radio == x_min) // Left Side
   {
       dx = 1;
   }
   */


   // calculate new Possiton with Friccion
   x = x+dx*velo_x;
   y = y+dy*velo_y;

   velo_x -= velo_x*friccion;
   velo_y -= velo_y*friccion;

   if (velo_x < 0.1)
   {
       velo_x = 0;
   }
   if (velo_y < 0.1)
   {
       velo_y = 0;
   }

}

void MyBall::set_color(QColor arg_color)
{
    color_var = arg_color;
}

QColor MyBall::get_color()
{
    return color_var;
}


void MyBall::set_radio(float arg_radio)
{
    radio = arg_radio;
}

int MyBall::get_radio()
{
    return radio;
}


void MyBall::set_velo(double arg_velo_x, double arg_velo_y)
{
    velo_x = arg_velo_x;
    velo_y = arg_velo_y;
}

void MyBall::set_velo_x(double arg_velo_x)
{
    velo_x = arg_velo_x;
}

void MyBall::set_velo_y(double arg_velo_y)
{
    velo_y = arg_velo_y;
}

double MyBall::get_velo_x()
{
    return double(velo_x);
}

double MyBall::get_velo_y()
{
    return double(velo_y);
}

void MyBall::get_velo(double *arg_x, double*arg_y)
{
    *arg_x = double(velo_x);
    *arg_y = double(velo_y);
}

void MyBall::set_d(int arg_dx, int arg_dy)
{
    dx = arg_dx;
    dy = arg_dy;
}

void MyBall::set_dx(int arg_dx)
{
    dx = arg_dx;
}

void MyBall::set_dy(int arg_dy)
{
    dy = arg_dy;
}
