#include "stdafx.h"
#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	//enable touch on screen
	this->setTouchEnabled(true);
	//this->setTouchMode(cocos2d::ccTouchesMode::kCCTouchesOneByOne);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	player = CCSprite::create("dragon_sign.png");
	
	//player->setContentSize(CCSizeMake(player->getContentSize().width*3, player->getContentSize().height*3));
	player->setPosition(ccp(visibleSize.width/3, visibleSize.height/3));

	this->addChild(player, 1);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    exit(0);
#endif
}

void HelloWorld::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
	CCTouch* touch = (CCTouch*) (pTouches->anyObject());
	CCPoint location = touch->getLocation();

	//resume music if click on player
	//pause music if click on the other point
	if(location.x > player->getPosition().x
		&& location.x < (player->getPosition().x + player->getContentSize().width)
		&& location.y > player->getPosition().y
		&& location.y < (player->getPosition().y + player->getContentSize().height))

	//bool test = SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
	//if( test)
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	else
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		

	//move player to touch point
	player->setPosition(location);
	
}