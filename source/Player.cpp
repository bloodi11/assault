#include "stdafx.h"


void IPlayer::setActionPoints(int actionPoints) {
	_actionPoints = actionPoints;
}

void IPlayer::setGold(int gold) {
	_gold = gold;
}

int IPlayer::getActionPoints() {
	return _actionPoints;
}

int IPlayer::getGold() {
	return _gold;
}

//________________________________________________RED

PlayerRed::PlayerRed() {
	setActionPoints(3);
	setGold(5);
}

/*std::shared_ptr<PlayerRed> GameManager::getPlayerRed() {
return playerRed;
}

std::shared_ptr<PlayerBlue> GameManager::getPlayerBlue() {
return playerBlue;
}*/

void PlayerRed::recruitSoldier(std::unique_ptr<Board> &board) {
	if (_gold >= 2 && _actionPoints >= 1) {
		std::unique_ptr<IWarrior> warriorRed = std::make_unique<WarriorRed>();
		if (typeid(*board->_area[2][1]) != typeid(WarriorRed)){
			_gold = _gold - 2;
			_actionPoints = _actionPoints - 1;

			//_units.push_back(warrior);
			board->_area[2][1].reset();
			board->_area[2][1] = std::move(warriorRed);

			std::cout << "player-red recruit an infantry" << std::endl;
		}
		else std::cout << "player-red there are units outside castle already " << std::endl;
	}
	else {
		std::cout << "player-red don't have enough gold or action-points to recruit any unit" << std::endl;
	}
}


//________________________________________________BLUE

PlayerBlue::PlayerBlue() {
	setActionPoints(3);
	setGold(4);
}

void PlayerBlue::recruitSoldier(std::unique_ptr<Board> &board) {
	if (_gold >= 2 && _actionPoints >= 1) {
		std::unique_ptr<IWarrior> warriorBlue = std::make_unique<WarriorBlue>();
		if (typeid(*board->_area[2][6]) != typeid(WarriorBlue)) {
			_gold = _gold - 2;
			_actionPoints = _actionPoints - 1;

			board->_area[2][6].reset();
			board->_area[2][6] = std::move(warriorBlue);

			std::cout << "player-blue recruit an infantry" << std::endl;
		}
		else std::cout << "player-blue there are units outside castle already " << std::endl;
	}
	else {
		std::cout << "player-blue don't have enough gold or action-points to recruit any unit" << std::endl;
	}
}