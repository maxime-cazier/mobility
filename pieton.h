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
    double ox;
    double oy;
    double vdesx;
    double vdesy;
public:
    Pieton();
    Pieton(double x, double y);
    Pieton(double x, double y, double r);
    Pieton(double x, double y, double r, double m);
    Pieton(double x, double y, double r, double m, double vx, double vy);
    Pieton(double x, double y, double r, double m, double vx, double vy, double e);
    Pieton(double x, double y, double r, double m, double vx, double vy, double e, double vdesx, double vdesy);

    double const get_x();
    double const get_y();
    double const get_r();
    double const get_m();
    double const get_vx();
    double const get_vy();
    double const get_e();
    double const get_vdesx();
    double const get_vdesy();
    direction force_attrac();
    direction force_repuls(Pieton p_ext);


    void change_x(double x);
    void change_y(double y);
    void change_vx(double vx);
    void change_vy(double vy);

    void UpdatePos(RectangleObstacleList RectObs, CircleObstacleList CircObs, double addvx = 0, double addvy = 0);
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

    void AddPieton(double X=0, double Y=0, double R=0, double M=0, double VX=0, double VY=0, double E=0, double Vdes_x=0, double Vdes_y=0);

    int const get_N();
    Pieton const get_ith_pieton(int i);
    void draw();
    void Updatepos(RectangleObstacleList RectObs, CircleObstacleList CircObs);
};










