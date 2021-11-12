#pragma once

#include <SFML/Graphics.hpp>

// Represents point
class Point  {
private:
	// Vertex array
	sf::RectangleShape _shape;
public:
	// Get point shape
	sf::RectangleShape& GetShape() { return _shape; }
	// Set point size
	void SetSize(float pointSize) {  _shape.setSize(sf::Vector2f(pointSize, pointSize)); }
};