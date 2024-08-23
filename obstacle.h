#pragma once

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
    CircleObstacle(double x, double y, double r);

    double const get_x();
    double const get_y();
    double const get_r();

};
