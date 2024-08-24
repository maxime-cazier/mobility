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



