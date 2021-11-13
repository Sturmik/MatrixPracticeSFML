#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

float Distance(sf::Vector2f firstPoint, sf::Vector2f secondPoint);

// Represents point
class Point  {
private:
	// Vertex array
	sf::RectangleShape _shape;
public:
	// Get distance between points
	float Distance(sf::Vector2f point) const {
		return sqrt((_shape.getPosition().x - point.x)* (_shape.getPosition().x - point.x)
			+ (_shape.getPosition().y - point.y)* (_shape.getPosition().y - point.y));
	}
	// Get distance between points
	float Distance(Point point) const {
		return sqrt((_shape.getPosition().x - point.GetShape().getPosition().x) * (_shape.getPosition().x - point.GetShape().getPosition().x)
			+ (_shape.getPosition().y - point.GetShape().getPosition().y) * (_shape.getPosition().y - point.GetShape().getPosition().y));
	}
	// Get point shape
	sf::RectangleShape& GetShape() { return _shape; }
	// Set point size
	void SetSize(float pointSize) {  _shape.setSize(sf::Vector2f(pointSize, pointSize)); }
};