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

   x = x+dx*velo_x;
   y = y+dy*velo_y;

   // Also datatype what should i use?
   // is double long good? cause better to cacluclate small changes or is it to much?

   velo_x -= velo_x*friccion;
   velo_y -= velo_y*friccion;


   /*
   if(slow_down_friccion == 10)
   {
       velo_x -= velo_x*slow_friccion;
       velo_y -= velo_y*slow_friccion;
       slow_down_friccion = 0;
   }
   slow_down_friccion +=1;
   */

}

void MyBall::set_color(int arg_color)
{
    color_var = arg_color;
}

QString MyBall::get_color()
{
    /*
    switch(color_var) {
      case "darkGreen":
        return Qt::darkGreen;
      case "red":
        return Qt::red;
      case "blue":
        return Qt::blue;
      default:
        return Qt::darkGreengreen;
    }
    */
}


void MyBall::set_radio(float arg_radio)
{
    radio = arg_radio;
}

int MyBall::get_radio()
{
    return radio;
}


void MyBall::set_velo(int arg_velo_x, int arg_velo_y)
{
    velo_x = arg_velo_x;
    velo_y = arg_velo_y;
}

void MyBall::set_velo_x(int arg_velo_x)
{
    velo_x = arg_velo_x;
}

void MyBall::set_velo_y(int arg_velo_y)
{
    velo_y = arg_velo_y;
}

int MyBall::get_velo_x()
{
    return int(velo_x);
}

int MyBall::get_velo_y()
{
    return int(velo_y);
}

void MyBall::get_velo(int *arg_x, int*arg_y)
{
    *arg_x = int(velo_x);
    *arg_y = int(velo_y);
}

