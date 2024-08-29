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




void Pieton::change_x(double X){
    x = X;
}

void Pieton::change_y(double Y){
    y = Y;
}

void Pieton::change_vx(double VX){
    vx = VX;
}

void Pieton::change_vy(double VY){
    vy = VY;
}







void Pieton::UpdatePos(RectangleObstacleList RectObs, CircleObstacleList CircObs, double addvx, double addvy){
    ox = x;
    oy = y;
    vx += addvx;
    vy += addvy;
    bool b = false;
    int i = 0;
    while((i < RectObs.get_N())){
        RectObsColl(RectObs.get_ith_obstacle(i), b);
        i++;
    }
    i = 0;
    while((i < CircObs.get_N())){
        CircleObsColl(CircObs.get_ith_obstacle(i), b);
        i++;
    }
    if(not(b)){
        x += vx/fps;
        y += vy/fps;
    }
    vx -= addvx;
    vy -= addvy;
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

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY, double E, double Vdesx, double Vdesy){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = E; ox = -1; oy = -1; vdesx = Vdesx; vdesy = Vdesy;
}




void Pieton::RectObsColl(RectangleObstacle Obs, bool& b){
    double t; double u; double coor[8];
    double arg_vect = arg(vx,vy);
    if(arg_vect <= - 1.570796327){
        modify(coor,x-std::sin(arg_vect)*r,vx/fps,y-std::cos(arg_vect)*r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y(),0);
        intersection(coor,t,u);
        if(t > 1 or u > 1 or t < 0 or u < 0){
            modify(coor,x+std::cos(arg_vect)*r,vx/fps,y-std::sin(arg_vect)*r,vy/fps,Obs.get_x()+Obs.get_width(),0,Obs.get_y(),Obs.get_height());
            intersection(coor,t,u);
            if(t > 1 or u > 1 or t < 0 or u < 0){
                double dirx = (x+vx/fps - (Obs.get_width()+Obs.get_x()));
                double diry = (y+vy/fps - Obs.get_y());
                double argdir = arg(dirx,diry);
                if(dirx*dirx + diry*diry <= r*r){
                    b = true;
                    x = Obs.get_width()+Obs.get_x() + r*cos(argdir) + 0.05;
                    y = Obs.get_y() - r*sin(argdir) - 0.05;
                }
                else{
                    b = false;
                }
            }
            else{
                b = true;
                x += t*vx/fps + 1e-10;
                y += vy/fps - 1e-10;
            }
        }
        else{
            b = true;
            x += vx/fps + 1e-10;
            y += t*vy/fps - 1e-10;
        }
    }
    else{
        if(arg_vect <=0){
            modify(coor,x+std::sin(arg_vect)*r,vx/fps,y+std::cos(arg_vect)*r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y(),0);
            intersection(coor,t,u);
            //std::cout << t << std::endl << u << std::endl;
            if(t > 1 or u > 1 or t < 0 or u < 0){
                modify(coor,x+std::cos(arg_vect)*r,vx/fps,y-std::sin(arg_vect)*r,vy/fps,Obs.get_x(),0,Obs.get_y(),Obs.get_height());
                intersection(coor,t,u);
                if(t > 1 or u > 1 or t < 0 or u < 0){
                    double dirx = (x+vx/fps - (Obs.get_x()));
                    double diry = (y+vy/fps - Obs.get_y());
                    double argdir = arg(dirx,diry);
                    if(dirx*dirx + diry*diry <= r*r){
                        b = true;
                        x = Obs.get_x() + r*cos(argdir) - 0.05;
                        y = Obs.get_y() - r*sin(argdir) - 0.05;
                    }
                    else{
                        b = false;
                    }
                }
                else{
                    b = true;
                    x += t*vx/fps - 1e-10;
                    y += vy/fps - 1e-10;
                }
            }
            else{
                b = true;
                x += vx/fps - 1e-10;
                y += t*vy/fps - 1e-10;
            }
        }
        else{
            if(arg_vect <= 1.570796327){
                modify(coor,x-std::sin(arg_vect)*r,vx/fps,y-std::cos(arg_vect)*r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y()+Obs.get_height(),0);
                intersection(coor,t,u);
                if(t > 1 or u > 1 or t < 0 or u < 0){
                    modify(coor,x+std::cos(arg_vect)*r,vx/fps,y-std::sin(arg_vect)*r,vy/fps,Obs.get_x(),0,Obs.get_y(),Obs.get_height());
                    intersection(coor,t,u);
                    if(t > 1 or u > 1 or t < 0 or u < 0){
                        double dirx = (x+vx/fps - (Obs.get_x()));
                        double diry = (y+vy/fps - (Obs.get_y()+Obs.get_height()));
                        double argdir = arg(dirx,diry);
                        if(dirx*dirx + diry*diry <= r*r){
                            b = true;
                            x = Obs.get_x() + r*cos(argdir) - 0.05;
                            y = Obs.get_height()+Obs.get_y() - r*sin(argdir) + 0.05;
                        }
                        else{
                            b = false;
                        }
                    }
                    else{
                        b = true;
                        x += t*vx/fps - 1e-10;
                        y += vy/fps + 1e-10;
                    }
                }
                else{
                    b = true;
                    x += vx/fps - 1e-10;
                    y += t*vy/fps + 1e-10;
                }
            }
            else{
                modify(coor,x+std::sin(arg_vect)*r,vx/fps,y+std::cos(arg_vect)*r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y()+ Obs.get_height(),0);
                intersection(coor,t,u);
                if(t > 1 or u > 1 or t < 0 or u < 0){
                    modify(coor,x+std::cos(arg_vect)*r,vx/fps,y-std::sin(arg_vect)*r,vy/fps,Obs.get_x()+Obs.get_width(),0,Obs.get_y(),Obs.get_height());
                    intersection(coor,t,u);
                    if(t > 1 or u > 1 or t < 0 or u < 0){
                        double dirx = (x+vx/fps - (Obs.get_width()+Obs.get_x()));
                        double diry = (y+vy/fps - (Obs.get_y()+Obs.get_height()));
                        double argdir = arg(dirx,diry);
                        if(dirx*dirx + diry*diry <= r*r){
                            b = true;
                            x = Obs.get_width()+Obs.get_x() + r*cos(argdir) + 0.05;
                            y = Obs.get_height()+Obs.get_y() - r*sin(argdir) + 0.05;
                        }
                        else{
                            b = false;
                        }
                    }
                    else{
                        b = true;
                        x += t*vx/fps + 1e-10;
                        y += vy/fps + 1e-10;
                    }
                }
                else{
                    b = true;
                    x += vx/fps + 1e-10;
                    y += t*vy/fps + 1e-10;
                }
            }
        }
    }
}

void Pieton::CircleObsColl(CircleObstacle Obs, bool &b){
    double dirx = (x+vx/fps - Obs.get_x());
    double diry = (y+vy/fps - Obs.get_y());
    double argdir = arg(dirx,diry);
    if(dirx*dirx + diry*diry <= (r+Obs.get_r())*(r+Obs.get_r())){
        b = true;
        x = Obs.get_x() + (r+Obs.get_r())*cos(argdir);
        y = Obs.get_y() - (r+Obs.get_r())*sin(argdir);
    }
    else{
        b = false;
    }
}


void Pieton::PietonColl(Pieton & p, RectangleObstacleList RectObs, CircleObstacleList CircObs){
    double dirx = (x - p.get_x());
    double diry = (y - p.get_y());
    double argdir = arg(dirx,diry);
    while(dirx*dirx + diry*diry <= (r+p.get_r())*(r+p.get_r()) - 0.01){
        double vtot = std::sqrt(vx*vx+vy*vy);
        p.ox = p.x;
        p.oy = p.y;
        p.Erase();
        p.change_vx(p.get_vx() - std::sqrt(m/p.get_m())*cos(argdir)*vtot);
        p.change_vy(p.get_vy() + std::sqrt(m/p.get_m())*sin(argdir)*vtot);



        p.UpdatePos(RectObs, CircObs, fps*(x - (r+p.get_r())*cos(argdir) - p.get_x()) - p.get_vx(), fps*(y + (r+p.get_r())*sin(argdir) - p.get_y()) - p.get_vy());

        dirx = (x - p.get_x());
        diry = (y - p.get_y());
        argdir = arg(dirx, diry);

        p.Draw();
        vx=0;
        vy=0;
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
    return A_repuls*(1/())*d;
}


PietonList::PietonList(){
    L = new Pieton[0];
    N = 0;
}

void PietonList::AddPieton(double X, double Y, double R, double M, double VX, double VY, double E, double Vdes_x, double Vdes_y){
    N += 1;
    Pieton * newL = new Pieton[N];
    for(int i = 0; i < N - 1; i++){
        Pieton p = L[i] ;
        newL[i] = Pieton(p.get_x(), p.get_y(), p.get_r(), p.get_m(), p.get_vx(),p.get_vy(),p.get_e(),p.get_vdesx(),p.get_vdesy());
    }
    newL[N-1] = Pieton(X,Y,R,M,VX,VY,E,Vdes_x,Vdes_y);
    delete[] L;
    L = newL;
}

int const PietonList::get_N(){
    return N;
}

Pieton const PietonList::get_ith_pieton(int i){
    return L[i];
}

void PietonList::draw(){
    for(int i = 0; i < N; i++){
        L[i].Erase();
        L[i].Draw();
    }
}

void PietonList::Updatepos(RectangleObstacleList RectObs, CircleObstacleList CircObs){
    for(int i = 0; i < N; i++){
        L[i].UpdatePos(RectObs, CircObs);
        for(int j = 0; j < N; j++){
            if(not(i == j)){
                L[i].PietonColl(L[j], RectObs, CircObs);
            }
        }
    }
}





