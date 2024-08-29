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

    void UpdatePos(RectangleObstacleList RectObs, CircleObstacleList CircObs);
    void RectObsColl(RectangleObstacle Obs, bool& b);
    void CircleObsColl(CircleObstacle Obs, bool& b);

    void Draw();
    void Erase();
};











