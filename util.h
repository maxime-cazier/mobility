#pragma once
#include <limits>
#include <cmath>
#include <Imagine/Graphics.h>

const double fps = 30.0;

void intersection(double coor[8], double & t, double& u);

double arg(double & x, double & y);

void modify(double coor[8], double a, double b, double c, double d, double e, double f, double g, double h);
