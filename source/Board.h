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
public:
	TexturePack tP;

	std::array<std::array<std::shared_ptr<ITile>, 8>, 5> _area = { {
		{ std::make_unique<GrassTile>(tP) , std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP) },
		{ std::make_unique<GrassTile>(tP) , std::make_unique<CastleRedTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP) },
		{ std::make_unique<GrassTile>(tP) , std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP) },
		{ std::make_unique<GrassTile>(tP) , std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<CastleBlueTile>(tP), std::make_unique<GrassTile>(tP) },
		{ std::make_unique<GrassTile>(tP) , std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP), std::make_unique<GrassTile>(tP) },
		} };

	std::unique_ptr<IButton> hourglassButton = std::make_unique<HourGlassButton>(tP);
	std::unique_ptr<IButton> questionmarkButton = std::make_unique<QuestionMarkButton>(tP);
	std::unique_ptr<IButton> recruitSoldierButton = std::make_unique<RecruitSoldierButton>(tP);
	std::unique_ptr<IButton> assaultButton = std::make_unique<AssaultButton>(tP);

	std::unique_ptr<Text> _goldText;
	std::unique_ptr<Text> _actionPointsText;

	Board(Root &root);

	void setText(Root &root);
	void actualize(Root &root);
};
