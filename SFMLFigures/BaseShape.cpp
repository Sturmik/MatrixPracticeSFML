#include "BaseShape.h"

// Updates all points according to the matrix
void BaseShape::UpdatePointsToMatrix(matrix::Matrix3x3& matrix)
{
	for (int i = 0; i < _points.size(); i++)
	{
		float nx, ny;
		// Update points according to matrix
		matrix::Forward(matrix, _points[i].GetShape().getPosition().x,
			_points[i].GetShape().getPosition().y, nx, ny);
		_points[i].GetShape().setPosition(sf::Vector2f(nx, ny));
	}
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
	// Update shape position
	_centerPosition = sf::Vector2f(_centerPosition.x + vector.x, _centerPosition.y + vector.y);
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix;
	// Identity matrix
	matrix::Identity(translateMatrix);
	// Get translation matrix
	matrix::Translate(translateMatrix, vector.x, vector.y);
	// Update points
	UpdatePointsToMatrix(translateMatrix);
}
// Rotates shape around it center point
void BaseShape::Rotate(float degrees)
{
	// Save our recent center position
	sf::Vector2f centerPositionBuff = _centerPosition;
	// Set position to zero
	SetPosition(sf::Vector2f(0, 0));
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, rotateMatrix, resultMatrix;
	// Identity matrix
	matrix::Identity(translateMatrix);
	matrix::Identity(rotateMatrix);
	// Get translation matrix
	matrix::Translate(translateMatrix, centerPositionBuff.x, centerPositionBuff.y);
	// Get translation matrix
	matrix::Rotate(rotateMatrix, degrees);
	// Update result matrix
	matrix::MatrixMultiply(resultMatrix, translateMatrix, rotateMatrix);
	// Update points
	UpdatePointsToMatrix(resultMatrix);
	// Update position
	_centerPosition = centerPositionBuff;
}
// Rotates shape around specific point
void BaseShape::Rotate(float degrees, sf::Vector2f point)
{
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, rotateMatrix, resultMatrix;
	// Identity matrix
	matrix::Identity(translateMatrix);
	matrix::Identity(rotateMatrix);
	// Get translation matrix
	matrix::Translate(translateMatrix, point.x, point.y);
	// Get translation matrix
	matrix::Rotate(rotateMatrix, degrees);
	// Get result matrix
	matrix::MatrixMultiply(resultMatrix, rotateMatrix, translateMatrix);
	// Update points
	UpdatePointsToMatrix(resultMatrix);
}
// Scale shape
void BaseShape::Scale(sf::Vector2f scaleVector)
{
	// Save our recent center position
	sf::Vector2f centerPositionBuff = _centerPosition;
	// Set position to zero
	SetPosition(sf::Vector2f(0, 0));
	// Declare matrixes
	matrix::Matrix3x3 translateMatrix, scaleMatrix, resultMatrix;
	// Identity matrix
	matrix::Identity(translateMatrix);
	matrix::Identity(scaleMatrix);
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
	// Update position
	_centerPosition = centerPositionBuff;
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
	// Identity matrix
	matrix::Identity(translateMatrix);
	matrix::Identity(shearMatrix);
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
	// Update position
	_centerPosition = centerPositionBuff;
}

// Draws shape
void BaseShape::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < _points.size(); i++)
	{
		window->draw(_points[i].GetShape());
	}
}