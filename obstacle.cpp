#include "obstacle.h"


double RectangleObstacle::get_x() const{
    return x;
}

double RectangleObstacle::get_y() const{
    return y;
}

double RectangleObstacle::get_width() const{
    return width;
}

double RectangleObstacle::get_height() const{
    return height;
}




RectangleObstacle::RectangleObstacle(){
    x = 0; y = 0; width = 0; height = 0;
}

RectangleObstacle::RectangleObstacle(double X, double Y, double Width, double Height){
    x = X; y = Y; width = Width; height = Height;
}




double CircleObstacle::get_x() const{
    return x;
}

double CircleObstacle::get_y() const{
    return y;
}

double CircleObstacle::get_r() const{
    return r;
}



CircleObstacle::CircleObstacle(){
    x = 0; y = 0; r = 0;
}

CircleObstacle::CircleObstacle(double X, double Y, double R){
    x = X; y = Y; r = R;
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
        RectangleObstacle newObs = RectangleObstacle(Obs.get_x(), Obs.get_y(), Obs.get_width(), Obs.get_height());
        newL[i] = newObs;
    }
    RectangleObstacle newObs = RectangleObstacle(x,y,width,height);
    newL[N-1] = newObs;
    delete[] L;
    L = newL;
}

int RectangleObstacleList::get_N() const{
    return N;
}

RectangleObstacle RectangleObstacleList::get_ith_obstacle(int i) const{
    return L[i];
}

RectangleObstacle* RectangleObstacleList::get_L() const{
    return L;
}


void RectangleObstacleList::draw(){
    for(int c = 0; c<N; c++){
        RectangleObstacle Obs = L[c];
        Imagine::fillRect(Obs.get_x(),Obs.get_y(),Obs.get_width(),Obs.get_height(),Imagine::BLACK);
    }
}

void RectangleObstacleList::draw_as_exit(){
    for(int c = 0; c<N; c++){
        RectangleObstacle Obs = L[c];
        Imagine::fillRect(Obs.get_x(),Obs.get_y(),Obs.get_width(),Obs.get_height(),Imagine::GREEN);
    }
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

int CircleObstacleList::get_N() const{
    return N;
}

CircleObstacle CircleObstacleList::get_ith_obstacle(int i) const{
    return L[i];
}


void CircleObstacleList::draw(){
    for(int i = 0; i < N; i++){
        CircleObstacle Obs = L[i];
        Imagine::fillCircle(Obs.get_x(),Obs.get_y(),Obs.get_r(),Imagine::BLACK);
    }
}






