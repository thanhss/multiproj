#ifndef __MP_MAP_SCENE_H__
#define __MP_MAP_SCENE_H__

#include "cocos2d.h"

class MPMapScene : public cocos2d::CCScene
{
public:
    static cocos2d::CCScene* create();

    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloMapScene);

};

#endif

