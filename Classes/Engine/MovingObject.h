#pragma once

class MovingObject
{
public:
    MovingObject(int x, int y);
    ~MovingObject();
    
protected:
    int x, y;
    bool isDead;

public:
    int getX() { return x; }
    void setX(int value) { x = value; }

    int getY() { return y; }
    void setY(int value) { y = value; }

    bool  IsDead() { return isDead; }
    void setDead(bool status) { isDead = status; }
    
};