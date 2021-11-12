#pragma once

#include "BaseShape.h"

// Represents circle
class Circle : public BaseShape
{
private:
	// Radius
	float _radius;
	// Forms shape
	virtual void Form() override;
	// Sets radius
	void SetCircle(float thickness = 1, float radius = 1);
public:
	Circle(float thickness, float radius) : BaseShape(thickness)
	{
		_radius = radius; 
		Form(); 
	}
};