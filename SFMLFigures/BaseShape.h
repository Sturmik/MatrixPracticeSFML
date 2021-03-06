#pragma once

// Include point for shape forming
#include "Point.h"
// Include matrix for operations with shape
#include "Matrix.h"

// Converts degrees to radians
float DegreesToRadians(float degrees);
// Converts radians to degrees
float RadiansToDegrees(float radians);

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
public:
	// Consturctor
	BaseShape(float thickness)
	{
		if (thickness < 0){ thickness = 1;}
		Scale(sf::Vector2f(1, 1));
		_thickness = thickness; 
	}

	// Get all points
	std::vector<Point>& GetPoints() { return _points; }
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