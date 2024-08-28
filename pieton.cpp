#include "pieton.h"
#include "Direction.h"
#include "util.h"





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

double const Pieton::get_vdesx(){
    return vdesx;
}

double const Pieton::get_vdesy(){
    return vdesy;
}




void Pieton::UpdatePos(RectangleObstacleList RectObs){
    ox = x;
    oy = y;
    bool b = false;
    int i = 0;
    while((i < RectObs.get_N()) and (not(b))){
        RectObsColl(RectObs.get_ith_obstacle(i), b);
    }
    if(not(b)){
        x += vx/fps;
        y += vy/fps;
    }
}





Pieton::Pieton(){
    x = 0; y = 0; r = 1; m = 1; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double X, double Y){
    x = X; y = Y; r = 1; m = 1; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double X, double Y, double R){
    x = X; y = Y; r = R; m = 1; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double X, double Y, double R, double M){
    x = X; y = Y; r = R; m = M; vx = 0; vy = 0; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = 0; ox = -1; oy = -1;
}

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY, double E){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = E; ox = -1; oy = -1;
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

direction Pieton::force_attrac(){
    direction d(m/tau*(vdesx-vx),m/tau*(vdesy-vy));
    return d;
}

direction Pieton::force_repuls(Pieton p_ext){
    double dij_x, dij_y;
    dij_x=x-p_ext.get_x();
    dij_y=y-p_ext.get_y();
    direction d(dij_x/std::sqrt(dij_x*dij_x+dij_y*dij_y),dij_y/std::sqrt(dij_x*dij_x+dij_y*dij_y));
    return A_repuls*std::exp()*d;
}




