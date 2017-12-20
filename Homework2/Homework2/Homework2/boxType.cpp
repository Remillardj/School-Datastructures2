#include <iostream>
#include "rectangleType.h"
#include "boxType.h"

boxType::boxType() 
{
	height = 0.0;
    boxColor = green;
}

boxType::boxType(double l, double w, double h, color setColor)
: rectangleType(l, w)
{
	if (h >= 0)
		height = h;
	else
		height = 0;
    
    boxColor = setColor;
}

void boxType::setDimension(double l, double w, double h)
{
	rectangleType::setDimension(l, w);

	if (h >= 0)
		height = h;
	else
		height = 0;
}

double boxType::getHeight() const
{
	return height;
}

double boxType::area() const
{
	return  2 * (getLength() * getWidth()
		+ getLength() * height
		+ getWidth() * height);
}

double boxType::volume() const
{
	return getLength()*getWidth()*height;
}

void boxType::print() const
{
	rectangleType::print();
	std::cout << "; Height = " << height;
}

void boxType::setBoxColor(color setColor) {
    boxColor = setColor;
}

color boxType::getBoxColor() const {
    return boxColor;
}

