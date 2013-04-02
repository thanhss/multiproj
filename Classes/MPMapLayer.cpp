#include "stdafx.h"
#include "MPMapLayer.h"
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

    MPMapLayer::antiAliasMap(map);
        
    map->setAnchorPoint(ccp(.5, .5));
    map->setPosition(ccp(visibleSize.width * .5, visibleSize.height * .5));
    map->setScale(.5);
    map->setRotation(45);
    
    CCTMXLayer* layer = map->layerNamed("Background");
    assert(layer != NULL);

    CCSprite *tile = layer->tileAt(ccp(5,6));
    assert(tile != NULL);
    
    layer->removeTileAt(ccp(5, 6));
    
    CCActionInterval*  actionBy = CCMoveBy::create(2, ccp(visibleSize.width * .5, visibleSize.height * .5));
    map->runAction(actionBy);
    
    CCActionInterval* action = CCScaleBy::create(2, 2);
    map->runAction(action);

    
    
/*
    CCSize s = layer->getLayerSize();
    for (int x = 2; x < s.width; x++) {
        for (int y = 0; y < s.height; y++) {
            layer->removeTileAt(ccp(x, y));
        }
    }
*/
    return true;
}

void MPMapLayer::antiAliasMap(CCTMXTiledMap * map)
{
    CCArray * pChildrenArray = map->getChildren();
    CCSpriteBatchNode* child = NULL;
    CCObject* pObject = NULL;
    CCARRAY_FOREACH(pChildrenArray, pObject)
    {
        child = (CCSpriteBatchNode*)pObject;
        
        if(!child)
            break;
        
        child->getTexture()->setAntiAliasTexParameters();
    }
}

void MPMapLayer::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPTitleScene::create());
}
