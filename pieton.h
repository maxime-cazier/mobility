#pragma once
#include "obstacle.h"
#include "Direction.h"

class Pieton{
    double x;
    double y;
    double r;
    double m;
    double vx;
    double vy;
    double e;
    double vdesx;
    double vdesy;
    double anglevision;
    double vlim;
    double v0;
    double m_app;


public:
    Pieton();
    Pieton(double x, double y);
    Pieton(double x, double y, double r);
    Pieton(double x, double y, double r, double m);
    Pieton(double x, double y, double r, double m, double vx, double vy);
    Pieton(double x, double y, double r, double m, double vx, double vy, double e);
    Pieton(double x, double y, double r, double m, double vx, double vy, double e, double vdesx, double vdesy);
    Pieton(double x, double y, double r, double m, double vx, double vy, double e, double vdesx, double vdesy,double vlim, double v0);

    double get_x() const;
    double get_y() const;
    double get_r() const;
    double get_m() const;
    double get_vx() const;
    double get_vy() const;
    double get_e() const;
    double get_vdesx() const;
    double get_vdesy() const;
    double get_vlim() const;
    double get_v0() const;
    double get_m_app() const;



    direction force_attrac();
    direction force_repuls(Pieton p_ext);
    direction force_repuls_circle(CircleObstacle Obs);


    void change_x(double x);
    void change_y(double y);
    void change_vx(double vx);
    void change_vy(double vy);
    void change_vdesx(double vdesx);
    void change_vdesy(double vdesy);
    void change_m(double m, double e);
    void change_vlim(double new_vlim);
    void change_v0(double new_v0);
    void change_m_app(double new_m_app);

    void UpdatePos(RectangleObstacleList RectObs, CircleObstacleList CircObs, double addvx = 0, double addvy = 0);
    void UpdateVdes(double x, double y);
    void RectObsColl(RectangleObstacle Obs, bool& b);
    void CircleObsColl(CircleObstacle Obs, bool& b);
    void PietonColl(Pieton &p, RectangleObstacleList RectObs, CircleObstacleList CircObs);

    void Draw();
    void Erase();
};


class PietonList{
    Pieton * L;
    int N;
public:

    PietonList();

    void AddPieton(double X=0, double Y=0, double R=0, double M=0, double VX=0, double VY=0, double E=0, double Vdes_x=0, double Vdes_y=0,double Vlim = 60,double V0=20);

    int get_N() const;
    Pieton get_ith_pieton(int i) const;
    void delete_ith_pos(int i);
    void draw();
    void erase();
    void Updatepos(RectangleObstacleList RectObs, CircleObstacleList CircObs, RectangleObstacleList Exit);
    void Updatespeed(RectangleObstacleList RectObs, CircleObstacleList);
};










