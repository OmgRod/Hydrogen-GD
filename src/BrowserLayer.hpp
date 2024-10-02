#ifndef BROWSER_LAYER_HPP
#define BROWSER_LAYER_HPP

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class BrowserLayer : public CCLayer {
public:
    static CCScene* scene();
    virtual void keyBackClicked();
    static BrowserLayer* create();
    bool init();
};

#endif // BROWSER_LAYER_HPP