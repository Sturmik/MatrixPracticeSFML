#include "Line.h"

float Line::GetMagnitude()
{
	if (_points.size() == 0) { return 0; }
	return _points[0].Distance(_points[_points.size() - 1]);
}

void Line::CreateLine(float magnitude)
{	
	// Clear all previous points
	_points.clear();
	
	// Declare variables
	float x, y;
	x = 0;
	y = 0;
	float step = 10e-2;
	// Forming the line
	while (true)
	{
		// Add and update point
		_points.push_back(Point());
		Point& newPoint = _points[_points.size() - 1];
		newPoint.GetShape().setPosition(x, y);
		newPoint.SetSize(_thickness);
		// If we reached end point - exit the cycle
		if (x >= magnitude)
		{
			break;
		}
		if (x < magnitude)
		{
			x += step * _thickness;
		}
	}
	_centerPosition.x = _points[_points.size() - 1].GetShape().getPosition().x / 2;
}