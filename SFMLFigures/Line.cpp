#include "Line.h"

void Line::Form()
{ 
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
		if (x >= _magnitude)
		{
			break;
		}
		if (x < _magnitude)
		{
			x += step * _thickness;
		}
	}
	_centerPosition.x = _points[_points.size() - 1].GetShape().getPosition().x / 2;
}
