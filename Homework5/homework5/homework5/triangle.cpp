//
//  triangle.cpp
//  homework5
//
//  Created by Jaryd Remillard on 2/20/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#include <cmath>
#include <iostream>
using namespace std;
#include "triangle.h"

Triangle::Triangle()
{
    SideA = 3;
    SideB = 4;
    SideC = 5;
}

Triangle::Triangle(double A, double B, double C) {
    if ((((A + B) < C) && ((A + C) < B) && ((B + C) < A)) || ((A <= 0 ) || (B <= 0) || (C <= 0))) {
        cout << "Triangle constructor(" << A << ", " << B << ", " << C << ") illegal - setting to default values [3, 4, 5]" << endl;
        SideA = 3;
        SideB = 4;
        SideC = 5;
    } else {
        SideA = A;
        SideB = B;
        SideC = C;
    }
}

double Triangle::getSideA() const {
    return SideA;
}

double Triangle::getSideB() const {
    return SideB;
}

double Triangle::getSideC() const {
    return SideC;
}

bool Triangle::isRightTriangle(const double A, const double B, const double C) const {
    if (pow(C, 2) == pow(A, 2) + pow(B, 2)) {
        return true;
    } else return false;
}

bool Triangle::isEquilateralTriangle(const double A, const double B, const double C) const {
    if (A == B && A == C && B == C) {
        return true;
    } else return false;
}

bool Triangle::isIsoscelesTriangle(const double A, const double B, const double C) const {
    if (A == B && A != C) {
        return true;
    } else if (A == C && A != B) {
        return true;
    } else if (B == C && B != A) {
        return true;
    } else return false;
}

double Triangle::TriangleArea(const double A, const double B, const double C) const {
    //p = (A + B + C)/2
    // herons formula: Area = sqrt((s * (s - a)) * (s * (s - b)) * (s * (s - c)))
    double permimeter = (A + B + C) / 2;
    double area;
    return area = sqrt(permimeter*(permimeter - A)*(permimeter - B)*(permimeter - C));
}




