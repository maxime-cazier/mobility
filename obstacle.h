#pragma once
#include "util.h"

class RectangleObstacle{
  double x;
  double y;
  double width;
  double height;
public:

  RectangleObstacle();
  RectangleObstacle(double x, double y, double width, double height);

  double const get_x();
  double const get_y();
  double const get_width();
  double const get_height();
};


class CircleObstacle{
    double x;
    double y;
    double r;
public:

    CircleObstacle();
    CircleObstacle(double X, double Y, double R);

    double const get_x();
    double const get_y();
    double const get_r();

};


class RectangleObstacleList{
    RectangleObstacle * L;
    int N;
public:

    RectangleObstacleList();

    void AddRectangleObstacle(double x, double y, double width, double height);

    int const get_N();
    RectangleObstacle const get_ith_obstacle(int i);
    RectangleObstacle* const get_L();
    void draw();
};


class CircleObstacleList{
    CircleObstacle * L;
    int N;
public:

    CircleObstacleList();

    void AddCircleObstacle(double x, double y, double r);

    int const get_N();
    CircleObstacle const get_ith_obstacle(int i);
    void draw();
};
