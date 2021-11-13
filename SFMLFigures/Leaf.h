#pragma once

#include "Paraboloid.h"

// Represents leaf
class Leaf : public BaseShape
{
private:
	// Top central point
	Point* _topCentralPoint;
	// Bottom central point
	Point* _bottomCentralPoint;
	// Creates leaf shape
	void CreateLeaf(float disclosure—oefficient, float xBorder);
public:
	// Get top central point
	Point GetTopCentralPoint() const { return *_topCentralPoint; }
	// Get bottom central point
	Point GetBottomCentralPoint() const { return *_bottomCentralPoint; }

	// Constructor
	Leaf(float disclosure—oefficient, float xBorder, float thickness) : BaseShape(thickness)
	{
		_topCentralPoint = _bottomCentralPoint = nullptr;
		CreateLeaf(disclosure—oefficient, xBorder);
	}
};