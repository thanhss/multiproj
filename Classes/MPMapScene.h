#ifndef __MP_MAP_SCENE_H__
#define __MP_MAP_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MPMapScene : public cocos2d::CCScene
{
public:
    static cocos2d::CCScene* create();

    void titleCallback(CCObject* pSender);
    
private:
    static CCLayer *createLayer();


};

#endif

