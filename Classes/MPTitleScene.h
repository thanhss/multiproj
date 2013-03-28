#ifndef __MP_TITLE_SCENE_H__
#define __MP_TITLE_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MPTitleScene : public cocos2d::CCScene
{
public:
    static cocos2d::CCScene * create();
    void menuCloseCallback(CCObject* pSender);
    void selectBox2D(CCObject* pSender);
    void selectAudio(CCObject* pSender);
    void selectMap(CCObject* pSender);

private:
    static CCLayer *createLayer();
};

#endif

