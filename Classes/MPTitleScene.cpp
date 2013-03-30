#include "stdafx.h"
#include "MPTitleScene.h"
#include "MPBox2DScene.h"
#include "MPGuiTestScene.h"
#include "MPAudioScene.h"
#include "MPMapScene.h"
#include "MPMacros.h"

USING_NS_CC;

void MPTitleScene::selectBox2D(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPBox2DScene::create());
}

void MPTitleScene::selectGuiTest(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPGuiTestScene::create());
}

void MPTitleScene::selectAudio(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPAudioScene::create());
}

void MPTitleScene::selectMap(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPMapScene::create());
}

void MPTitleScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    exit(0);
#endif
}

CCScene * MPTitleScene::create()
{
	CCScene *scene = CCScene::create();
	CCLayer *layer = createLayer();
    scene->addChild(layer);
    return scene;
}

CCLayer *MPTitleScene::createLayer()
{
	CCLayer * layer = CCLayer::create();
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // Scene title 
    CCLabelTTF* pLabel = CCLabelTTF::create("Title Scene", "Arial", TITLE_FONT_SIZE);    
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    layer->addChild(pLabel, 1);

	// Layout the selectable labels.

	int yInc = 40;
	int xPos = 250;
	int yPos = 100;

	// Box2D menu item label
    CCLabelTTF* box2DLabel = CCLabelTTF::create("Box 2D Scene", "Arial", TITLE_FONT_SIZE);
    box2DLabel->setPosition(CCPointZero);
    CCMenuItemLabel *box2DItem = CCMenuItemLabel::create(
                                     box2DLabel,
                                     layer,
                                     menu_selector(MPTitleScene::selectBox2D));
	box2DItem->setPosition(xPos, yPos);

	// GUI Test menu item label
	yPos += yInc;
    CCLabelTTF* guiTestLabel = CCLabelTTF::create("GUI Test Scene", "Arial", TITLE_FONT_SIZE);
    guiTestLabel->setPosition(CCPointZero);
    CCMenuItemLabel *guiTestItem = CCMenuItemLabel::create(
                                     guiTestLabel,
                                     layer,
                                     menu_selector(MPTitleScene::selectGuiTest));
	guiTestItem->setPosition(xPos, yPos);
    
    // Audio Button
	yPos += yInc;
    CCLabelTTF* audioLabel = CCLabelTTF::create("Audio Scene", "Arial", TITLE_FONT_SIZE);
    audioLabel->setPosition(CCPointZero);
    
    CCMenuItemLabel *audioItem = CCMenuItemLabel::create(
                                                         audioLabel,
                                                         layer,
                                                         menu_selector(MPTitleScene::selectAudio));
	audioItem->setPosition(xPos, yPos);
    
    // Map Button
	yPos += yInc;
    CCLabelTTF* mapLabel = CCLabelTTF::create("Map Scene", "Arial", TITLE_FONT_SIZE);
    mapLabel->setPosition(CCPointZero);
    
    CCMenuItemLabel *mapItem = CCMenuItemLabel::create(
                                                         mapLabel,
                                                         layer,
                                                         menu_selector(MPTitleScene::selectMap));
	mapItem->setPosition(xPos, yPos);
    


	// Close button
    CCMenuItemImage *closeItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        layer,
                                        menu_selector(MPTitleScene::menuCloseCallback));
	closeItem->setPosition(ccp(
		origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
        origin.y + closeItem->getContentSize().height/2));

	// Menu container
    CCMenu * menu = CCMenu::create(box2DItem, guiTestItem, audioItem, mapItem, closeItem, NULL);
    menu->setPosition(CCPointZero);
    layer->addChild(menu, 1);

    return layer;
}


