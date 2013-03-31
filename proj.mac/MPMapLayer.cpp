#include "MPMapLayer.h"
#include "stdafx.h"
#include "MPTitleScene.h"
#include "MPMacros.h"

USING_NS_CC;

bool MPMapLayer::init(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
	// Exit button
    
    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                                        "CloseNormal.png",
                                                        "CloseSelected.png",
                                                        this,
                                                        menu_selector(MPMapLayer::titleCallback));
    
	backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                              origin.y + backItem->getContentSize().height/2));
    
    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);
    
	// Screen Title
    
    CCLabelTTF* label = CCLabelTTF::create("A Map Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);
    
	// Tile Map
    
    //	CCTMXTiledMap *map = CCTMXTiledMap::create("MP_map/desert.tmx");
	CCTMXTiledMap *map = CCTMXTiledMap::create("ninja_map/TileMap.tmx");
    this->addChild(map, 0);
    
    return true;
}

void MPMapLayer::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPTitleScene::create());
}
