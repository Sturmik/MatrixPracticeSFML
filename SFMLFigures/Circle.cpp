#include "Circle.h"

void Circle::SetCircle(float thickness, float radius)
{
	// Set thickness and radius
	this->_thickness = thickness;
	this->_radius = radius;
	_points.clear();
	// Precalculate radius
	float sqrSquare = radius * radius;
	for (float x = -radius; x <= radius; x += radius /  150)
	{
		// Position
		sf::Vector2f pos(x - _centerPosition.x, sqrt(sqrSquare - x * x) - _centerPosition.y);
		// Point forming
		Point point; 
		point.SetSize(thickness);
		// Top point
		point.GetShape().setPosition(pos);
		_points.push_back(point);
		// Bottom point
		point.GetShape().setPosition(x, -pos.y);
		_points.push_back(point);
	}
	for (float y = -radius; y <= radius; y += radius / 150)
	{
		// Position
		sf::Vector2f pos(sqrt(sqrSquare - y * y),y - _centerPosition.y);
		// Point forming
		Point point;
		point.SetSize(thickness);
		// Top point
		point.GetShape().setPosition(pos);
		_points.push_back(point);
		// Bottom point
		point.GetShape().setPosition(-pos.x, y);
		_points.push_back(point);
	}
}

void Circle::Form()
{
	SetCircle(_thickness, _radius);
}