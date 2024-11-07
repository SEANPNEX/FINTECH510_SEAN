//filename: point.hpp
//compile: g++ -std=c++17 -o point.o point.hpp
//execute: not applicable - no main function 
#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
  double x;
  double y;

public:
  Point(double initialX=0.0, double initialY=0.0);
  ~Point();
  double distanceFrom(const Point & p);
  void move(double dx, double dy);
  double getX();
  double getY();
};



#endif