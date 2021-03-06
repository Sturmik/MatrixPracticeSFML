#include "Leaf.h"

void Leaf::CreateLeaf(float disclosureÑoefficient, float xBorder)
{
    // Clear all previous points
    _points.clear();

    // Form leaf from paraboloids
    Paraboloid topParab(disclosureÑoefficient, xBorder, _thickness);
    Paraboloid bottomParab(disclosureÑoefficient, xBorder, _thickness);
    topParab.SetPosition(sf::Vector2f(0, 0));
    bottomParab.Rotate(180);
    bottomParab.SetPosition(sf::Vector2f(0, topParab.GetCenterPosition().y));
    // Additional move of bottom parab to form leaf
    bottomParab.Move(sf::Vector2f(0, abs(topParab.GetPoints()[0].GetShape().getPosition().y 
        - bottomParab.GetPoints()[0].GetShape().getPosition().y)));

    // Get all points
    _points.insert(_points.end(), topParab.GetPoints().begin(), topParab.GetPoints().end());
    _points.insert(_points.end(), bottomParab.GetPoints().begin(), bottomParab.GetPoints().end());

    // Update pointer values
    _topCentralPoint = &_points[(topParab.GetPoints().size() / 2) - 1];
    _bottomCentralPoint = &_points[topParab.GetPoints().size() + (bottomParab.GetPoints().size() / 2)];

    // Update center position
    UpdateCenterPositionOfTheShape();
}