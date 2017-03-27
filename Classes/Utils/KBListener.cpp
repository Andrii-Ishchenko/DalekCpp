#include "KBListener.h"

USING_NS_CC;

void KBListener::OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    cocos2d::log("pressed");
}

void KBListener::OnKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
   // MessageBox("ABC", "DEF");
    cocos2d::log("released");
}