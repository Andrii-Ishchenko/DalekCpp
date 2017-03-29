#pragma once

#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;



class KeyboardEventRoot
{
private:
	GameScene* _scene;

public:
	KeyboardEventRoot() {};
	KeyboardEventRoot(GameScene* scene);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

