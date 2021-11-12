#pragma once

#include "BaseShape.h"

// Represent the line
class Line : public BaseShape
{
private:
	// Creates line
	void CreateLine(float magnitude);
public:
	// Gets line magnitude
	float GetMagnitude();
	// Constructor
	Line(float magnitude, float thickness) : BaseShape(thickness)
	{
		if (magnitude < 0) { magnitude = 1; }
		CreateLine(magnitude);
	}
};