#include "Land.h"
#include "LandChamber.h"
//#include "Owner.h"
//#include <iostream>

Land::Land(double area = 0.0) : area{ area }
{
    LandChamber::addLand(this);
}

void Land::addOwner(Owner* owner)
{
    if (!owners.contains(owner))
        owners.insert(owner);
}

void Land::deleteOwner(Owner* owner)
{
    owners.erase(owner);
}

void Land::printOwners() const
{
    if (owners.empty())
        std::cout << *this << " does not have any owner.\n";
    else
    {
        std::cout << *this << " has owners: ";
        for (const auto* owner : owners)
        {
            std::cout << owner->getName() << ' ';
        }
        std::cout << "\n";
    }
}

double Land::getArea() const { return area; }

std::ostream& operator<<(std::ostream& out, const Land& land)
{
    return land.print(out);
}

void TriangleLand::setArea()
{
    area = side * height / 2.0;
}

TriangleLand::TriangleLand(double side = 0.0, double height = 0.0) :
    side{ side }, height{ height }
{
    setArea();
}


std::ostream& TriangleLand::print(std::ostream& out) const
{
    return out << "TriangleLand(side: " << side << ", height: " << height << ", area: " << area << ')';
}

void CircleLand::setArea()
{
    area = radius * radius * 3.14;
}

CircleLand::CircleLand(double radius = 0.0) :
    radius{ radius }
{
    setArea();
}

std::ostream& CircleLand::print(std::ostream& out) const
{
    return out << "CircleLand(radius: " << radius << ", area: " << area << ')';
}

void RectangleLand::setArea()
{
    area = width * length;
}

RectangleLand::RectangleLand(double width = 0.0, double length = 0.0) :
    width{ width }, length{ length }
{
    setArea();
}

std::ostream& RectangleLand::print(std::ostream& out) const
{
    return out << "RectangleLand(width: " << (width < length ? width : length) 
        << ", length: " << (width > length ? width : length) << ", area: " << area << ')';
}

SquareLand::SquareLand(double side = 0.0) :
    RectangleLand{ side, side }, side{ side }
{
}

std::ostream& SquareLand::print(std::ostream& out) const
{
    return out << "SquareLand(side: " << side << ", area: " << area << ')';
}