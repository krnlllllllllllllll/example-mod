#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "AIDecoPopup.hpp"   // <-- include your AI decorator mod header

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        // Create button
        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );

        // Add to bottom menu
        auto menu = this->getChildByID("bottom-menu");
        menu->addChild(btn);
        btn->setID("ai-deco-button"_spr);
        menu->updateLayout();

        return true;
    }

    void onMyButton(CCObject*) {
        // OPEN YOUR AI DECORATOR POPUP
        AIDecoPopup::create()->show();
    }
};
