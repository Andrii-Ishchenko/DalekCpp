#include "Game.h"
#include <algorithm>


Game::Game(int mx, int my) : 
    MX(mx),
    MY(my),
	hero(Hero(0,0)),
    daleks( vector<Dalek>())
{

}

Game::~Game()
{
	//destroy created objects, 2d arrays etc
}

void Game::initField(std::vector<std::vector<Cell*>>* cellArray)
{
	field = *cellArray;
}

void Game::initLevel()
{
    setHero();
    setDaleks();
}

void Game::setHero()
{
    int x = rand() % MX;
    int y = rand() % MY;

    hero.setX(x);
    hero.setY(y);
    hero.setDead(false);
    hero.setAxeAvailable(true);
}

void Game::setDaleks()
{
    daleksCount = 4 * level;
    
    daleks.clear();

    int i = 0;    
    
    while (i<daleksCount)
    {
        int x = rand() % MX;
        int y = rand() % MY;

		if (field[x][y]->isObstacle())
			continue;

        if (x == hero.getX() && y == hero.getY())
            continue;

        if (findByCoords(x, y))
            continue;
        
        daleks.push_back(Dalek(x, y));
        i++;
    }
}

bool Game::canMove(Direction dir)
{
    switch (dir)
    {
    case Direction::UP:
        return (hero.getY() < MY - 1);
        break;
    case Direction::DOWN:
        return (hero.getY() > 0);
        break;
    case Direction::LEFT:
        return (hero.getX() > 0);
        break;
    case Direction::RIGHT:
        return (hero.getX() < MX - 1);
        break;
    default:
        return false;
        break;
    }
}

void Game::move(Direction dir)
{
}

void Game::useTeleport()
{

}

bool Game::canAxe()
{
    return hero.isAxeAvailable();
}

void Game::useAxe()
{
}

void Game::skipMove()
{
}

bool Game::findByCoords(int x, int y)
{
    for (auto it = daleks.begin(); it <= daleks.end(); it++) 
    {
        if (it->getX() == x && it->getY() == y)
            return true;
    }

    return false;
}


