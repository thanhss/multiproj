#include "stdafx.h"
#include "MPMapScene.h"
#include "MPMapLayer.h"
#include "MPMacros.h"

USING_NS_CC;

CCScene* MPMapScene::create()
{
    CCScene *scene = CCScene::create();    
    CCLayer *layer = MPMapLayer::create();
    scene->addChild(layer);
    return scene;
}
