#pragma once

#include "BaseShape.h"

// Represent the line
class Line : public BaseShape
{
private:
	// Start point
	Point* _startPoint;
	// End point
	Point*_endPoint;
	// Creates line
	void CreateLine(float magnitude);
public:
	// Get start point
	Point GetStartPoint() const { return *_startPoint; }
	// Get end point
	Point GetEndPoint() const { return *_endPoint; }
	// Gets line magnitude
	float GetMagnitude();
	// Constructor
	Line(float magnitude, float thickness) : BaseShape(thickness)
	{
		_startPoint = _endPoint = nullptr;
		if (magnitude < 0) { magnitude = 1; }
		CreateLine(magnitude);
	}
};