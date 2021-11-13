#include "BaseShape.h"

// Converts degrees to radians
float DegreesToRadians(float degrees)
{
	return  degrees * 0.0174533;
}

// Converts radians to degrees
float RadiansToDegrees(float radians)
{
	return radians * 57, 2958;
}

// Updates all points according to the matrix
void BaseShape::UpdatePointsToMatrix(matrix::Matrix3x3& matrix)
{
	for (int i = 0; i < _points.size(); i++)
	{
		float nx, ny;
		// Update points according to matrix
		matrix::Forward(matrix, _points[i].GetShape().getPosition().x,
			_points[i].GetShape().getPosition().y, nx, ny);
		// Set new position
		_points[i].GetShape().setPosition(sf::Vector2f(nx, ny));
	}
	UpdateCenterPositionOfTheShape();
}

// Updates center position of the shape
void BaseShape::UpdateCenterPositionOfTheShape()
{
	if (_points.size() == 0) { return; }
	double centerX, centerY; centerX = centerY = 0;
	for (int i = 0; i < _points.size(); i++)
	{
		centerX += _points[i].GetShape().getPosition().x;
		centerY += _points[i].GetShape().getPosition().y;
	}
	_centerPosition.x = centerX / _points.size();
	_centerPosition.y = centerY / _points.size();
}

// Sets position
void BaseShape::SetPosition(sf::Vector2f pos)
{
	// Translate matrix
	Move(sf::Vector2f(pos.x - _centerPosition.x, pos.y - _centerPosition.y));
}

// Move shape
void BaseShape::Move(sf::Vector2f vector)
{
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix;
	// Get translation matrix
	matrix::Translate(translateMatrix, vector.x, vector.y);
	// Update points
	UpdatePointsToMatrix(translateMatrix);
}

// Rotates shape around it center point
void BaseShape::Rotate(float degrees)
{
	// Convert degrees to radians
	float radians = DegreesToRadians(degrees);
	// Save our recent center position
	sf::Vector2f centerPositionBuff = _centerPosition;
	// Set position to zero
	SetPosition(sf::Vector2f(0, 0));
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, rotateMatrix, resultMatrix;
	// Get translation matrix
	matrix::Translate(translateMatrix, centerPositionBuff.x, centerPositionBuff.y);
	// Get translation matrix
	matrix::Rotate(rotateMatrix, radians);
	// Update result matrix
	matrix::MatrixMultiply(resultMatrix, translateMatrix, rotateMatrix);
	// Update points
	UpdatePointsToMatrix(resultMatrix);
}

// Rotates shape around specific point
void BaseShape::Rotate(float degrees, sf::Vector2f point)
{
	// Convert degrees to radians
	float radians = DegreesToRadians(degrees);
	// Save our recent center position
	sf::Vector2f centerPositionAfterRotation;
	centerPositionAfterRotation.x = _centerPosition.x - point.x;
	centerPositionAfterRotation.y = _centerPosition.y - point.y;
	// Set position to zero
	SetPosition(sf::Vector2f(0, 0));
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, rotateMatrix, translateRotateMatrix, translateBackMatrix, resultMatrix;
	// Get translation matrix
	matrix::Translate(translateMatrix, point.x, point.y);
	// Get translation matrix
	matrix::Rotate(rotateMatrix, radians);
	// Get translate rotate matrix
	matrix::MatrixMultiply(translateRotateMatrix, translateMatrix, rotateMatrix);
	// Get translate back matrix
	matrix::Translate(translateBackMatrix, centerPositionAfterRotation.x, centerPositionAfterRotation.y);
	// Update result matrix
	matrix::MatrixMultiply(resultMatrix, translateRotateMatrix, translateBackMatrix);
	// Update points
	UpdatePointsToMatrix(resultMatrix);
}

// Scale shape
void BaseShape::Scale(sf::Vector2f scaleVector)
{
	// Remember  recent center position
	sf::Vector2f centerPositionBuff = _centerPosition;
	// Set position to zero
	SetPosition(sf::Vector2f(0, 0));
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, scaleMatrix, resultMatrix;
	// Get translation matrix
	matrix::Translate(translateMatrix, centerPositionBuff.x, centerPositionBuff.y);
	// Get scale matrix
	matrix::Scale(scaleMatrix, scaleVector.x, scaleVector.y);
	// Get result matrix
	matrix::MatrixMultiply(resultMatrix, translateMatrix, scaleMatrix);
	// Update points size
	for (int i = 0; i < _points.size(); i++)
	{
		sf::Vector2f pointScale = _points[i].GetShape().getScale();
		_points[i].GetShape().setScale(pointScale.x * scaleVector.x, pointScale.y * scaleVector.y);
	}
	// Update points
	UpdatePointsToMatrix(resultMatrix);
}

// Shear shape
void BaseShape::Shear(sf::Vector2f shearVector)
{
	// Save our recent center position
	sf::Vector2f centerPositionBuff = _centerPosition;
	// Set position to zero
	SetPosition(sf::Vector2f(0, 0));
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, shearMatrix, resultMatrix;
	// Get translation matrix
	matrix::Translate(translateMatrix, centerPositionBuff.x, centerPositionBuff.y);
	// Get scale matrix
	matrix::Shear(shearMatrix, shearVector.x, shearVector.y);
	// Get result matrix
	matrix::MatrixMultiply(resultMatrix, translateMatrix, shearMatrix);
	// Update points size
	for (int i = 0; i < _points.size(); i++)
	{
		sf::Vector2f pointScale = _points[i].GetShape().getScale();
		_points[i].GetShape().setScale(pointScale.x * shearVector.x, pointScale.y * shearVector.y);
	}
	// Update points
	UpdatePointsToMatrix(resultMatrix);
}

// Draws shape
void BaseShape::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < _points.size(); i++)
	{
		window->draw(_points[i].GetShape());
	}
}