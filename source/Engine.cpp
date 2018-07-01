#include "stdafx.h"

Root::Root() {
	std::cout << "initialzing.." << std::endl;
	auto window = std::make_unique<Window>();
	_window = std::move(window);
}




Window::Window() {
	create(sf::VideoMode(_screenWidth, _screenHeight), "Assault", sf::Style::Titlebar | sf::Style::Close);
	setFramerateLimit(_fps);
	
	std::cout << "window created" << std::endl;
}

Text::Text(std::string string, float x, float y) {
	_font = std::make_unique<sf::Font>();
	_color = std::make_unique<sf::Color>();
	_font->loadFromFile("fonts/gothice_.ttf");
	setFont(*_font);
	setCharacterSize(30);
	setStyle(sf::Text::Bold);
	this->setPosition(x, y);
	this->setString(string);
}

Text::~Text() {
	_font.reset();
	_color.reset();
}

GameManager::GameManager() {
	//for initialize in Root
}

GameManager::GameManager(std::unique_ptr<Root> &root) {
	_root = std::move(root);
	_board = std::make_unique<Board>(_root);
	
	std::cout << "game-manager activated" << std::endl;
	std::cout << "start of game" << std::endl;

	while (_root->_window->isOpen())
	{
		this->waitForEvent();
	}
}

GameManager::~GameManager() {
	_root.reset();
	_board.reset();
}


void GameManager::waitForEvent() {
	int i = -1;
	int j = -1;
	int e = 1;
	
	while (_root->_window->pollEvent(_root->_event)) {
		e = 1;
	
		if (_root->_event.type == sf::Event::Closed) {
			_root->_window->close();
		}
		//________________________CLICK ON HOURGLASS
		if (_board->hourglassButton->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_event.mouseButton.button == _root->_mouse.Left) {
			if (_root->_event.type == _root->_event.MouseButtonReleased) this->changeTurn();
		}
		//________________________CLICK ON QUESTIONMARK
		if (_board->questionmarkButton->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_event.mouseButton.button == _root->_mouse.Left) {
			if (_root->_event.type == _root->_event.MouseButtonReleased && _root->_event.MouseLeft) {
				std::cout << std::endl << "OBJECTIVES: Make an assault on enemy castle. To do that, move your infantry to tiles on the WEST and EAST side of enemy's castle and press assault button (two crossed swords). Beware ! To press assault button, you need 3 action points." << std::endl << std::endl;
				std::cout << std::endl << "GAME-MECHANICS: This is turn-based game. To end turn press hour-glass button. Every time you end turn, you earn 1 gold coin and all of your action points reset to 3. To recruit infantry press recruit-infantry button. It costs 2 gold coins and 1 action point. You may move every infantry-unit as far as many action points you have, but only horizontal and vertival (straight line). Every move reduces your action points." << std::endl << std::endl;
				std::cout << std::endl << "TIP OF DAY: Press left-mouse-button on infantry to MARK them. If they are marked already, press right-mouse-button to UNMARK them." << std::endl << std::endl;

			}
		}

		//________________________CLICK ON RECRUIT BUTTON
		if (_board->recruitSoldierButton->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_event.mouseButton.button == _root->_mouse.Left) {
			if (_root->_event.type == _root->_event.MouseButtonReleased) {
				if (_root->_turnOfPlayer == 1) {
					_root->playerRed->recruitSoldier(_board);
					_board->actualize(_root);
				}
				else if (_root->_turnOfPlayer == 2) {
					_root->playerBlue->recruitSoldier(_board);
					_board->actualize(_root);
				}
			}
		}
		//________________________CLICK ON ASSAULT BUTTON
		if (_board->assaultButton->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_event.mouseButton.button == _root->_mouse.Left) {
			if (_root->_event.type == _root->_event.MouseButtonReleased) {
				if (_root->_turnOfPlayer == 1) {
					if (_root->playerRed->getActionPoints() == 3) {
						if (typeid(*_board->_area[3][5]) != typeid(WarriorRed) || typeid(*_board->_area[3][7]) != typeid(WarriorRed)) {
							std::cout << "red-player some units are too far to prepare an assault" << std::endl;
						}
						else if (typeid(*_board->_area[3][5]) == typeid(WarriorRed) && typeid(*_board->_area[3][7]) == typeid(WarriorRed)) {
							_root->_window->close();
							std::cout << std::endl << "red-player win" << std::endl << std::endl;
						}
					}
					else
						std::cout << "red-player don't have enough action-points to make assault" << std::endl;
				}
				if (_root->_turnOfPlayer == 2) {
					if (_root->playerBlue->getActionPoints() == 3) {
						if (typeid(*_board->_area[1][0]) != typeid(WarriorBlue) || typeid(*_board->_area[1][2]) != typeid(WarriorBlue)) {
							std::cout << "blue-player some units are too far to prepare an assault" << std::endl;
						}
						else if (typeid(*_board->_area[1][0]) == typeid(WarriorBlue) && typeid(*_board->_area[1][2]) == typeid(WarriorBlue)) {
							_root->_window->close();
							std::cout << std::endl << "blue-player win" << std::endl << std::endl;
						}
					}
					else
						std::cout << "blue-player don't have enough action-points to make assault" << std::endl;
				}
			}
		}
		//__________________________________CLICK ON UNIT RED
	
		if (_root->_turnOfPlayer == 1) {
			for (auto element : _board->_area) {
				i += 1;
				for (auto unit : element) {
					j += 1;
					if (typeid(*unit) == typeid(WarriorRed)) {
						if (_root->playerRed->getActionPoints() > 0) {
							if (unit->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_event.mouseButton.button == _root->_mouse.Left) {
								if (_root->_event.type == _root->_event.MouseButtonReleased) {
									_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 178));
									if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 128));
									if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 128));
									if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 128));
									if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 128));
									_board->actualize(_root);
									
											while (_root->_window->isOpen()) {

												while (_root->_window->pollEvent(_root->_event2)) {
													
											if (i < 4) {
												if (_board->_area[i + 1][j]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true/* _root->_event.mouseButton.button == _root->_mouse.Left*/) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {
														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i + 1][j]) == typeid(WarriorRed) || typeid(*_board->_area[i + 1][j]) == typeid(CastleRedTile) || typeid(*_board->_area[i + 1][j]) == typeid(CastleBlueTile)) std::cout << "red-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i + 1][j]) == typeid(WarriorBlue)) {

															_board->_area[i + 1][j].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;
														}
														else if (typeid(*_board->_area[i + 1][j]) != typeid(WarriorRed) || typeid(*_board->_area[i + 1][j]) != typeid(CastleRedTile) || typeid(*_board->_area[i + 1][j]) != typeid(CastleBlueTile)) {
															_board->_area[i + 1][j].swap(_board->_area[i][j]);
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;

														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}
											if (i > 0) {
												if (_board->_area[i - 1][j]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {

														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i - 1][j]) == typeid(WarriorRed) || typeid(*_board->_area[i - 1][j]) == typeid(CastleRedTile) || typeid(*_board->_area[i - 1][j]) == typeid(CastleBlueTile)) std::cout << "red-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i - 1][j]) == typeid(WarriorBlue)) {

															_board->_area[i - 1][j].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;
														}
														else if (typeid(*_board->_area[i - 1][j]) != typeid(WarriorRed) || typeid(*_board->_area[i - 1][j]) != typeid(CastleRedTile) || typeid(*_board->_area[i - 1][j]) != typeid(CastleBlueTile)) {
															_board->_area[i - 1][j].swap(_board->_area[i][j]);
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;
														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}

											if (j < 7) {
												if (_board->_area[i][j + 1]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {

														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i][j + 1]) == typeid(WarriorRed) || typeid(*_board->_area[i][j + 1]) == typeid(CastleRedTile) || typeid(*_board->_area[i][j + 1]) == typeid(CastleBlueTile)) std::cout << "red-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i][j + 1]) == typeid(WarriorBlue)) {

															_board->_area[i][j + 1].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;
														}
														else if (typeid(*_board->_area[i][j + 1]) != typeid(WarriorRed) || typeid(*_board->_area[i][j + 1]) != typeid(CastleRedTile) || typeid(*_board->_area[i][j + 1]) != typeid(CastleBlueTile)) {
															_board->_area[i][j + 1].swap(_board->_area[i][j]);
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;
														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}

											if (j > 0) {
												if (_board->_area[i][j - 1]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {

														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j >= 1) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i][j - 1]) == typeid(WarriorRed) || typeid(*_board->_area[i][j - 1]) == typeid(CastleRedTile) || typeid(*_board->_area[i][j - 1]) == typeid(CastleBlueTile)) std::cout << "red-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i][j - 1]) == typeid(WarriorBlue)) {

															_board->_area[i][j - 1].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;

														}
														else if (typeid(*_board->_area[i][j - 1]) != typeid(WarriorRed) || typeid(*_board->_area[i][j - 1]) != typeid(CastleRedTile) || typeid(*_board->_area[i][j - 1]) != typeid(CastleBlueTile)) {
															_board->_area[i][j - 1].swap(_board->_area[i][j]);
															_root->playerRed->setActionPoints(_root->playerRed->getActionPoints() - 1);
															e = 0;
														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}

											if (_root->_mouse.isButtonPressed(_root->_mouse.Right) == true) {
												if (_root->_event.type == _root->_event.MouseButtonReleased) {
													_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
													if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
													if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
													if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
													if (j >= 1) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
													_board->actualize(_root);
													e = 0;
													break;
												}

											}
											

										}
										
										if (e == 0) break;
									}				//while 
								
								

								}
								
							}
						}


					}
				}
				j = -1;
			}
			i = -1;
			j = -1;
		}



		//_____________________________________________CLICK ON UNIT BLUE

		if (_root->_turnOfPlayer == 2) {
			for (auto element : _board->_area) {
				i += 1;
				for (auto unit : element) {
					j += 1;
					if (typeid(*unit) == typeid(WarriorBlue)) {
						if (_root->playerBlue->getActionPoints() > 0) {
							if (unit->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_event.mouseButton.button == _root->_mouse.Left) {
								if (_root->_event.type == _root->_event.MouseButtonReleased) {
									_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 178));
									if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 128));
									if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 128));
									if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 128));
									if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 128));
									_board->actualize(_root);

									while (_root->_window->isOpen()) {

										while (_root->_window->pollEvent(_root->_event2)) {

											if (i < 4) {
												if (_board->_area[i + 1][j]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true/* _root->_event.mouseButton.button == _root->_mouse.Left*/) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {
														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i + 1][j]) == typeid(WarriorBlue) || typeid(*_board->_area[i + 1][j]) == typeid(CastleRedTile) || typeid(*_board->_area[i + 1][j]) == typeid(CastleBlueTile)) std::cout << "blue-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i + 1][j]) == typeid(WarriorRed)) {

															_board->_area[i + 1][j].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;
														}
														else if (typeid(*_board->_area[i + 1][j]) != typeid(WarriorBlue) || typeid(*_board->_area[i + 1][j]) != typeid(CastleRedTile) || typeid(*_board->_area[i + 1][j]) != typeid(CastleBlueTile)) {
															_board->_area[i + 1][j].swap(_board->_area[i][j]);
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;

														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}
											if (i > 0) {
												if (_board->_area[i - 1][j]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {

														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i - 1][j]) == typeid(WarriorBlue) || typeid(*_board->_area[i - 1][j]) == typeid(CastleRedTile) || typeid(*_board->_area[i - 1][j]) == typeid(CastleBlueTile)) std::cout << "blue-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i - 1][j]) == typeid(WarriorRed)) {

															_board->_area[i - 1][j].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;
														}
														else if (typeid(*_board->_area[i - 1][j]) != typeid(WarriorBlue) || typeid(*_board->_area[i - 1][j]) != typeid(CastleRedTile) || typeid(*_board->_area[i - 1][j]) != typeid(CastleBlueTile)) {
															_board->_area[i - 1][j].swap(_board->_area[i][j]);
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;
														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}

											if (j < 7) {
												if (_board->_area[i][j + 1]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {

														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j > 0) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i][j + 1]) == typeid(WarriorBlue) || typeid(*_board->_area[i][j + 1]) == typeid(CastleRedTile) || typeid(*_board->_area[i][j + 1]) == typeid(CastleBlueTile)) std::cout << "blue-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i][j + 1]) == typeid(WarriorRed)) {

															_board->_area[i][j + 1].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;
														}
														else if (typeid(*_board->_area[i][j + 1]) != typeid(WarriorBlue) || typeid(*_board->_area[i][j + 1]) != typeid(CastleRedTile) || typeid(*_board->_area[i][j + 1]) != typeid(CastleBlueTile)) {
															_board->_area[i][j + 1].swap(_board->_area[i][j]);
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;
														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}

											if (j > 0) {
												if (_board->_area[i][j - 1]->getGlobalBounds().contains(_root->_window->mapPixelToCoords(_root->_mouse.getPosition(*_root->_window))) && _root->_mouse.isButtonPressed(_root->_mouse.Left) == true) {
													if (_root->_event.type == _root->_event.MouseButtonReleased) {

														_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
														if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
														if (j >= 1) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
														if (typeid(*_board->_area[i][j - 1]) == typeid(WarriorBlue) || typeid(*_board->_area[i][j - 1]) == typeid(CastleRedTile) || typeid(*_board->_area[i][j - 1]) == typeid(CastleBlueTile)) std::cout << "blue-player cannot move unit there cause place is occupied already" << std::endl;
														else if (typeid(*_board->_area[i][j - 1]) == typeid(WarriorRed)) {

															_board->_area[i][j - 1].swap(_board->_area[i][j]);
															_board->_area[i][j] = std::move(std::make_shared<GrassTile>());
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;

														}
														else if (typeid(*_board->_area[i][j - 1]) != typeid(WarriorBlue) || typeid(*_board->_area[i][j - 1]) != typeid(CastleRedTile) || typeid(*_board->_area[i][j - 1]) != typeid(CastleBlueTile)) {
															_board->_area[i][j - 1].swap(_board->_area[i][j]);
															_root->playerBlue->setActionPoints(_root->playerBlue->getActionPoints() - 1);
															e = 0;
														}
														_board->actualize(_root);
														e = 0;
														break;
													}
												}
											}

											if (_root->_mouse.isButtonPressed(_root->_mouse.Right) == true) {
												if (_root->_event.type == _root->_event.MouseButtonReleased) {
													_board->_area[i][j]->setColor(sf::Color(255, 255, 255, 255));
													if (i < 4) _board->_area[i + 1][j]->setColor(sf::Color(255, 255, 255, 255));
													if (i > 0) _board->_area[i - 1][j]->setColor(sf::Color(255, 255, 255, 255));
													if (j < 7) _board->_area[i][j + 1]->setColor(sf::Color(255, 255, 255, 255));
													if (j >= 1) _board->_area[i][j - 1]->setColor(sf::Color(255, 255, 255, 255));
													_board->actualize(_root);
													e = 0;
													break;
												}

											}


										}

										if (e == 0) break;
									}				//while 



								}

							}
						}


					}
				}
				j = -1;
			}
			i = -1;
			j = -1;
		}

		//___________________________________________________________


	}
}

int GameManager::getTurn() {
	return _root->_turnOfPlayer;
}

void GameManager::setTurn(int turn) {
	_root->_turnOfPlayer = turn;
}

void GameManager::changeTurn() {
	if (_root->_turnOfPlayer == 1) {
		setTurn(2);
		_root->playerBlue->setActionPoints(3);
		_root->playerBlue->setGold(_root->playerBlue->getGold() + 1);

		_board->actualize(_root);

		std::cout << "turn changed from 1 to 2" << std::endl;
	}
	else if (_root->_turnOfPlayer == 2) {
		setTurn(1);
		_root->playerRed->setActionPoints(3);
		_root->playerRed->setGold(_root->playerRed->getGold() + 1);

		_board->actualize(_root);

		std::cout << "turn changed from 2 to 1" << std::endl;
	}
}



