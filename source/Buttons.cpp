#include "stdafx.h"

HourGlassButton::HourGlassButton() {
	_texture->loadFromFile("img/hourglass.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

QuestionMarkButton::QuestionMarkButton() {
	_texture->loadFromFile("img/questionmark.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

RecruitSoldierButton::RecruitSoldierButton()
{
	_texture->loadFromFile("img/warriors.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

AssaultButton::AssaultButton() {
	_texture->loadFromFile("img/swords.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}