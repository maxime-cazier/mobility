#pragma once
#include <limits>
#include <cmath>
#include <Imagine/Graphics.h>

const double fps = 30.0;

const double tau=1;

const double A_repuls=200;

const double B_repuls=100;

void intersection(double coor[8], double & t, double& u);

double arg(double & x, double & y);

void modify(double coor[8], double a, double b, double c, double d, double e, double f, double g, double h);

double dist(double x1, double y1, double x2, double y2);
