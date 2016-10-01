#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(HelloWorld);

	virtual void onTouchesBegan(const std::vector<Touch*>&
		touches, Event *unsed_event);

};

#endif // __HELLOWORLD_SCENE_H__
