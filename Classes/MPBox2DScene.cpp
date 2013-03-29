#include "stdafx.h"
#include "MPBox2DScene.h"
#include "MPBox2DLayer.h"
#include "MPTitleScene.h"
#include "MPMacros.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

CCScene *MPBox2DScene::create()
{
    CCScene *scene = CCScene::create();    
	CCLayer * layer = MPBox2DLayer::create();
    scene->addChild(layer);
    return scene;
}
