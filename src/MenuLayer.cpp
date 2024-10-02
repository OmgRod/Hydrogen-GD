#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

#include "BrowserLayer.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("HN_modBtn_001.png"_spr),
			this,
			menu_selector(MyMenuLayer::onHydrogen)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("hydrogen-btn"_spr);

		menu->updateLayout();

		return true;
	}

	void onHydrogen(CCObject*) {
		auto scenePrev = CCTransitionFade::create(0.5f, BrowserLayer::scene());
        CCDirector::sharedDirector()->replaceScene(scenePrev);
	}
};