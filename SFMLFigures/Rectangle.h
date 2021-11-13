#pragma once

#include "Line.h"
#include <iostream>
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
	float GetLeftSideLength();
	// Get diagonal length
	float GetDiagonalLength();

	// Constructor
	Rectangle(float width, float height, float thickness)  : BaseShape(thickness)
	{ 
		_leftTopPoint = _rightTopPoint = _leftBottomPoint = nullptr;
		if (width < 0) { width = 1; }
		if (height < 0) { height = 1; }
		CreateRectangle(width, height);
	}
};