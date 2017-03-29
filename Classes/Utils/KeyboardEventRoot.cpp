#include "KeyboardEventRoot.h"
#include "GameScene.h"


USING_NS_CC;

KeyboardEventRoot::KeyboardEventRoot(GameScene* scene)
	:_scene(scene)
{

}


void KeyboardEventRoot::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    //cocos2d::log("pressed");
	if (keyCode == EventKeyboard::KeyCode::KEY_M)
		_scene->_collidersLayer->setVisible(true);

}

void KeyboardEventRoot::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
 //   cocos2d::log("released");
	//MessageBox("A", "B");
	_scene->_collidersLayer->setVisible(false);
}