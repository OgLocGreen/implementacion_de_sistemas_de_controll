#include "MyBall.h"

MyBall::MyBall()
{
}


MyBall::MyBall(int init_x, int init_y, int init_color,int init_radio, int init_max_velo_x, int init_max_velo_y)
{
    // Init the Class MyBall with an non-Default Constructor
    max_velo_x = init_max_velo_x;
    max_velo_y = init_max_velo_y;
    radio = init_radio;
    x = init_x;
    y = init_y;
    color_var = init_color;
}

void MyBall::set_postion(int arg_x, int arg_y)
{
    // Setter function for the Postion
    x = arg_x;
    y = arg_y;
}

int MyBall::get_postion(int *arg_x, int*arg_y)
{
    // Getter funtction to Return both x and y position in one function
    *arg_x = x;
    *arg_y = y;
    return (0);
}

int MyBall::get_postion_x()
{
    // getter for x
    return x;
}
int MyBall::get_postion_y()
{
    // getter for y
    return y;
}

void MyBall::cal_new_postion()
{

   // First Calculate dirrection of the Ball then what Wall its going to hit
   // and then change the velocity depending on it
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

    // calculate new Possiton with Friccion
    // dx and dy is for the sign couse i only use unsigned velocity
    // the friccion is that the Ball slows down
    x = x+dx*velo_x;
    y = y+dy*velo_y;

    velo_x -= velo_x*friccion;
    velo_y -= velo_y*friccion;

    // because the Friccion is just a Mulitpicaction
    // the speed would never be Zero
    // there for we set it so Zero after the threshold of 0.1
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
    // setter color
    color_var = arg_color;
}

QColor MyBall::get_color()
{
    // getter color
    return color_var;
}


void MyBall::set_radio(float arg_radio)
{
    // setter raido
    radio = arg_radio;
}

int MyBall::get_radio()
{
    // getter radio
    return radio;
}


void MyBall::set_max_velo(double arg_max_velo_x, double arg_max_velo_y)
{
    // setter maximal velocity
    max_velo_x = arg_max_velo_x;
    max_velo_y = arg_max_velo_y;
}

void MyBall::set_max_velo_x(double arg_max_velo_x)
{
    // setter maximal velocity x
    max_velo_x = arg_max_velo_x;
}

void MyBall::set_max_velo_y(double arg_max_velo_y)
{
    // setter maximal velocity y
    max_velo_y = arg_max_velo_y;
}

double MyBall::get_max_velo_x()
{
    // getter maximal velocity x
    return double(max_velo_x);
}

double MyBall::get_max_velo_y()
{
    // getter maximal velocity y
    return double(max_velo_y);
}

void MyBall::get_max_velo(double *max_arg_x, double*max_arg_y)
{
    // getter maximal velocity
    *max_arg_x = double(max_velo_x);
    *max_arg_y = double(max_velo_y);
}


void MyBall::set_velo(double arg_velo_x, double arg_velo_y)
{
    // setter of velocity
    // checks if the velocity is bigger then the maximum alows
    // if its bigger takes the maximal value as actual velocity
    if(arg_velo_x > max_velo_x)
        velo_x = max_velo_x;
    else
        velo_x = arg_velo_x;

    if(arg_velo_y > max_velo_y)
        velo_y = max_velo_y;
    else
        velo_y = arg_velo_y;
}

void MyBall::set_velo_x(double arg_velo_x)
{
    // setter of velocity x
    // checks if the velocity is bigger then the maximum alows
    // if its bigger takes the maximal value as actual velocity x
    if(arg_velo_x > max_velo_x)
        velo_x = max_velo_x;
    else
        velo_x = arg_velo_x;
}

void MyBall::set_velo_y(double arg_velo_y)
{
    // setter of velocity y
    // checks if the velocity is bigger then the maximum alows
    // if its bigger takes the maximal value as actual velocity y
    if(arg_velo_y > max_velo_y)
        velo_y = max_velo_y;
    else
        velo_y = arg_velo_y;
}

double MyBall::get_velo_x()
{
    // getter velocity x
    return double(velo_x);
}

double MyBall::get_velo_y()
{
    // getter velocity y
    return double(velo_y);
}

void MyBall::get_velo(double *arg_x, double*arg_y)
{
    // getter velocity
    *arg_x = double(velo_x);
    *arg_y = double(velo_y);
}


void MyBall::set_d(int arg_dx, int arg_dy)
{
    // setter dy,dx
    dx = arg_dx;
    dy = arg_dy;
}

void MyBall::set_dx(int arg_dx)
{
    // setter dx
    dx = arg_dx;
}

void MyBall::set_dy(int arg_dy)
{
    // setter dy
    dy = arg_dy;
}
