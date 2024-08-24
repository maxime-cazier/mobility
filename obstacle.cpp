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





RectangleObstacleList::RectangleObstacleList(){
    N = 0;
    L = new RectangleObstacle[0];
}


void RectangleObstacleList::AddRectangleObstacle(double x, double y, double width, double height){
    N += 1;
    RectangleObstacle * newL = new RectangleObstacle[N];
    for(int i = 0; i < N - 1; i++){
        RectangleObstacle Obs = L[i] ;
        newL[i] = RectangleObstacle(Obs.get_x(), Obs.get_y(), Obs.get_width(), Obs.get_height());
    }
    newL[N-1] = RectangleObstacle(x,y,width,height);
    delete[] L;
    L = newL;
}

int const RectangleObstacleList::get_N(){
    return N;
}

RectangleObstacle const RectangleObstacleList::get_ith_obstacle(int i){
    return L[i];
}






CircleObstacleList::CircleObstacleList(){
    N = 0;
    L = new CircleObstacle[0];
}


void CircleObstacleList::AddCircleObstacle(double x, double y, double r){
    N += 1;
    CircleObstacle * newL = new CircleObstacle[N];
    for(int i = 0; i < N - 1; i++){
        CircleObstacle Obs = L[i] ;
        newL[i] = CircleObstacle(Obs.get_x(), Obs.get_y(), Obs.get_r());
    }
    newL[N-1] = CircleObstacle(x,y,r);
    delete[] L;
    L = newL;
}

int const CircleObstacleList::get_N(){
    return N;
}

CircleObstacle const CircleObstacleList::get_ith_obstacle(int i){
    return L[i];
}
