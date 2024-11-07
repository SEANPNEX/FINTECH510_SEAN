//filename: point.hpp
//compile: g++ -std=c++17 -o point.o point.hpp
//execute: not applicable - no main function 
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "point.hpp"

class Circle {
    Point center;
    double radius;

public:
  Circle(Point initialCenter = Point(0,0), double initialRadius = 1);
  ~Circle();
  void move(double dx, double dy);
  double intersectionArea(const Circle & otherCircle);
};



#endif