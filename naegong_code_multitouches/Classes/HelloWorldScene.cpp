#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool HelloWorld::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	auto listener = EventListenerTouchAllAtOnce::create();                  // 멀티 터치 이벤트
	listener -> onTouchesBegan = CC_CALLBACK_2
		(HelloWorld::onTouchesBegan, this);
	Director::getInstance() -> getEventDispatcher() ->
		addEventListenerWithFixedPriority(listener, 1);
	
	return true;
}


void HelloWorld::onTouchesBegan(const std::vector<Touch*> & touches,
								Event *unused_event)
{
	CCLOG("onTouchesBegan");

	std::vector<Touch*>::const_iterator it = touches.begin();
	Touch *touch;
	Point location[2];

	for (int i = 0; i < touches.size(); i++) {
		touch = (Touch*) (*it);
		location[i] = touch -> getLocation();
		it++;

		CCLOG("location[%d] x = %f, y = %f", i, location[i].x, location[i].y);
	}																					// 터치한 곳 좌표값 구하기
}
