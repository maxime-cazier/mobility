#include "pieton.h"
#include "Direction.h"
#include "util.h"





double Pieton::get_x() const{
    return x;
}

double Pieton::get_y() const{
    return y;
}

double Pieton::get_r() const{
    return r;
}

double Pieton::get_m() const{
    return m;
}

double Pieton::get_vx() const{
    return vx;
}

double Pieton::get_vy() const{
    return vy;
}

double Pieton::get_e() const{
    return e;
}

double Pieton::get_vdesx() const{
    return vdesx;
}

double Pieton::get_vdesy() const{
    return vdesy;
}

double Pieton::get_vlim() const{
    return vlim;
}

double Pieton::get_v0() const{
    return v0;
}

double Pieton::get_m_app() const{
    return m_app;
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

void Pieton::change_vdesx(double X){
    vdesx = X;
}

void Pieton::change_vdesy(double X){
    vdesy = X;
}

void Pieton::change_vlim(double new_vlim){
    vlim=new_vlim;
}

void Pieton::change_v0(double new_v0){
    v0=new_v0;
}

void Pieton::change_m_app(double new_m_app){
    m_app=new_m_app;
}



void Pieton::UpdatePos(RectangleObstacleList RectObs, CircleObstacleList CircObs, double addvx, double addvy){
    vx += addvx;
    vy += addvy;
    bool b = false;
    int i = 0;
    while((i < RectObs.get_N()) and not(b)){
        RectObsColl(RectObs.get_ith_obstacle(i), b);
        i++;
    }
    i = 0;
    while((i < CircObs.get_N()) and not(b)){
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



void Pieton::UpdateVdes(double X, double Y){
    double v=(vlim-v0)*e+v0;
    //double v = std::sqrt(vdesx*vdesx + vdesy*vdesy);
    double dirx = X - x;
    double diry = Y - y;
    double argdir = arg(dirx,diry);
    vdesx = v*std::cos(argdir);
    vdesy = -v*std::sin(argdir);
}



Pieton::Pieton(){
    x = 0; y = 0; r = 1; m = 1; vx = 0; vy = 0; e = 0; vdesx = 0; vdesy = 0; anglevision = 3.1415926535/2, m_app=10;
}

Pieton::Pieton(double X, double Y){
    x = X; y = Y; r = 1; m = 1; vx = 0; vy = 0; e = 0; vdesx = 0; vdesy = 0; anglevision = 3.1415926535/2, vlim=60.0, v0=20.0, m_app=10;
}

Pieton::Pieton(double X, double Y, double R){
    x = X; y = Y; r = R; m = 1; vx = 0; vy = 0; e = 0; vdesx = 0; vdesy = 0; anglevision = 3.1415926535/2, vlim=60.0, v0=20.0, m_app=10;
}

Pieton::Pieton(double X, double Y, double R, double M){
    x = X; y = Y; r = R; m = M; vx = 0; vy = 0; e = 0; vdesx = 0; vdesy = 0; anglevision = 3.1415926535/2, vlim=60.0, v0=20.0, m_app=10;
}

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = 0; vdesx = 0; vdesy = 0; anglevision = 3.1415926535/2, vlim=60.0, v0=20.0, m_app=10;
}

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY, double E){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = E; vdesx = 0; vdesy = 0; anglevision = 3.1415926535/2, vlim=60.0, v0=20.0, m_app=10;
}

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY, double E, double Vdesx, double Vdesy){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = E; vdesx = Vdesx; vdesy = Vdesy; anglevision = 3.1415926535/2, vlim=60.0, v0=20.0, m_app=10;
}

Pieton::Pieton(double X, double Y, double R, double M, double VX, double VY, double E, double Vdesx, double Vdesy, double Vlim, double V0){
    x = X; y = Y; r = R; m = M; vx = VX; vy = VY; e = E; vdesx = Vdesx; vdesy = Vdesy; anglevision = 3.1415926535/2, vlim=Vlim, v0=V0, m_app=10;
}



void Pieton::RectObsColl(RectangleObstacle Obs, bool& b){



    double t; double u; double coor[8];
    double arg_vect = arg(vx,vy);
    if(arg_vect <= - 1.570796327){
        modify(coor,x,vx/fps,y + r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y(),0);
        intersection(coor,t,u);
        if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){

            modify(coor,x - r,vx/fps,y,vy/fps,Obs.get_x()+Obs.get_width(),0,Obs.get_y(),Obs.get_height());
            intersection(coor,t,u);
            if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){

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
            modify(coor,x,vx/fps,y+r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y(),0);
            intersection(coor,t,u);
            if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){

                modify(coor,x+r,vx/fps,y,vy/fps,Obs.get_x(),0,Obs.get_y(),Obs.get_height());
                intersection(coor,t,u);
                if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){

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
                modify(coor,x,vx/fps,y-r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y()+Obs.get_height(),0);
                intersection(coor,t,u);
                if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){


                    modify(coor,x+r,vx/fps,y,vy/fps,Obs.get_x(),0,Obs.get_y(),Obs.get_height());
                    intersection(coor,t,u);
                    if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){


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
                modify(coor,x,vx/fps,y-r,vy/fps,Obs.get_x(),Obs.get_width(),Obs.get_y()+ Obs.get_height(),0);
                intersection(coor,t,u);
                if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){


                    modify(coor,x-r,vx/fps,y,vy/fps,Obs.get_x()+Obs.get_width(),0,Obs.get_y(),Obs.get_height());
                    intersection(coor,t,u);
                    if(!(t <= 1 and u <= 1 and t >= 0 and u >= 0)){


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
    if(dirx*dirx + diry*diry <= (r+p.get_r())*(r+p.get_r()) - 0.01){
        x = p.get_x() + (r+p.get_r())*cos(argdir);
        y = p.get_y() - (r+p.get_r())*sin(argdir);
        p.change_vx(1/(p.get_m()+m)*(p.get_vx()*(p.get_m()-m)+2*m*vx));
        p.change_vy(1/(p.get_m()+m)*(p.get_vy()*(p.get_m()-m)+2*m*vy));
        vx=0;
        vy=0;
    }
}

void Pieton::Draw(){
    Imagine::drawCircle(x,y,r,Imagine::RED);
}

void Pieton::Erase(){
    Imagine::drawCircle(x,y,r,Imagine::WHITE);
}

direction Pieton::force_attrac(){
    direction d(1/tau*(vdesx-vx),1/tau*(vdesy-vy));
    return d;
}

direction Pieton::force_repuls(Pieton p_ext){
    double dirx = (p_ext.get_x() - x);
    double diry = (p_ext.get_y() - y);
    double argdir = arg(dirx,diry);
    double argv = arg(vdesx,vdesy);
    double difarg = argdir - argv;

    while(difarg > 3.1415926535) difarg -= 2*3.1415926535;
    while(difarg < -3.141592654) difarg += 2*3.1415926535;

    double distance =std::sqrt((x-p_ext.get_x())*(x-p_ext.get_x()) + (y-p_ext.get_x())*(y-p_ext.get_x()));

    direction d(0,0);
    if(difarg <= 0 and difarg >= -anglevision/2){
        d.change_x((-1)*A_repuls*cos(argdir-3.1415926535/2)/distance);
        d.change_y(A_repuls*sin(argdir-3.1415926535/2)/distance);
    }
    else{
        if(difarg > 0 and difarg <= anglevision/2){
            d.change_x((-1)*A_repuls*cos(argdir+3.1415926535/2)/distance);
            d.change_y(A_repuls*sin(argdir+3.1415926535/2)/distance);
        }
    }
    return d;
}


direction Pieton::force_repuls_circle(CircleObstacle Obs){
    double dirx = (Obs.get_x() - x);
    double diry = (Obs.get_y() - y);
    double argdir = arg(dirx,diry);
    double argv = arg(vx,vy);
    double difarg = argdir - argv;

    while(difarg > 3.1415926535) difarg -= 2*3.1415926535;
    while(difarg < -3.141592654) difarg += 2*3.1415926535;

    double distance =std::sqrt((x-Obs.get_x())*(x-Obs.get_x()) + (y-Obs.get_x())*(y-Obs.get_x()));

    direction d(0,0);
    if(difarg <= 0 and difarg >= -anglevision/2){
        d.change_x((-1)*A_repuls*cos(argdir-3.1415926535/2)/distance);
        d.change_y(A_repuls*sin(argdir-3.1415926535/2)/distance);
    }
    else{
        if(difarg > 0 and difarg <= anglevision/2){
            d.change_x((-1)*A_repuls*cos(argdir+3.1415926535/2)/distance);
            d.change_y(A_repuls*sin(argdir+3.1415926535/2)/distance);
        }
    }
    return d;
}
























PietonList::PietonList(){
    L = new Pieton[0];
    N = 0;
}

void PietonList::AddPieton(double X, double Y, double R, double M, double VX, double VY, double E, double Vdes_x, double Vdes_y,double Vlim,double V0){
    N += 1;
    Pieton * newL = new Pieton[N];
    for(int i = 0; i < N - 1; i++){
        Pieton p = L[i] ;
        newL[i] = Pieton(p.get_x(), p.get_y(), p.get_r(), p.get_m(), p.get_vx(),p.get_vy(),p.get_e(),p.get_vdesx(),p.get_vdesy(),p.get_vlim(),p.get_v0());
    }
    newL[N-1] = Pieton(X,Y,R,M,VX,VY,E,Vdes_x,Vdes_y,Vlim,V0);
    delete[] L;
    L = newL;
}

int PietonList::get_N() const{
    return N;
}

Pieton PietonList::get_ith_pieton(int i) const{
    return L[i];
}

void PietonList::draw(){
    for(int i = 0; i < N; i++){
        L[i].Draw();
    }
}

void PietonList::erase(){
    for(int i = 0; i < N; i++){
        L[i].Erase();
    }
}

void PietonList::Updatepos(RectangleObstacleList RectObs, CircleObstacleList CircObs, RectangleObstacleList Exit){
    erase();
    for(int i = 0; i < N; i++){
        L[i].UpdatePos(RectObs, CircObs);
        for(int j = 0; j < N; j++){
            if(not(i == j)){
                L[i].PietonColl(L[j], RectObs, CircObs);
            }
        }


        RectangleObstacle Ex = Exit.get_ith_obstacle(i%Exit.get_N());
        L[i].UpdateVdes(Ex.get_x()+Ex.get_width()/2, Ex.get_y()+Ex.get_height()/2);
        bool b = false;
        for(int j = 0; j < Exit.get_N(); j++){
            RectangleObstacle Ex = Exit.get_ith_obstacle(j);
            L[i].RectObsColl(Ex,b);
            if(b){
                delete_ith_pos(i);
                i -= 1;
                break;
            }
        }
    }
    draw();
}



void PietonList::Updatespeed(RectangleObstacleList RectObs, CircleObstacleList){
    for(int i = 0; i < N; i++){
        L[i].change_vx(L[i].get_vx() + (L[i].force_attrac()).get_d_x()/fps);
        L[i].change_vy(L[i].get_vy() + (L[i].force_attrac()).get_d_y()/fps);
        //for(int j = 0; j < N; j++){
        //    if(not(i == j)){
        //        L[i].change_vx(L[i].get_vx() + L[i].force_repuls(L[j]).get_d_x()/fps);
        //        L[i].change_vy(L[i].get_vy() + L[i].force_repuls(L[j]).get_d_y()/fps);
        //    }
        //}
    }
}


void PietonList::delete_ith_pos(int i){
    N -= 1;
    int k = 0;
    Pieton * newL = new Pieton[N];
    for(int j = 0; j < N + 1; j++){
        if(!(i == j)){
            Pieton p = L[j] ;
            newL[j-k] = Pieton(p.get_x(), p.get_y(), p.get_r(), p.get_m(), p.get_vx(),p.get_vy(),p.get_e(),p.get_vdesx(),p.get_vdesy());
        }
        else k = 1;
    }
    delete[] L;
    L = newL;
}

void Pieton::change_m(double m, double e){
    m_app=m*(1+e*0.5);
}



