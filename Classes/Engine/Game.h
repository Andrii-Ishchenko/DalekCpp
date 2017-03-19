#pragma once
#include "Hero.h"
#include "Cell.h"
#include "Dalek.h"
#include "Heap.h"


#include <vector>
#include <cstdlib>

using namespace std;

enum class Direction : int
{
    UP =1,
    DOWN  =2,
    LEFT = 3,
    RIGHT = 4
};

class Game
{
public:
    Game(int mx, int my);
    ~Game();

private:
    Hero hero;

    vector<Dalek> daleks;
    vector<Heap> heaps;
    

	std::vector<std::vector<Cell*>> field;
    const int MX, MY;

    int level;
    int daleksCount;
public:
	void initField(std::vector<std::vector<Cell*>> *cellArray);
    void initLevel();
    
    void setHero();
    void setDaleks();
    
    bool canMove(Direction dir);
    void move(Direction dir);
    
    bool canTeleport() { return true; }
    void useTeleport();

    bool canAxe();
    void useAxe();
    
    void skipMove();
private:
    bool findByCoords(int x, int y);

};

