#include "obstacle.h"


double const RectangleObstacle::get_x(){
    return x;
}

double const RectangleObstacle::get_y(){
    return y;
}

double const RectangleObstacle::get_width(){
    return width;
}

double const RectangleObstacle::get_height(){
    return height;
}




RectangleObstacle::RectangleObstacle(){
    x = 0; y = 0; width = 0; height = 0;
}

RectangleObstacle::RectangleObstacle(double x, double y, double width, double height){
    x = x; y = y; width = width; height = height;
}




double const CircleObstacle::get_x(){
    return x;
}

double const CircleObstacle::get_y(){
    return y;
}

double const CircleObstacle::get_r(){
    return r;
}



CircleObstacle::CircleObstacle(){
    x = 0; y = 0; r = 0;
}

CircleObstacle::CircleObstacle(double x, double y, double r){
    x = x; y = y; r = r;
}
