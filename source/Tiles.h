#pragma once
#include "stdafx.h"
#include <memory>
#include <SFML\Graphics.hpp>

class Board;

class TexturePack {
public:
	std::vector<std::shared_ptr<sf::Texture>> textures;

	TexturePack();

};

class ITile : public sf::Sprite {
protected:
	std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
	
public:
};

class IWarrior : public ITile {
protected:

public:
	
};

class GrassTile : public ITile {
private:
	
public:
	GrassTile();
	GrassTile(TexturePack texturePack);
};

class CastleRedTile : public ITile {
private:

public:
	CastleRedTile(TexturePack texturePack);
	CastleRedTile();
};

class CastleBlueTile : public ITile {
private:
	
public:
	CastleBlueTile(TexturePack texturePack);
	CastleBlueTile();
};

class PanelTile : public ITile {
private:

	const float _x = 0;
	const float _y = 500;
public:
	PanelTile(TexturePack texturePack);
	PanelTile();
};


class GoldTile : public ITile {
private:

	const float _x = 50;
	const float _y = 525;
public:
	GoldTile(TexturePack texturePack);
	GoldTile();
};

class ActionPointsTile : public ITile {
private:
	
	const float _x = 125;
	const float _y = 525;
public:
	ActionPointsTile(TexturePack texturePack);
	ActionPointsTile();
};


class WarriorRed :  public IWarrior {
private:
	
public:
	WarriorRed(TexturePack texturePack);
	WarriorRed();
};

class WarriorBlue :  public IWarrior {
private:
	
public:
	WarriorBlue(TexturePack texturePack);
	WarriorBlue();
};

