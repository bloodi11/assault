#pragma once
#include "stdafx.h"

class GameManager;
class Root;

class IButton : public ITile {
protected:
	
public:
	
};

class HourGlassButton : public IButton {
private:
	std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
	const float _x = 700;
	const float _y = 525;
public:
	
	HourGlassButton();
};

class QuestionMarkButton : public IButton {
private:
	std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
	const float _x = 325;
	const float _y = 525;
public:
	
	QuestionMarkButton();
};

class RecruitSoldierButton : public IButton {
private:
	std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
	const float _x = 385;
	const float _y = 525;
public:
	RecruitSoldierButton();
};


class AssaultButton : public IButton {
private:
	std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
	const float _x = 445;
	const float _y = 525;
public:
	AssaultButton();
};


