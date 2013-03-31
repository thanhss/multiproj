#include "stdafx.h"
#include "MPTitleScene.h"
#include "MPMacros.h"
#include "MPTitleLayer.h"

USING_NS_CC;

CCScene * MPTitleScene::create()
{
	CCScene *scene = CCScene::create();
	CCLayer *layer = MPTitleLayer::create();
    scene->addChild(layer);
    return scene;
}


