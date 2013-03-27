#include "stdafx.h"
#include "MPBox2DScene.h"
#include "MPTitleScene.h"
#include "MPMacros.h"

USING_NS_CC;

CCScene *MPBox2DScene::create()
{
    CCScene *scene = CCScene::create();    
    CCLayer * layer = createLayer();
    scene->addChild(layer);
    return scene;
}

CCLayer *MPBox2DScene::createLayer()
{
	CCLayer *layer = CCLayer::create();
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        layer,
                                        menu_selector(MPBox2DScene::menuCloseCallback));
    
	backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                               origin.y + backItem->getContentSize().height/2));

    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    layer->addChild(menu, 1);
    
    CCLabelTTF* label = CCLabelTTF::create("Box 2D Scene", "Arial", TITLE_FONT_SIZE);    
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    layer->addChild(label, 1);
    
    return layer;
}

void MPBox2DScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPTitleScene::create());
}
