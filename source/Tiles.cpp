#include "stdafx.h"

TexturePack::TexturePack() {
	std::shared_ptr<sf::Texture> t0 = std::make_shared<sf::Texture>();
	t0->loadFromFile("img/grass2.jpg");
	textures.push_back(t0);

	std::shared_ptr<sf::Texture> t1 = std::make_shared<sf::Texture>();
	t1->loadFromFile("img/castleRed2.jpg");
	textures.push_back(t1);

	std::shared_ptr<sf::Texture> t2 = std::make_shared<sf::Texture>();
	t2->loadFromFile("img/castleBlue.jpg");
	textures.push_back(t2);

	std::shared_ptr<sf::Texture> t3 = std::make_shared<sf::Texture>();
	t3->loadFromFile("img/panel-wooden.jpg");
	textures.push_back(t3);

	std::shared_ptr<sf::Texture> t4 = std::make_shared<sf::Texture>();
	t4->loadFromFile("img/gold.jpg");
	textures.push_back(t4);

	std::shared_ptr<sf::Texture> t5 = std::make_shared<sf::Texture>();
	t5->loadFromFile("img/actionPoints.jpg");
	textures.push_back(t5);

	std::shared_ptr<sf::Texture> t6 = std::make_shared<sf::Texture>();
	t6->loadFromFile("img/warriorRed2.jpg");
	textures.push_back(t6);

	std::shared_ptr<sf::Texture> t7 = std::make_shared<sf::Texture>();
	t7->loadFromFile("img/warriorBlue2.jpg");
	textures.push_back(t7);

	std::shared_ptr<sf::Texture> t8 = std::make_shared<sf::Texture>();
	t8->loadFromFile("img/hourglass.jpg");
	textures.push_back(t8);


	std::shared_ptr<sf::Texture> t9 = std::make_shared<sf::Texture>();
	t9->loadFromFile("img/questionmark.jpg");
	textures.push_back(t9);

	std::shared_ptr<sf::Texture> t10 = std::make_shared<sf::Texture>();
	t10->loadFromFile("img/warriors.jpg");
	textures.push_back(t10);

	std::shared_ptr<sf::Texture> t11 = std::make_shared<sf::Texture>();
	t11->loadFromFile("img/swords.jpg");
	textures.push_back(t11);

}

GrassTile::GrassTile(){}

GrassTile::GrassTile(TexturePack texturePack) {
	_texture = texturePack.textures[0];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

CastleRedTile::CastleRedTile(){}
CastleRedTile::CastleRedTile(TexturePack texturePack) {
	_texture = texturePack.textures[1];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

CastleBlueTile::CastleBlueTile(){}
CastleBlueTile::CastleBlueTile(TexturePack texturePack) {
	_texture = texturePack.textures[2];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

PanelTile::PanelTile(){}
PanelTile::PanelTile(TexturePack texturePack) {
	_texture = texturePack.textures[3];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

GoldTile::GoldTile(){}
GoldTile::GoldTile(TexturePack texturePack) {
	_texture = texturePack.textures[4];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}

ActionPointsTile::ActionPointsTile(){}
ActionPointsTile::ActionPointsTile(TexturePack texturePack) {
	_texture = texturePack.textures[5];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
	this->setPosition(_x, _y);
}


//_____________________________________________WARRIOR RED
WarriorRed::WarriorRed(){}
WarriorRed::WarriorRed(TexturePack texturePack) {
	_texture = texturePack.textures[6];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}



//_______________________________________________WARRIOR BLUE
WarriorBlue::WarriorBlue(){}
WarriorBlue::WarriorBlue(TexturePack texturePack) {
	_texture = texturePack.textures[7];
	_texture->setSmooth(true);
	this->setTexture(*_texture);
}

