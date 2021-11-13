#include "SnowflakeShape.h"

void SnowflakeShape::CreateSnowflakeShape(float size)
{
	// Declare all neded shapes
	Circle centerCircle(size / 3, _thickness);
	
	Line verticalLine(size + size / 3, _thickness), horizontalLine(size + size / 3, _thickness);
	Line diagonalLeftLine(size + size / 5, _thickness), diagonalRightLine(size + size / 5, _thickness);
	
	Rectangle leftRectangle(size / 4, size / 4, _thickness), rightRectangle(size / 4, size / 4, _thickness);
	Rectangle topRectangle(size / 4, size / 4, _thickness), bottomRectangle(size / 4, size / 4, _thickness);

	// Calculate disclosure
	// This forms leafs with similiar size according to the given size in the function.
	float disclosureCoefficient = DISCLOSURE_COEFFICIENT - ((DISCLOSURE_COEFFICIENT_SIZE - size) / DISCLOSURE_COEFFICIENT_STEP);

	Leaf leftTopLeaf(disclosureCoefficient, horizontalLine.GetMagnitude() / 5 , _thickness),
		rightTopLeaf(disclosureCoefficient, horizontalLine.GetMagnitude() / 5, _thickness);
	Leaf leftBottomLeaf(disclosureCoefficient, horizontalLine.GetMagnitude() / 5, _thickness), 
		rightBottomLeaf(disclosureCoefficient, horizontalLine.GetMagnitude() / 5, _thickness);
	
	// Position all shapes

	// Set circle in the center
	centerCircle.SetPosition(sf::Vector2f(0, 0));

	// Set lines and rotate them
	verticalLine.SetPosition(sf::Vector2f(0, 0));
	verticalLine.Rotate(90);

	horizontalLine.SetPosition(sf::Vector2f(0, 0));

	diagonalLeftLine.SetPosition(sf::Vector2f(0, 0));
	diagonalLeftLine.Rotate(-45);

	diagonalRightLine.SetPosition(sf::Vector2f(0, 0));
	diagonalRightLine.Rotate(45);

	// Set rectangles and rotate them
	leftRectangle.Rotate(45);
	leftRectangle.SetPosition(sf::Vector2f
	(-horizontalLine.GetMagnitude() / 2 - leftRectangle.GetDiagonalLength() / 2, horizontalLine.GetCenterPosition().y));

	rightRectangle.Rotate(45);
	rightRectangle.SetPosition(sf::Vector2f
	(horizontalLine.GetMagnitude() / 2 + rightRectangle.GetDiagonalLength() / 2,
		horizontalLine.GetCenterPosition().y));

	topRectangle.Rotate(45);
	topRectangle.SetPosition(sf::Vector2f
	(verticalLine.GetCenterPosition().x,
		-verticalLine.GetMagnitude() / 2 - topRectangle.GetDiagonalLength() / 2));

	bottomRectangle.Rotate(45);
	bottomRectangle.SetPosition(sf::Vector2f
	(verticalLine.GetCenterPosition().x,
		verticalLine.GetMagnitude() / 2 + bottomRectangle.GetDiagonalLength() / 2));

	// Set leafs and rotate them

	leftTopLeaf.Rotate(45);
	leftTopLeaf.Move
	(sf::Vector2f(diagonalLeftLine.GetStartPoint().GetShape().getPosition().x 
		- leftTopLeaf.GetBottomCentralPoint().GetShape().getPosition().x,
		diagonalLeftLine.GetStartPoint().GetShape().getPosition().y -
		leftTopLeaf.GetBottomCentralPoint().GetShape().getPosition().y));

	rightTopLeaf.Rotate(-45);
	rightTopLeaf.Move
	(sf::Vector2f(diagonalRightLine.GetEndPoint().GetShape().getPosition().x - 
		rightTopLeaf.GetBottomCentralPoint().GetShape().getPosition().x,
		diagonalRightLine.GetEndPoint().GetShape().getPosition().y -
		rightTopLeaf.GetBottomCentralPoint().GetShape().getPosition().y));

	leftBottomLeaf.Rotate(-45);
	leftBottomLeaf.Move
	(sf::Vector2f(diagonalRightLine.GetStartPoint().GetShape().getPosition().x -
		leftBottomLeaf.GetTopCentralPoint().GetShape().getPosition().x,
		diagonalRightLine.GetStartPoint().GetShape().getPosition().y -
		leftBottomLeaf.GetTopCentralPoint().GetShape().getPosition().y));

	rightBottomLeaf.Rotate(45);
	rightBottomLeaf.Move
	(sf::Vector2f(diagonalLeftLine.GetEndPoint().GetShape().getPosition().x -
		rightBottomLeaf.GetTopCentralPoint().GetShape().getPosition().x,
		diagonalLeftLine.GetEndPoint().GetShape().getPosition().y -
		rightBottomLeaf.GetTopCentralPoint().GetShape().getPosition().y));

	// Get all points
	_points.insert(_points.end(), centerCircle.GetPoints().begin(), centerCircle.GetPoints().end());

	_points.insert(_points.end(), verticalLine.GetPoints().begin(), verticalLine.GetPoints().end());
	_points.insert(_points.end(), horizontalLine.GetPoints().begin(), horizontalLine.GetPoints().end());
	_points.insert(_points.end(), diagonalLeftLine.GetPoints().begin(), diagonalLeftLine.GetPoints().end());
	_points.insert(_points.end(), diagonalRightLine.GetPoints().begin(), diagonalRightLine.GetPoints().end());

	_points.insert(_points.end(), leftRectangle.GetPoints().begin(), leftRectangle.GetPoints().end());
	_points.insert(_points.end(), rightRectangle.GetPoints().begin(), rightRectangle.GetPoints().end());
	_points.insert(_points.end(), topRectangle.GetPoints().begin(), topRectangle.GetPoints().end());
	_points.insert(_points.end(), bottomRectangle.GetPoints().begin(), bottomRectangle.GetPoints().end());

	_points.insert(_points.end(), leftTopLeaf.GetPoints().begin(), leftTopLeaf.GetPoints().end());
	_points.insert(_points.end(), rightTopLeaf.GetPoints().begin(), rightTopLeaf.GetPoints().end());
	_points.insert(_points.end(), leftBottomLeaf.GetPoints().begin(), leftBottomLeaf.GetPoints().end());
	_points.insert(_points.end(), rightBottomLeaf.GetPoints().begin(), rightBottomLeaf.GetPoints().end());

	// Update center position
	UpdateCenterPositionOfTheShape();
}