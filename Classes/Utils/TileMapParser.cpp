#include "TileMapParser.h"

using namespace cocos2d;

Game* TileMapParser::ParseTiledMap(cocos2d::TMXTiledMap * map)
{
	Size mapSize = map->getMapSize();

	TMXLayer* obstacles = map->layerNamed("colliders");

	/*mapSize.width columns with mapSize.height values to keep a[x][y] format*/
	std::vector<std::vector<Cell*>> *cellArray = new std::vector<std::vector<Cell*>>(mapSize.width, std::vector<Cell*>(mapSize.height));

	for (int i = 0; i < mapSize.width; i++)
	{
		for (int j = 0; j < mapSize.height; j++)
		{
			int gid = obstacles->getTileGIDAt(Vec2(i, j));

			ValueMap dict = map->propertiesForGID(gid).asValueMap();

			Value obstValue = dict["collidabe"];

			bool isObstacle = obstValue.asBool();

			if (isObstacle)
			{
				(*cellArray)[i][j] = new Cell(i, j, FieldCellType::OBSTACLE);
			}
			else
			{
				(*cellArray)[i][j] = new Cell(i, j, FieldCellType::FREE);
			}
		}
	}


	Game* game = new Game(mapSize.width, mapSize.height);
	game->initField(cellArray);

	return game;
}
