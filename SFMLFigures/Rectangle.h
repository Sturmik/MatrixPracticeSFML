#pragma once

#include "Line.h"

// Represents rectangle
class Rectangle : public BaseShape
{
private:
	// Points for rectangle analyze
	Point* _leftTopPoint;
	Point* _rightTopPoint;
	Point* _leftBottomPoint;
	// Creates rectangle
	void CreateRectangle(float width, float height);
public:
	// Get rectangle top side length
	float GetTopSideLength();
	// Get rectangle left side length
	float GetleftSideLength();

	// Constructor
	Rectangle(float width, float height, float thickness)  : BaseShape(thickness)
	{ 
		if (width < 0) { width = 1; }
		if (height < 0) { height = 1; }
		CreateRectangle(width, height);
	}
};