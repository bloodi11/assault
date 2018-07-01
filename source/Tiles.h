#pragma once
#include "stdafx.h"
#include <memory>
#include <SFML\Graphics.hpp>

class Board;


class ITile : public sf::Sprite {
protected:
	std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
	
public:
	~ITile();
};

class IWarrior : public ITile {
protected:

public:
	
};

class GrassTile : public ITile {
private:
	
public:
	
	GrassTile();
};

class CastleRedTile : public ITile {
private:

public:
	
	CastleRedTile();
};

class CastleBlueTile : public ITile {
private:
	
public:
	
	CastleBlueTile();
};

class PanelTile : public ITile {
private:

	const float _x = 0;
	const float _y = 500;
public:
	
	PanelTile();
};


class GoldTile : public ITile {
private:

	const float _x = 50;
	const float _y = 525;
public:
	
	GoldTile();
};

class ActionPointsTile : public ITile {
private:
	
	const float _x = 125;
	const float _y = 525;
public:

	ActionPointsTile();
};


class WarriorRed :  public IWarrior {
private:
	
public:
	WarriorRed();
};

class WarriorBlue :  public IWarrior {
private:
	
public:
	
	WarriorBlue();

};

