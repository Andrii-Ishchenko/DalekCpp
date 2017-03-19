#ifndef _TILE_MAP_PARSER_H_
#define _TILE_MAP_PARSER_H_

#include "cocos2d.h"
#include "Engine\Game.h"

class TileMapParser 
{
public:
	static Game* ParseTiledMap(cocos2d::TMXTiledMap* map);

private:
	TileMapParser();
};

#endif // !_TILE_MAP_PARSER_H_
