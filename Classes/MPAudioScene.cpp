#include "stdafx.h"
#include "MPAudioScene.h"
#include "MPTitleScene.h"
#include "MPMacros.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

bool MPAudioScene::paused = false;

CCSprite *MPAudioScene::player = NULL;

CCScene* MPAudioScene::create()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    CCLayer *layer = createLayer();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
CCLayer *MPAudioScene::createLayer()
{
    CCLayer *layer = CCLayer::create();
    
    paused = false;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	//enable touch on screen
	layer->setTouchEnabled(true);
	//this->setTouchMode(cocos2d::ccTouchesMode::kCCTouchesOneByOne);

    CCMenuItemImage *backItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        layer,
                                        menu_selector(MPAudioScene::titleCallback));
    
	backItem->setPosition(ccp(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
                                origin.y + backItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    layer->addChild(menu, 1);

    //Scene Title
    
    CCLabelTTF* label = CCLabelTTF::create("Audio Scene", "Arial", TITLE_FONT_SIZE);
    
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    layer->addChild(label, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    layer->addChild(pSprite, 0);

	player = CCSprite::create("dragon_sign.png");
	
	//player->setContentSize(CCSizeMake(player->getContentSize().width*3, player->getContentSize().height*3));
	player ->setPosition(ccp(visibleSize.width/3, visibleSize.height/3));

	layer->addChild(player, 1);

	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("background.mp3");
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);

    
    return layer;
}

void MPAudioScene::titleCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    exit(0);
#endif
}

void MPAudioScene::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
	CCTouch* touch = (CCTouch*) (pTouches->anyObject());
	CCPoint location = touch->getLocation();

    //Changes the play and pause state depending on paused instance
    if(paused != false){
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        paused = false;
    }
    else{
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        paused = true;
    }

	//move player to touch point
	player->setPosition(location);
	
}