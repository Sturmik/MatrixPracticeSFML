#pragma once

#include "Rectangle.h"
#include "Circle.h"
#include "Leaf.h"

// Represents snowflake shape
class SnowflakeShape : public BaseShape
{
private:
	// Constants, which are needed for snowflake creating
	const float DISCLOSURE_COEFFICIENT = 11.5f;
	const float DISCLOSURE_COEFFICIENT_SIZE = 250.0f;
	const float DISCLOSURE_COEFFICIENT_STEP = 33.3f;

	// Creates snowflake shape
	void CreateSnowflakeShape(float size);
public:
	// Constructor
	SnowflakeShape(float size = 250, float thickness = 5) : BaseShape(thickness) 
	{ CreateSnowflakeShape(size); }
};