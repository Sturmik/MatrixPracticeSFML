#pragma once

#include "Paraboloid.h"

// Represents leaf
class Leaf : public BaseShape
{
private:
	// Creates leaf shape
	void CreateLeaf(float disclosure—oefficient, float xBorder);
public:
	// Constructor
	Leaf(float disclosure—oefficient, float xBorder, float thickness) : BaseShape(thickness)
	{
		CreateLeaf(disclosure—oefficient, xBorder);
	}
};