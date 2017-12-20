//
//  triangle.h
//  homework5
//
//  Created by Jaryd Remillard on 2/20/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//
//

/*
 a triangle class that is capable of analyzing and outputting information
 regarding sides of the triangle
*/
class Triangle {
public:
    // create triangle object
    Triangle();
    
    // construct object parameters
    Triangle(double A, double B, double C);
    
    // input sides of the triangle, and return true if the sides follow the pythagorean theorem
    // of c^2 = a^2 + b^2. It will return false if it does not follow the theorem
    bool isRightTriangle(const double A, const double B, const double C) const;
    
    // input sides of the triangle, will return true if all sides are equal
    // will return false if all sides do not equal each other
    bool isEquilateralTriangle(const double A, const double B, const double C) const;
    
    // input sides of the triangle, will return true if two of the sides equal
    // each other, but differ from the last side. Will return false if
    // two sides don't equal and differ from the last side
    bool isIsoscelesTriangle(const double A, const double B, const double C) const;
    
    // find the area of the inputted triangle sides by using Herons formula of
    // Area = sqrt((s * (s - a)) * (s * (s - b)) * (s * (s - c))) where s = (a + b + c)/2
    // and return double value
    double TriangleArea(const double A, const double B, const double C) const;
    
    // return value of side length of A
    double getSideA() const;
    
    // return value of side length of B
    double getSideB() const;
    
    // return value of side length C
    double getSideC() const;
    
private:
    double SideA;
    double SideB;
    double SideC;
};
