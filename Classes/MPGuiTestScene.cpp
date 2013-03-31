#include "stdafx.h"
#include "MPGuiTestScene.h"
#include "MPGuiTestLayer.h"
#include "MPTitleScene.h"
#include "MPMacros.h"

USING_NS_CC;

CCScene *MPGuiTestScene::create() {
    CCScene *scene = CCScene::create();    
	CCLayer * layer = MPGuiTestLayer::create();
    scene->addChild(layer);
    return scene;
}