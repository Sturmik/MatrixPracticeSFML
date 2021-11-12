#pragma once

#include "BaseShape.h"

// Represent the line
class Line : public BaseShape
{
private:
	// Line magnitude
	int _magnitude;
	// Forms shape
	virtual void Form() override;
public:
	Line(int magnitude, float thickness)
	{
		_magnitude = magnitude;
		_thickness = thickness;
		Form();
	}
};