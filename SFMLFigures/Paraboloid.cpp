#include "Paraboloid.h"

float Paraboloid::GetDistanceBetweenExtremePoints()
{
	if (_points.size() == 0) { return 0; }
	return _points[0].Distance(_points[_points.size() - 1]);
}

void Paraboloid::CreateParaboloid(float disclosureCoefficient, float xBorder)
{
	// Clear all previous points
	_points.clear();
	// Form the parabaloid
	for (float x = -xBorder; x <= xBorder; x += xBorder / xBorder / 2)
	{
		// Point forming
		Point point;
		point.SetSize(_thickness);
		// Point positioning
		point.GetShape().setPosition(x, pow(x/disclosureCoefficient,2));
		_points.push_back(point);
	}
	// Update center position
	UpdateCenterPositionOfTheShape();
}