#pragma once
#include "stdafx.h"
#include "Board.h"
#include "Tiles.h"
#include "Buttons.h"
#include "Player.h"
#include <memory>
#include <array>
#include <string>
#include <iostream>
#include <thread>
#include <SFML\Graphics.hpp>

class Window;

class Root {
public:
	std::unique_ptr<Window> _window;
	sf::Event _event;
	sf::Event _event2;
	sf::Mouse _mouse;

	int _turnOfPlayer = 1;
	std::unique_ptr<PlayerRed> playerRed = std::make_unique<PlayerRed>();
	std::unique_ptr<PlayerBlue> playerBlue = std::make_unique<PlayerBlue>();
	
	Root();
};


class Window : public sf::RenderWindow {
private:
	const int _screenWidth = 800;
	const int _screenHeight = 600;
	const int _fps = 60;

public:
	Window();
};

class Text : public sf::Text {
private:
	std::unique_ptr<sf::Font> _font;
	std::unique_ptr<sf::Color> _color;
public:
	Text(std::string string, float x, float y);
	~Text();
};


class GameManager {
private:
	std::unique_ptr<Board> _board;
	Root _root;
	
public:
	GameManager();
	GameManager(Root &root);
	~GameManager();

	int getTurn();
	void setTurn(int turn);
	void changeTurn();
	void waitForEvent();
};

