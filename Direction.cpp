#include "Direction.h"

direction::get_d_x(){
    return d_x;
}

direction::get_d_y(){
    return d_y;
}

direction operator * (double k, direction d){
    return {k*d.get_d_x(),k*d.get_d_y()};
}
