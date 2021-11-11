#pragma once

#include <SFML/Graphics.hpp>

// Represents point
class Point  {
private:
	// Default size for all points
	float _pointSize;
	// Vertex array
	sf::RectangleShape _shape;
	// Is visible
	bool _isVisible;
public:
	// Get point shape
	sf::RectangleShape& GetShape() { return _shape; }
	// Get point size
	float GetSize() const { return _pointSize; }
	// Set point size
	void SetSize(float pointSize) { _pointSize = pointSize; _shape.setSize(sf::Vector2f(_pointSize, _pointSize)); }
	// Get point visibility state
	bool IsVisible() const { return _isVisible; }
	// Sets visibility
	void SetVisibility(bool visibility) { _isVisible = visibility; }
};