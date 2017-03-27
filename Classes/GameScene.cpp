#include "GameScene.h"
#include "Utils\TileMapParser.h"
#include "Utils\KBListener.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	_map = new TMXTiledMap();
	_map->initWithTMXFile("D:/Assets/Maps/Dalek.tmx");
	
	_collidersLayer = _map->layerNamed("colliders");
	_collidersLayer->setVisible(false);

	_game = TileMapParser::ParseTiledMap(_map);

	_map->setAnchorPoint(Vec2(0.5f, 0.5f));

	Size mapSize = _map->getContentSize();
	_map->setPosition(origin.x + visibleSize.width /2 ,origin.y + visibleSize.height/2);

	this->addChild(_map,0);

	auto label = LabelTTF::create("Scores", "Segoe UI Light", 24);
	label->setColor(Color3B(255, 0, 0));
	label->setAnchorPoint(Vec2(0, 1));

	//label->setPosition(Vec2(origin.x + visibleSize.width / 2 - mapSize.width / 2, origin.y + visibleSize.height / 2 + mapSize.height / 2 + 5));
	label->setPosition(Vec2(origin.x + 5, origin.y+visibleSize.height));
	this->addChild(label, 1);

    auto listener = EventListenerKeyboard::create();
   // listener->onKeyPressed = CC_CALLBACK_2(KBListener::OnKeyPressed, this);
    //listener->onKeyReleased = CC_CALLBACK_2(KBListener::OnKeyReleased, this);

    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) 
    {
        _collidersLayer->setVisible(false);
    };

    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        if (keyCode == EventKeyboard::KeyCode::KEY_M)
            _collidersLayer->setVisible(true);
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}