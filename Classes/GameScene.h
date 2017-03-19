#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Engine\Game.h"

using namespace cocos2d;

class GameScene :
	public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	TMXTiledMap * _map;
	TMXLayer * _backgroundLayer;
	TMXLayer * _collidersLayer;

	Game * _game;

public:
	CREATE_FUNC(GameScene);
};

#endif