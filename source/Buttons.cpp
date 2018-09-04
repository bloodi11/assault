#include "stdafx.h"

HourGlassButton::HourGlassButton() {}
HourGlassButton::HourGlassButton(TexturePack texturePack) {
	_texture = texturePack.textures[8];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

QuestionMarkButton::QuestionMarkButton() {}
QuestionMarkButton::QuestionMarkButton(TexturePack texturePack) {
	_texture = texturePack.textures[9];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

RecruitSoldierButton::RecruitSoldierButton(){}
RecruitSoldierButton::RecruitSoldierButton(TexturePack texturePack)
{
	_texture = texturePack.textures[10];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

AssaultButton::AssaultButton() {}
AssaultButton::AssaultButton(TexturePack texturePack) {
	_texture = texturePack.textures[11];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}