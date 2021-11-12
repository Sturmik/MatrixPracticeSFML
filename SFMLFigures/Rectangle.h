#pragma once

#include "Line.h"

// Represents rectangle
class Rectangle : public BaseShape
{
private:
	// Width and height of the rectangle
	float _width, _height;
	// Forms the figure
	void Form() override;
public:
	// Constructor
	Rectangle(float width, float height, float thickness)  : BaseShape(thickness)
	{ 
		_width = width;
		_height = height;
		Form();
	}
};