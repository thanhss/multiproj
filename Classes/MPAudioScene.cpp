#include "stdafx.h"
#include "MPAudioScene.h"
#include "MPAudioLayer.h"
#include "MPMacros.h"

USING_NS_CC;

CCScene* MPAudioScene::create() {
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPAudioLayer::create();
    scene->addChild(layer);
    return scene;
}