#include "pieton.h"





double const Pieton::get_x(){
    return x;
}

double const Pieton::get_y(){
    return y;
}

double const Pieton::get_r(){
    return r;
}

double const Pieton::get_m(){
    return m;
}

double const Pieton::get_vx(){
    return vx;
}

double const Pieton::get_vy(){
    return vy;
}

double const Pieton::get_e(){
    return e;
}






void Pieton::UpdatePos(){
    x = x + vx/fps;
    y = y + vy/fps;
}





Pieton::Pieton(){
    x = 0; y = 0; r = 1; m = 1; vx = 0; vy = 0; e = 0;
}

Pieton::Pieton(double x, double y){
    x = x; y = y; r = 1; m = 1; vx = 0; vy = 0; e = 0;
}

Pieton::Pieton(double x, double y, double r){
    x = x; y = y; r = r; m = 1; vx = 0; vy = 0; e = 0;
}

Pieton::Pieton(double x, double y, double r, double m){
    x = x; y = y; r = r; m = m; vx = 0; vy = 0; e = 0;
}

Pieton::Pieton(double x, double y, double r, double m, double vx, double vy){
    x = x; y = y; r = r; m = m; vx = vx; vy = vy; e = 0;
}

Pieton::Pieton(double x, double y, double r, double m, double vx, double vy, double e){
    x = x; y = y; r = r; m = m; vx = vx; vy = vy; e = e;
}


