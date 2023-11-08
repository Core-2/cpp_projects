#ifndef OWNER_H
#define OWNER_H

#include <map>
#include <string>
//#include <set>

class Land;

class Owner
{
private:
    std::string name{};
    //std::set<Land*> lands{};
    std::map<Land*, double> lands{};

public:
    Owner(const std::string& name);

    void addLand(Land* land, double landDivider = 0.0);

    void deleteLand(Land* land);

    bool hasLands() const;

    const std::string& getName() const;

    double getLandAreaSum() const;

    void printLands() const;
};

#endif // !OWNER_H
