#ifndef LANDCHAMBER_H
#define LANDCHAMBER_H

#include "Land.h"
#include "Owner.h"
#include <set>

class LandChamber
{
private:
    static std::set<Land*> lands;
    static std::set<Owner*> owners;

public:
    static void addLand(Land* land);

    static void deleteLand(Land* land);

    static void addOwner(Owner* owner);

    static void deleteOwner(Owner* owner);

    static void assignLandToOwner(Land* land, Owner* owner, double landDivider = 1.0);

    static void takeLandFromOwner(Land* land, Owner* owner);

    static void printOwnersInfo();

    static void printLandsInfo();
};

#endif // !LANDCHAMBER_H
