#pragma once

// Include point for shape forming
#include "Point.h"
// Include matrix for operations with shape
#include "Matrix.h"

// Abstract base shape builder
class BaseShape
{
protected:
	// Points
	std::vector<Point> _points;
	// Shape position
	sf::Vector2f _centerPosition;
	// Scale
	sf::Vector2f _scale;
	// Thickness
	float _thickness;

	// Updates all points according to the matrix
	void UpdatePointsToMatrix(matrix::Matrix3x3& matrix);

	// Forms shape
	virtual void Form() = 0;
public:
	// Consturctor
	BaseShape() { Scale(sf::Vector2f(1, 1)); }

	// Returns scale
	sf::Vector2f GetScale() const { return _scale; }
	// Gets shape thickness
	float GetThickness() const { return _thickness; }

	// Sets position
	void SetPosition(sf::Vector2f pos);
	// Move shape
	void Move(sf::Vector2f vector);
	// Rotates shape around it center point
	void Rotate(float degrees);
	// Rotates shape around specific point
	void Rotate(float degrees, sf::Vector2f point);
	// Scale shape
	void Scale(sf::Vector2f scaleVector);
	// Shear shape
	void Shear(sf::Vector2f shearVector);

	// Draws shape
	void Draw(sf::RenderWindow* window);
};