#include "stdafx.h"
#include "MPTitleScene.h"
#include "MPBox2DScene.h"
#include "MPMacros.h"

USING_NS_CC;

void MPTitleScene::selectBox2D(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPBox2DScene::create());
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

	// Box2D button
    CCMenuItemImage *box2DItem = CCMenuItemImage::create(
                                     "CloseNormal.png",
                                     "CloseSelected.png",
                                     layer,
                                     menu_selector(MPTitleScene::selectBox2D));
	box2DItem->setPosition(ccp(
		origin.x + visibleSize.width - box2DItem->getContentSize().width/2 - 300,
		origin.y + box2DItem->getContentSize().height/2 + 300));
    


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
    CCMenu * menu = CCMenu::create(box2DItem, closeItem, NULL);
    menu->setPosition(CCPointZero);
    layer->addChild(menu, 1);

    return layer;
}


