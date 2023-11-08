#ifndef LAND_H
#define LAND_H

#include "Owner.h"
#include <set>
#include <iostream>

class Land
{
protected:
    double area{};
    std::set<Owner*> owners{};

    Land(double);

    virtual void setArea() = 0;

    void addOwner(Owner* owner);

    void deleteOwner(Owner* owner);

public:
    double getArea() const;

    void printOwners() const;

    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Land& land);

    friend void Owner::addLand(Land* land, double ownershipShare);

    friend void Owner::deleteLand(Land* land);
};

class TriangleLand : public Land
{
private:
    double side{};
    double height{};

protected:
    void setArea() override;

public:
    TriangleLand(double, double height);

    std::ostream& print(std::ostream& out) const override;
};

class CircleLand : public Land
{
private:
    double radius{};

protected:
    void setArea() override;

public:
    CircleLand(double radius);

    std::ostream& print(std::ostream& out) const override;
};

class RectangleLand : public Land
{
private:
    double width{};
    double length{};

protected:
    void setArea() override;

public:
    RectangleLand(double, double);

    std::ostream& print(std::ostream& out) const override;
};

class SquareLand : public RectangleLand
{
private:
    double side{};

public:
    SquareLand(double side);

    std::ostream& print(std::ostream& out) const override;
};

#endif // !LAND_H
