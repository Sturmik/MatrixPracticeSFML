#pragma once

#include "BaseShape.h"

// Represents circle
class Circle : public BaseShape
{
private:
	// Creates circle
	void CreateCircle(float radius);
public:
	// Get circle radius
	float GetRadius();
	// Constructor
	Circle(float radius, float thickness) : BaseShape(thickness)
	{
		if (radius < 0) { radius = 1; }
		CreateCircle(radius);
	}
};