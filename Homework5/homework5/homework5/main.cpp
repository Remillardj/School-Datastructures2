//
//  main.cpp
//  homework5
//
//  Created by Jaryd Remillard on 2/20/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "triangle.h"

void printTriangleDetails(string label, const Triangle &tri) {
    double A = tri.getSideA();
    double B = tri.getSideB();
    double C = tri.getSideC();
    
    cout << label << " triangle: [";
    cout << A << ", "
         << B << ", "
         << C << "]" << endl;
    
    cout << "Area is: " << tri.TriangleArea(A, B, C) << endl;
    
    if (tri.isRightTriangle(A, B, C))
        cout << " Triangle is a right triangle" << endl;
    else
        cout << " Triangle is not a right triangle" << endl;
    
    if (tri.isIsoscelesTriangle(A, B, C))
        cout << " Triangle is an isosceles triangle" << endl;
    else
        cout << " Triangle is not an isosceles triangle" << endl;
    
    if (tri.isEquilateralTriangle(A, B, C))
        cout << " Triangle is an equilateral triangle" << endl;
    else
        cout << " Triangle is not an equilateral triangle" << endl;
    
    
}

int main() {
    cout << "CSC2430  Triangle Lab: Written by Jaryd Remillard" << endl;
    
    Triangle t1;
    printTriangleDetails("default", t1);
    
    Triangle t2(5, 2, 3);
    printTriangleDetails("t2(5, 2, 3)", t2);
    
    Triangle t3(4, 5, 3);
    printTriangleDetails("t3(4, 5, 3)", t3);
    
    Triangle t4(4, 6, 4);
    Triangle t5 = t4;
    printTriangleDetails("Assigned t5=t4", t5);
    
    t5 = Triangle(3, 3, 3);
    printTriangleDetails("On-the-fly assigned Triangle(3, 3, 3)", t5);
    
    t5 = Triangle(t5.getSideA(), 4, t5.getSideC());
    printTriangleDetails("Changed sideB", t5);
    
    Triangle t6(2, 4, 2);
    printTriangleDetails("t6(2, 4, 2)", t6);
    
    return 0;
}
