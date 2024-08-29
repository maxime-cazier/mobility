#include "util.h"


void intersection(double coor[8], double & t, double & u){
    double det = coor[5]*coor[3] - coor[1]*coor[7];
    if(std::abs(det) < 1e-10){
        t = NAN; u = NAN;
    }
    else{
        t = (coor[5]*(coor[6] - coor[2]) + coor[7]*(coor[0] - coor[4]))/det;
        u = (coor[1]*(coor[6] - coor[2]) + coor[3]*(coor[0] - coor[4]))/det;
    }
}


double arg(double & x, double & y){
    if(x < 0 and y == 0) return 3.141592;
    else return -2*std::atan(y/(x+std::sqrt(x*x+y*y)));
}

void modify(double coor[8], double a, double b, double c, double d, double e, double f, double g, double h){
    coor[0] = a; coor[1] = b; coor[2] = c; coor[3] = d; coor[4] = e; coor[5] = f; coor[6] = g; coor[7] = h;
}


