#include "Land.h"
#include "LandChamber.h"
#include "Owner.h"
#include <iostream>

Owner::Owner(const std::string& name) : name{ name }
{
}

void Owner::addLand(Land* land, double landDivider)
{
    lands.insert({ land, landDivider });
    land->addOwner(this);
}

void Owner::deleteLand(Land* land)
{
    lands.erase(land);
    land->deleteOwner(this);
    if (!this->hasLands())
        LandChamber::deleteOwner(this);
}

bool Owner::hasLands() const { return !lands.empty(); }

const std::string& Owner::getName() const { return name; }

double Owner::getLandAreaSum() const
{
    double sum{ 0.0 };

    for (const auto& land : lands)
    {
        sum += land.first->getArea() / land.second;
    }

    return sum;
}

void Owner::printLands() const
{
    if (lands.empty())
        std::cout << name << " does not own any land.\n";
    else
    {
        std::cout << name << " owns lands:\n";

        for (const auto& land : lands)
        {
            std::cout << *land.first << ", ownership share: 1/" << land.second 
                << " (" << (land.first->getArea() / land.second) << ")\n";
        }
    }
}