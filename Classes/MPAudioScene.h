#ifndef __MP_AUDIO_SCENE_H__
#define __MP_AUDIO_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MPAudioScene //: public cocos2d::CCScene
{
public:
    static cocos2d::CCScene* create();

	static cocos2d::CCSprite* player;
    
    void titleCallback(CCObject* pSender);

	// touch callback
	//void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    
    /*Not sure if maybe a pause screen would be a different scene where the paused instance would need to be used.
      If so, we would need basic accessor and mutator functions for paused unless it should be public.
     */
    void setPaused();
    
    bool getPaused();

private:
    static bool paused;
    
    static CCLayer *createLayer();

};



#endif 