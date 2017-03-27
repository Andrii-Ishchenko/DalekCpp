#pragma once

#include "cocos2d.h"

USING_NS_CC;

static class KBListener
{
private:
    KBListener() {}
public:
    virtual void OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    virtual void OnKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

