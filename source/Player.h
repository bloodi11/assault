#pragma once
#include "stdafx.h"

class Board;

class IPlayer {
protected:
	int _gold;
	int _actionPoints;

public:

	int getGold();
	void setGold(int gold);
	int getActionPoints();
	void setActionPoints(int actionPoints);
	virtual void recruitSoldier(std::unique_ptr<Board> &board) = 0;
};

//_________________________________________________RED

class PlayerRed : public IPlayer {
private:

public:

	PlayerRed();
	void recruitSoldier(std::unique_ptr<Board> &board) override;
};

//_______________________________________________________BLUE

class PlayerBlue : public IPlayer {
private:

public:
	PlayerBlue();
	void recruitSoldier(std::unique_ptr<Board> &board) override;
};
