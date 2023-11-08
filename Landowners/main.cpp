#include "Land.h"
#include "LandChamber.h"
#include "Owner.h"
#include <iostream>
#include <list>

int main()
{
    TriangleLand land1{ 5.0, 4.0 };
    TriangleLand land2{ 3.5, 8.0 };
    CircleLand land3{ 3.0 };
    CircleLand land4{ 5.5 };
    RectangleLand land5{ 6.0, 1.5 };
    RectangleLand land6{ 4.5, 2.0 };
    SquareLand land7{ 5.0 };
    SquareLand land8{ 7.0 };

    Owner owner1{ "Johnson" };
    LandChamber::assignLandToOwner(&land1, &owner1);
    LandChamber::assignLandToOwner(&land4, &owner1);

    Owner owner2{ "Stevens" };
    LandChamber::assignLandToOwner(&land2, &owner2);
    LandChamber::assignLandToOwner(&land6, &owner2);
    LandChamber::assignLandToOwner(&land7, &owner2);

    Owner owner3{ "Rodriguez" };
    LandChamber::assignLandToOwner(&land3, &owner3);

    Owner owner4{ "Trevis" };

    Owner owner5{ "Phillips" };

    Owner owner6{ "Parker" };

    LandChamber::printOwnersInfo();

    std::cout << "-----------------------------------------------\n\n";

    LandChamber::printLandsInfo();

    std::cout << "\n-----------------------------------------------\n\n";

    LandChamber::takeLandFromOwner(&land3, &owner3);

    LandChamber::assignLandToOwner(&land3, &owner4, 3.0);
    LandChamber::assignLandToOwner(&land3, &owner5, 3.0);
    LandChamber::assignLandToOwner(&land3, &owner6, 3.0);

    LandChamber::assignLandToOwner(&land5, &owner1, 2.0);
    LandChamber::assignLandToOwner(&land5, &owner6, 2.0);

    LandChamber::printOwnersInfo();

    std::cout << "-----------------------------------------------\n\n";

    LandChamber::printLandsInfo();

    return 0;
}