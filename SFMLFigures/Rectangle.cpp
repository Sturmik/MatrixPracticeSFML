#include "Rectangle.h"

float Rectangle::GetTopSideLength()
{
	if (_leftTopPoint == nullptr || _rightTopPoint == nullptr) { return 0; }
	return _leftTopPoint->Distance(*_rightTopPoint);
}

float Rectangle::GetleftSideLength()
{
	if (_leftTopPoint == nullptr || _leftBottomPoint == nullptr) { return 0; }
	return _leftTopPoint->Distance(*_leftBottomPoint); 
}

void Rectangle::CreateRectangle(float width, float height)
{
	// Clear all previous points
	_points.clear();

	// Top and bottom side of the rectangle
	Line top(width, _thickness), bottom(width, _thickness);
	// Left and right side of the rectangle
	Line left(height, _thickness), right(height, _thickness);

	// Place lines
	top.SetPosition(sf::Vector2f(width / 2, 0));
	bottom.SetPosition(sf::Vector2f(width / 2, height));
	left.SetPosition(sf::Vector2f(0, height / 2));
	right.SetPosition(sf::Vector2f(width, height / 2));
	// Rotate lines
	right.Rotate(90);
	left.Rotate(90);

	// Get all points
	_points.insert(_points.end(), top.GetPoints().begin(), top.GetPoints().end());
	_points.insert(_points.end(), bottom.GetPoints().begin(), bottom.GetPoints().end());
	_points.insert(_points.end(), left.GetPoints().begin(), left.GetPoints().end());
	_points.insert(_points.end(), right.GetPoints().begin(), right.GetPoints().end());

	// Update point values
	_leftTopPoint = &top.GetPoints()[0];
	_rightTopPoint = &top.GetPoints()[top.GetPoints().size() - 1];
	_leftBottomPoint = &bottom.GetPoints()[0];
}