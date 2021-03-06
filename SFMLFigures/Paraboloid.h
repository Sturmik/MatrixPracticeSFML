#pragma once

#include "BaseShape.h"

// Represents paraboloid
class Paraboloid : public BaseShape
{
private:
	// Creates parabaloid
	void CreateParaboloid(float disclosureCoefficient, float xBorder);
public:
	// Gets distance between extreme points
	float GetDistanceBetweenExtremePoints();
	// Parabaloid constructor
	Paraboloid(float disclosureÑoefficient, float xBorder, float thickness) : BaseShape(thickness)
	{
		if (disclosureÑoefficient < 0) { disclosureÑoefficient = 1; }
		if (xBorder < 0) { xBorder = 1; }
		CreateParaboloid(disclosureÑoefficient, xBorder);
		UpdateCenterPositionOfTheShape();
	}
};