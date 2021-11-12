#include "Rectangle.h"

void Rectangle::Form()
{
	// Top and bottom side of the rectangle
	Line top(_width, _thickness), bottom(_width, _thickness);
	// Left and right side of the rectangle
	Line left(_height, _thickness), right(_height, _thickness);

	// Place lines
	top.SetPosition(sf::Vector2f(_width / 2, 0));
	bottom.SetPosition(sf::Vector2f(_width / 2, _height));
	left.SetPosition(sf::Vector2f(0, _height / 2));
	right.SetPosition(sf::Vector2f(_width, _height / 2));
	// Rotate lines
	right.Rotate(90);
	left.Rotate(90);

	// Get all points
	_points.insert(_points.end(), top.GetPoints().begin(), top.GetPoints().end());
	_points.insert(_points.end(), bottom.GetPoints().begin(), bottom.GetPoints().end());
	_points.insert(_points.end(), left.GetPoints().begin(), left.GetPoints().end());
	_points.insert(_points.end(), right.GetPoints().begin(), right.GetPoints().end());
}