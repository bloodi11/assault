#include "stdafx.h"


Board::Board(std::unique_ptr<Root> &root) {

	actualize(root);
}

Board::~Board() {

	for (auto &element : _area) {
		for (auto &tile : element) {
			tile.reset();
		}
	}
	
	goldTile.reset();
	panelTile.reset();
	actionpointsTile.reset();
	hourglassButton.reset();
	recruitSoldierButton.reset();

	_actionPointsText.reset();
	_goldText.reset();
}

void Board::setText(std::unique_ptr<Root> &root) {
	if (root->_turnOfPlayer == 1) {
		_goldText = std::make_unique<Text>(std::to_string(root->playerRed->getGold()), 55, 560);
		_actionPointsText = std::make_unique<Text>(std::to_string(root->playerRed->getActionPoints()), 130, 560);
	}
	else if (root->_turnOfPlayer == 2) {
		_goldText = std::make_unique<Text>(std::to_string(root->playerBlue->getGold()), 55, 560);
		_actionPointsText = std::make_unique<Text>(std::to_string(root->playerBlue->getActionPoints()), 130, 560);
	}
}


void Board::actualize(std::unique_ptr<Root> &root) {
	root->_window->clear();
	setText(root);
	root->_window->draw(*panelTile);
	root->_window->draw(*goldTile);
	root->_window->draw(*actionpointsTile);
	root->_window->draw(*hourglassButton);
	root->_window->draw(*questionmarkButton);
	root->_window->draw(*recruitSoldierButton);
	root->_window->draw(*assaultButton);

	float y = 0;
	float x = 0;
	for (auto element : _area) {
		for (auto tile : element) {
			tile->setPosition(x, y);
			root->_window->draw(*tile);
			x = x + 100;
		}
		y = y + 100;
		x = 0;
	}

	root->_window->draw(*_actionPointsText);
	root->_window->draw(*_goldText);
	
	root->_window->display();
}

