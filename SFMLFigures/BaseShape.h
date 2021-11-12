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
	// Updates center position of the shape
	void UpdateCenterPositionOfTheShape();

	// Forms shape
	virtual void Form() = 0;
public:
	// Consturctor
	BaseShape() { Scale(sf::Vector2f(1, 1)); }

	// Return center position
	sf::Vector2f GetCenterPosition() const { return _centerPosition; }
	// Returns scale
	sf::Vector2f GetScale() const { return _scale; }
	// Gets shape thickness
	float GetThickness() const { return _thickness; }

	// Sets position
	virtual void SetPosition(sf::Vector2f pos);
	// Move shape
	virtual void Move(sf::Vector2f vector);
	// Rotates shape around it center point
	virtual void Rotate(float degrees);
	// Rotates shape around specific point
	virtual void Rotate(float degrees, sf::Vector2f point);
	// Scale shape
	virtual void Scale(sf::Vector2f scaleVector);
	// Shear shape
	virtual void Shear(sf::Vector2f shearVector);

	// Draws shape
	virtual void Draw(sf::RenderWindow* window);
};