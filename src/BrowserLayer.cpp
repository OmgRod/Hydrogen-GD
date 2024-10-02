#include "BrowserLayer.hpp"

CCScene* BrowserLayer::scene() {
    auto scene = CCScene::create();
    scene->addChild(BrowserLayer::create());
    return scene;
}

void BrowserLayer::keyBackClicked() {
    CCDirector::get()->popScene();
}

BrowserLayer* BrowserLayer::create() {
    BrowserLayer* ret = new BrowserLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool BrowserLayer::init() {
    if (!CCLayer::init()) return false;

    setKeypadEnabled(true);

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto menu = CCMenu::create();

    menu->setPosition({0.f,0.f});
    menu->setAnchorPoint({0.f,1.f});

    this->addChild(menu);
    return true;
}
