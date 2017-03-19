#pragma once
#include "MovingObject.h"
class Hero :
    public MovingObject
{
public:
    Hero(int x, int y);
    ~Hero();

protected:

    bool axeAvailable;

public:
    void setAxeAvailable(bool value) { axeAvailable = value; }
    bool isAxeAvailable() { return axeAvailable; }
};

