#pragma once

#include "Paraboloid.h"

// Represents leaf
class Leaf : public BaseShape
{
private:
	// Creates leaf shape
	void CreateLeaf(float disclosureÑoefficient, float xBorder);
public:
	// Constructor
	Leaf(float disclosureÑoefficient, float xBorder, float thickness) : BaseShape(thickness)
	{
		CreateLeaf(disclosureÑoefficient, xBorder);
	}
};