#include "stdafx.h"
#include "HelloMapScene.h"
#include "HelloTitleScene.h"
#include "AppMacros.h"

USING_NS_CC;

CCScene* HelloMapScene::scene()
{
    CCScene *scene = CCScene::create();    
    HelloMapScene *layer = HelloMapScene::create();
    scene->addChild(layer);
    return scene;
}

bool HelloMapScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	// Exit button

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloMapScene::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
	// Screen Title

    CCLabelTTF* pLabel = CCLabelTTF::create("A Map Scene", "Arial", TITLE_FONT_SIZE);    
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    this->addChild(pLabel, 1);

	// Tile Map

//	CCTMXTiledMap *map = CCTMXTiledMap::create("hello_map/desert.tmx");
	CCTMXTiledMap *map = CCTMXTiledMap::create("ninja_map/TileMap.tmx");
    addChild(map, 0);
    
    return true;
}


void HelloMapScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(HelloTitleScene::scene());
}
