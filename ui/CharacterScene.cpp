#include"CharacterScene.h"

#include<ui/CocosGUI.h>

#include"ui/ConsoleLayer.h"
#include"ui/Resource.h"
#include"runtime/Macros.h"

USING_NS_CC;

bool CharacterScene::init() {
	if(!Scene::init()) {
		return false;
	}
	//BackButton
	this->addChild(CreateDefaultButton(T("back"), Vec2(23, 745), Size(40, 40),
				   [&](Ref* sender, ui::Widget::TouchEventType type) {
					   switch(type) {
					   case ui::Widget::TouchEventType::BEGAN:

						   Director::getInstance()->popScene();
						   break;
					   }
				   },
				   T("<-"), FONTS_KAI, 32, Color3B(0, 0, 0)));

	//Key
	CONSOLE_KEY;

	return true;
}

bool CharacterWidget::init() {
	this->setContentSize(Size(400, 500));

	auto BackGround = LayerColor::create(Color4B::GRAY, 400, 500);
	this->addChild(BackGround);

	auto CharNameLabel = Label::createWithTTF(CharName, FONTS_KAI, 32);
	CharNameLabel->setPosition(Vec2(66, 466));
	CharNameLabel->setContentSize(Size(300, 40));
	this->addChild(CharNameLabel);

	auto CharPhotoSprite = Sprite::create(DIR_IMAGES + "Button_Normal.png");
	CharPhotoSprite->setPosition(79, 340);
	CharPhotoSprite->setContentSize(Size(133, 182));
	this->addChild(CharPhotoSprite);

	return true;
}