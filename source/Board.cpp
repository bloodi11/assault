#include "stdafx.h"


Board::Board(Root& root) {

	actualize(root);
}


void Board::setText(Root &root) {
	if (root._turnOfPlayer == 1) {
		_goldText = std::make_unique<Text>(std::to_string(root.playerRed->getGold()), 55, 560);
		_actionPointsText = std::make_unique<Text>(std::to_string(root.playerRed->getActionPoints()), 130, 560);
	}
	else if (root._turnOfPlayer == 2) {
		_goldText = std::make_unique<Text>(std::to_string(root.playerBlue->getGold()), 55, 560);
		_actionPointsText = std::make_unique<Text>(std::to_string(root.playerBlue->getActionPoints()), 130, 560);
	}
}




void Board::actualize(Root &root) {
	root._window->clear();
	setText(root);
	//auto panel = std::make_unique<PanelTile>(tP);
	PanelTile panel(tP);
	auto gold = std::make_unique<GoldTile>(tP);
	auto actionPoints = std::make_unique<ActionPointsTile>(tP);

	root._window->draw(panel);
	root._window->draw(*gold);
	root._window->draw(*actionPoints);
	root._window->draw(*hourglassButton);
	root._window->draw(*std::move(std::make_unique<ITile>(*questionmarkButton)));
	root._window->draw(*std::move(std::make_unique<ITile>(*recruitSoldierButton)));
	root._window->draw(*std::move(std::make_unique<ITile>(*assaultButton)));


	float y = 0;
	float x = 0;
	for (auto& element : _area) {
		for (auto& tile : element) {
			tile->setPosition(x, y);
			root._window->draw(*std::move(std::make_unique<ITile>(*tile)));
			x = x + 100;
		}
		y = y + 100;
		x = 0;
	}

	root._window->draw(*_actionPointsText);
	root._window->draw(*_goldText);
	
	root._window->display();
}

