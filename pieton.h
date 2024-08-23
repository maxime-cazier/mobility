#pragma once
#include "util.h"

class Pieton{
    double x;
    double y;
    double r;
    double m;
    double vx;
    double vy;
    double e;
public:
    Pieton();
    Pieton(double x, double y);
    Pieton(double x, double y, double r);
    Pieton(double x, double y, double r, double m);
    Pieton(double x, double y, double r, double m, double vx, double vy);
    Pieton(double x, double y, double r, double m, double vx, double vy, double e);

    double const get_x();
    double const get_y();
    double const get_r();
    double const get_m();
    double const get_vx();
    double const get_vy();
    double const get_e();

    void UpdatePos();
};
