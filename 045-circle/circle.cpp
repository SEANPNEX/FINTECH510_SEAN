#include <iostream>
#include <cmath>
#include "point.hpp"
#include "circle.hpp"
#include <algorithm>

Circle::Circle(Point initalCenter, double initialRadius): center{initalCenter}, radius{initialRadius} {}

Circle::~Circle(){}

void Circle::move(double dx, double dy){
    center.move(dx, dy);
}

double Circle::intersectionArea(const Circle & otherCircle){
    double r1 = this->radius;
    Point otherCenter = otherCircle.center;
    double r2 = otherCircle.radius;
    double D = center.distanceFrom(otherCenter);
    if(D>=r1+r2){
        //  circle don't overlap
        return 0;
    }
    else if(D<abs(r2-r1)){
        // circle contained in another
        double a1 = M_PI * r1 * r1;
        double a2 = M_PI * r2 * r2;
        return std::min(a1, a2);
    }
    else if((D==0)&&(r1==r2)){
        // 2 circle coincides
        return M_PI * r1 *r1;
    }
    else{
        double part1 = r1 * r1 * acos((D * D + r1 * r1 - r2 * r2) / (2 * D * r1));
        double part2 = r2 * r2 * acos((D * D + r2 * r2 - r1 * r1) / (2 * D * r2));
        double part3 = 0.5 * sqrt((-D + r1 + r2) * (D + r1 - r2) * (D - r1 + r2) * (D + r1 + r2));
        return part1 + part2 - part3;        
    }
}
