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






void Pieton::UpdatePos(RectangleObstacleList RectObs, CircleObstacleList CircleList){
    bool b = false;
    int i = 0;
    while((i < RectObs.get_N()) and (not(b))){
        RectObsColl(RectObs.get_ith_obstacle(i), b);
    }
}





Pieton::Pieton(){
    x = 0; y = 0; r = 1; m = 1; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double x, double y){
    x = x; y = y; r = 1; m = 1; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double x, double y, double r){
    x = x; y = y; r = r; m = 1; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double x, double y, double r, double m){
    x = x; y = y; r = r; m = m; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double x, double y, double r, double m, double vx, double vy){
    x = x; y = y; r = r; m = m; vx = vx; vy = vy; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double x, double y, double r, double m, double vx, double vy, double e){
    x = x; y = y; r = r; m = m; vx = vx; vy = vy; e = e; ox = -1; oy = -1;
}




void Pieton::RectObsColl(RectangleObstacle Obs, bool& b){
    double t; double u; double coor[8];
    double arg_vect = arg(vx,vy);
    if(arg_vect <= - 1.570796327){
        modify(coor,x,vx/fps,y,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y(),0);
        intersection(coor,t,u);
        if(t > 1 or u > 1 or t < 0 or u < 0){
            modify(coor,x,vx/fps,y,vy/fps,Obs.get_x()+Obs.get_width(),0,Obs.get_y(),Obs.get_height());
            intersection(coor,t,u);
            if(t > 1 or u > 1 or t < 0 or u < 0){
                b = false;
            }
            else{
                b = true;
                x += t*vx/fps + r + 1e-10;
                y += t*vy/fps - r*vy/vx - 1e-10;
            }
        }
        else{
            b = true;
            x += t*vx/fps - vx*r/vy + 1e-10;
            y += t*vy/fps - r - 1e-10;
        }
    }
    else{
        if(arg_vect <=0){
            modify(coor,x,vx/fps,y,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y(),0);
            intersection(coor,t,u);
            if(t > 1 or u > 1 or t < 0 or u < 0){
                modify(coor,x,vx/fps,y,vy/fps,Obs.get_x(),0,Obs.get_y(),Obs.get_height());
                intersection(coor,t,u);
                if(t > 1 or u > 1 or t < 0 or u < 0){
                    b = false;
                }
                else{
                    b = true;
                    x += t*vx/fps - r - 1e-10;
                    y += t*vy/fps - r*vy/vx - 1e-10;
                }
            }
            else{
                b = true;
                x += t*vx/fps - vx*r/vy - 1e-10;
                y += t*vy/fps - r - 1e-10;
            }
        }
        else{
            if(arg_vect <= 1.570796327){
                modify(coor,x,vx/fps,y,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y()+Obs.get_height(),0);
                intersection(coor,t,u);
                if(t > 1 or u > 1 or t < 0 or u < 0){
                    modify(coor,x,vx/fps,y,vy/fps,Obs.get_x(),0,Obs.get_y(),Obs.get_height());
                    intersection(coor,t,u);
                    if(t > 1 or u > 1 or t < 0 or u < 0){
                        b = false;
                    }
                    else{
                        b = true;
                        x += t*vx/fps - r - 1e-10;
                        y += t*vy/fps - r*vy/vx + 1e-10;
                    }
                }
                else{
                    b = true;
                    x += t*vx/fps - vx*r/vy - 1e-10;
                    y += t*vy/fps + r + 1e-10;
                }
            }
            else{
                modify(coor,x,vx/fps,y,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y()+ Obs.get_height(),0);
                intersection(coor,t,u);
                if(t > 1 or u > 1 or t < 0 or u < 0){
                    modify(coor,x,vx/fps,y,vy/fps,Obs.get_x()+Obs.get_width(),0,Obs.get_y(),Obs.get_height());
                    intersection(coor,t,u);
                    if(t > 1 or u > 1 or t < 0 or u < 0){
                        b = false;
                    }
                    else{
                        b = true;
                        x += t*vx/fps + r + 1e-10;
                        y += t*vy/fps - r*vy/vx + 1e-10;
                    }
                }
                else{
                    b = true;
                    x += t*vx/fps - vx*r/vy + 1e-10;
                    y += t*vy/fps + r + 1e-10;
                }
            }
        }
    }
}




void Pieton::Draw(){
    Imagine::drawCircle(x,y,r,Imagine::BLACK);
}

void Pieton::Erase(){
    Imagine::drawCircle(ox,oy,r,Imagine::WHITE);
}
