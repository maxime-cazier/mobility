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

  double get_x() const;
  double get_y() const;
  double get_width() const;
  double get_height() const;
};


class CircleObstacle{
    double x;
    double y;
    double r;
public:

    CircleObstacle();
    CircleObstacle(double X, double Y, double R);

    double get_x() const;
    double get_y() const;
    double get_r() const;

};


class RectangleObstacleList{
    RectangleObstacle * L;
    int N;
public:

    RectangleObstacleList();

    void AddRectangleObstacle(double x, double y, double width, double height);

    int get_N() const;
    RectangleObstacle get_ith_obstacle(int i) const;
    RectangleObstacle* get_L() const;
    void draw();
    void draw_as_exit();
};


class CircleObstacleList{
    CircleObstacle * L;
    int N;
public:

    CircleObstacleList();

    void AddCircleObstacle(double x, double y, double r);

    int get_N() const;
    CircleObstacle get_ith_obstacle(int i) const;
    void draw();
};






