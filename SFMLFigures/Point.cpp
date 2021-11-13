#include "Point.h"

float Distance(sf::Vector2f firstPoint, sf::Vector2f secondPoint)
{
	return sqrt((firstPoint.x - secondPoint.x) * (firstPoint.x - secondPoint.x)
		+ (firstPoint.y - secondPoint.y) * (firstPoint.y - secondPoint.y));
}