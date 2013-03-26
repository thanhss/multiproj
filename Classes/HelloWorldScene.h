#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorldScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	cocos2d::CCSprite* player;
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorldScene);

	// touch callback
	void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    
    /*Not sure if maybe a pause screen would be a different scene where the paused instance would need to be used.
      If so, we would need basic accessor and mutator functions for paused unless it should be a boolean.
     */
    void setPaused();
    
    bool getPaused();

private:
    bool paused;

};



#endif // __HELLOWORLD_SCENE_H__
