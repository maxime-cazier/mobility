#pragma once

class direction{
    double d_x;
    double d_y;
public:
    direction(double x, double y);

    double get_d_x();
    double get_d_y();
};

direction operator * (double k, direction d);
