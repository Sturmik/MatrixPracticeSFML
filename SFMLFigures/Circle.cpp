#include "Circle.h"

float Circle::GetRadius() 
{
	if (_points.size() == 0) { return 0; }
	return _points[0].Distance(_centerPosition);
}

void Circle::CreateCircle(float radius)
{
	// Clear all previous points
	_points.clear();

	// Precalculate radius
	float sqrSquare = radius * radius;
	for (float x = -radius; x <= radius; x += radius / radius / 3)
	{
		// Position
		sf::Vector2f pos(x - _centerPosition.x, sqrt(sqrSquare - x * x) - _centerPosition.y);
		// Point forming
		Point point; 
		point.SetSize(_thickness);
		// Top point
		point.GetShape().setPosition(pos);
		_points.push_back(point);
		// Bottom point
		point.GetShape().setPosition(x, -pos.y);
		_points.push_back(point);
	}
	for (float y = -radius; y <= radius; y += radius / radius / 3)
	{
		// Position
		sf::Vector2f pos(sqrt(sqrSquare - y * y),y - _centerPosition.y);
		// Point forming
		Point point;
		point.SetSize(_thickness);
		// Top point
		point.GetShape().setPosition(pos);
		_points.push_back(point);
		// Bottom point
		point.GetShape().setPosition(-pos.x, y);
		_points.push_back(point);
	}


	// Update center position
	UpdateCenterPositionOfTheShape();
}