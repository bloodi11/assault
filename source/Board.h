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
#include <SFML\Graphics.hpp>

class Text;
class WarriorRed;
class WarriorBlue;


class Board {   
private:
	std::unique_ptr<ITile> panelTile = std::make_unique<PanelTile>();
	std::unique_ptr<ITile> actionpointsTile = std::make_unique<ActionPointsTile>();
	std::unique_ptr<ITile> goldTile = std::make_unique<GoldTile>();	
	
public:
	std::array<std::array<std::shared_ptr<ITile>, 8>, 5> _area = { {
		{ std::make_unique<GrassTile>() , std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>() },
		{ std::make_unique<GrassTile>() , std::make_unique<CastleRedTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>() },
		{ std::make_unique<GrassTile>() , std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>() },
		{ std::make_unique<GrassTile>() , std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<CastleBlueTile>(), std::make_unique<GrassTile>() },
		{ std::make_unique<GrassTile>() , std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>(), std::make_unique<GrassTile>() },
		} };

	std::unique_ptr<IButton> hourglassButton = std::make_unique<HourGlassButton>();
	std::unique_ptr<IButton> questionmarkButton = std::make_unique<QuestionMarkButton>();
	std::unique_ptr<IButton> recruitSoldierButton = std::make_unique<RecruitSoldierButton>();
	std::unique_ptr<IButton> assaultButton = std::make_unique<AssaultButton>();

	std::unique_ptr<Text> _goldText;
	std::unique_ptr<Text> _actionPointsText;

	Board(std::unique_ptr<Root> &root);
	~Board();

	void setText(std::unique_ptr<Root> &root);
	void actualize(std::unique_ptr<Root> &root);
};
