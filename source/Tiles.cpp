#include "stdafx.h"

ITile::~ITile() {
	_texture.reset();
}


GrassTile::GrassTile() {
	_texture->loadFromFile("img/grass2.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

CastleRedTile::CastleRedTile() {
	_texture->loadFromFile("img/castleRed2.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}


CastleBlueTile::CastleBlueTile() {
	_texture->loadFromFile("img/castleBlue.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

PanelTile::PanelTile() {
	_texture->loadFromFile("img/panel-wooden.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}


GoldTile::GoldTile() {
	_texture->loadFromFile("img/gold.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

ActionPointsTile::ActionPointsTile() {
	_texture->loadFromFile("img/actionPoints.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}


//_____________________________________________WARRIOR RED
WarriorRed::WarriorRed() {
	_texture->loadFromFile("img/warriorRed2.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}



//_______________________________________________WARRIOR BLUE
WarriorBlue::WarriorBlue() {
	_texture->loadFromFile("img/warriorBlue2.jpg");
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

