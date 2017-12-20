#ifndef boxType_H
#define boxType_H

#include "rectangleType.h"
#include <string>
#include <vector>

enum color { green = 0, black = 1, brown = 2, white = 3};

class boxType : private rectangleType
{
public:
	//Function to set the length, width, and height 
	//of the box.
	//Postcondition: length = l; width = w; height = h;
	void setDimension(double l, double w, double h);

	//Function to return the height of the box.
	//Postcondition: The value of height is returned. 
	double getHeight() const;
	
	//Function to return the surface area of the box.
	//Postcondition: The surface area of the box is 
	//                calculated and returned.
	double area() const;
	
	//Function to return the volume of the box. 
	//Postcondition: The volume of the box is 
	//               calculated and returned.
	double volume() const;
	
	//Function to output the length, width, and height of a box.
	void print() const;
    
    void setBoxColor(color setColor);
    color getBoxColor() const;
	
	//Default constructor
	//Postcondition: length = 0; width = 0; height = 0;
	boxType();
	
	//Constructor with parameters
	//Postcondition: length = l; width = w; height = h;
	boxType(double l, double w, double h, color boxColor = green);
    
private:
	double height;
    color boxColor;
};

#endif
