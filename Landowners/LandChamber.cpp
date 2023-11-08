#include "LandChamber.h"

std::set<Land*> LandChamber::lands{};
std::set<Owner*> LandChamber::owners{};

void LandChamber::addLand(Land* land)
{
    lands.insert(land);
}

void LandChamber::deleteLand(Land* land)
{
    lands.erase(land);
}

void LandChamber::addOwner(Owner* owner)
{
    owners.insert(owner);
}

void LandChamber::deleteOwner(Owner* owner)
{
    owners.erase(owner);
}

void LandChamber::assignLandToOwner(Land* land, Owner* owner, double landDivider)
{
    addOwner(owner);
    owner->addLand(land, landDivider);
}

void LandChamber::takeLandFromOwner(Land* land, Owner* owner)
{
    owner->deleteLand(land);
}

void LandChamber::printOwnersInfo()
{
    for (const auto* owner : owners)
    {
        owner->printLands();
        std::cout << '\n' << owner->getName()
            << " has lands with total square: " << owner->getLandAreaSum() << "\n\n";
    }
}

void LandChamber::printLandsInfo()
{
    for (const auto* land : lands)
    {
        land->printOwners();
    }
}