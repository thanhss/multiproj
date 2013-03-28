#include "stdafx.h"
#include "MPMapScene.h"
#include "MPTitleScene.h"
#include "MPMacros.h"

USING_NS_CC;

CCScene* MPMapScene::create()
{
    CCScene *scene = CCScene::create();    
    CCLayer *layer = createLayer();
    scene->addChild(layer);
    return scene;
}

CCLayer *MPMapScene::createLayer()
{
    CCLayer *layer = CCLayer::create();
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	// Exit button

    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        layer,
                                        menu_selector(MPMapScene::titleCallback));
    
	backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                                origin.y + backItem->getContentSize().height/2));

    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    layer->addChild(menu, 1);
    
	// Screen Title

    CCLabelTTF* label = CCLabelTTF::create("A Map Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    layer->addChild(label, 1);

	// Tile Map

//	CCTMXTiledMap *map = CCTMXTiledMap::create("MP_map/desert.tmx");
	CCTMXTiledMap *map = CCTMXTiledMap::create("ninja_map/TileMap.tmx");
    layer->addChild(map, 0);
    
    return layer;
}


void MPMapScene::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPTitleScene::create());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    CCDirector::sharedDirector()->replaceScene(MPTitleScene::create());
#endif
}
