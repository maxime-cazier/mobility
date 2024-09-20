#include "Direction.h"

double direction::get_d_x(){
    return d_x;
}

double direction::get_d_y(){
    return d_y;
}

direction::direction(double x, double y){
    d_x = x;
    d_y = y;
}

direction operator*(double k, direction d){
    direction newdir(k*d.get_d_x(),k*d.get_d_y());
    return newdir;
}


void direction::change_x(double X){
    d_x = X;
}

void direction::change_y(double Y){
    d_y = Y;
}
