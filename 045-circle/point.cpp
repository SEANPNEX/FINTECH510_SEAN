#include <iostream>
#include <cmath>
#include "point.hpp"


Point::Point(/* args */double initialX, double initialY): x{initialX}, y{initialY} {}


Point::~Point(){}

double Point::getX(){
        return this->x;
}

double Point::getY(){
        return this->y;
}

void Point::move(double dx, double dy){
        this->x += dx;
        this->y += dy;
}


double Point::distanceFrom(const Point &p){
        double dx = p.x - x;
        double dy = p.y - y;
        return std::sqrt(dx * dx + dy * dy);
}