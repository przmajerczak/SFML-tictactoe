#include <iostream>
#include <cstdlib>
#include <string>

#include <SFML/Graphics.hpp>

#include "game.h"
#include "SFMLButton.h"


using namespace std;

int WinMain()
{
	char game[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    bool playersOneMove = true;
    char playersMark = '-';
    char computersMark = '-';
    int moves = 0;
    int temp = 0;

	float windowX = 1200;
	float windowY = 675;
	float margines = 30;

	bool computerIsPlayerTwo = true;
	bool playersOneMarkIsX = true;

	sf::Event event;
	int app_state = 0; 
	bool holdCurrentState = true;
	
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Tictactoe", sf::Style::Default);
	windowX = window.getSize().x;
	windowY = window.getSize().y;

	sf::Sprite background;
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Pictures/background.png");
	sf::Vector2u backgroundSize = backgroundTexture.getSize();
	background.setScale(windowX / backgroundSize.x, windowY / backgroundSize.y);
	background.setTexture(backgroundTexture);
	backgroundTexture.setSmooth(true);
	
	SFMLButton* buttonMenu = new SFMLButton(	{ margines, windowY - 6 * margines },
													{ windowX - 2 * margines, 2 * margines },
													"Powrót do menu",
													"Pictures/default_buttonLONG.png");
	SFMLButton* buttonClose = new SFMLButton(	{ margines, windowY - 3 * margines },
												{ windowX - 2 * margines, 2 * margines },
												"Wyjscie",
												"Pictures/default_buttonLONG.png");


	while (window.isOpen())
	{
		switch (app_state)
		{
		case 0:
		{
			int questionNo = 0;

			SFMLButton* buttonLeft = new SFMLButton({ margines, margines },
			{ (windowX - 3 * margines) / 2, windowY - 8 * margines },
				"Gra z komputerem");
			SFMLButton* buttonRight = new SFMLButton({ (windowX + margines) / 2, margines },
			{ (windowX - 3 * margines) / 2, windowY - 8 * margines },
				"Gra z przeciwnikiem");
			while (holdCurrentState)
			{
				window.draw(background);


				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
					{
						window.close();
						return 0;
						break;
					}
					case sf::Event::KeyPressed:
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						{
							window.close();
							break;
						}
					}
					case sf::Event::MouseMoved:
					{
						buttonLeft->mousePosition(sf::Mouse::getPosition(window));
						buttonRight->mousePosition(sf::Mouse::getPosition(window));
						buttonMenu->mousePosition(sf::Mouse::getPosition(window));
						buttonClose->mousePosition(sf::Mouse::getPosition(window));
						break;
					}
					case sf::Event::MouseButtonPressed:
					{
						buttonLeft->mousePressed();
						buttonRight->mousePressed();
						buttonMenu->mousePressed();
						buttonClose->mousePressed();
						break;
					}
					case sf::Event::MouseButtonReleased:
					{
						buttonLeft->mouseReleased();
						buttonRight->mouseReleased();
						buttonMenu->mouseReleased();
						buttonClose->mouseReleased();
						break;
					}
					};
				}

				if (buttonClose->pressed())
				{
					buttonClose->clear();
					window.close();
					return 0;
				}

				if (buttonMenu->pressed())
				{
					buttonLeft->draw(window);
					buttonRight->draw(window);
					buttonMenu->draw(window);
					buttonClose->draw(window);
					window.display();

					app_state = 0;
					break;
				}

				if (buttonRight->pressed() && questionNo == 0)
				{
					buttonRight->clear();
					questionNo++;
					computerIsPlayerTwo = false;
					if (computerIsPlayerTwo)
					{
						buttonLeft->setText("Twoim znakiem O");
						buttonRight->setText("Twoim znakiem X");
					}
					else
					{
						buttonLeft->setText("O zaczyna");
						buttonRight->setText("X zaczyna");
					}
				}
				if (buttonLeft->pressed() && questionNo == 0)
				{
					buttonLeft->clear();
					questionNo++;
					if (computerIsPlayerTwo)
					{
						buttonLeft->setText("Twoim znakiem O");
						buttonRight->setText("Twoim znakiem X");
					}
					else
					{
						buttonLeft->setText("O zaczyna");
						buttonRight->setText("X zaczyna");
					}

				}

				if (buttonRight->pressed() && questionNo == 1)
				{
					buttonRight->clear();
					questionNo++;
					if (!computerIsPlayerTwo)
					{
						holdCurrentState = false;
						app_state = 1;
					}
					else
					{
						buttonLeft->setText("Ty zaczynasz");
						buttonRight->setText("Komputer zaczyna");
					}
					
				}
				if (buttonLeft->pressed() && questionNo == 1)
				{
					buttonLeft->clear();
					playersOneMarkIsX = false;
					questionNo++;
					if (!computerIsPlayerTwo)
					{
						holdCurrentState = false;
						app_state = 1;
					}
					else
					{
						buttonLeft->setText("Ty zaczynasz");
						buttonRight->setText("Komputer zaczyna");
					}
				}
				if (buttonRight->pressed() && questionNo == 2)
				{
					buttonRight->clear();
					playersOneMove = false;
					holdCurrentState = false;
					app_state = 1;
				}
				if (buttonLeft->pressed() && questionNo == 2)
				{
					buttonLeft->clear();
					holdCurrentState = false;
					app_state = 1;
				}

				buttonLeft->draw(window);
				buttonRight->draw(window);
				buttonMenu->draw(window);
				buttonClose->draw(window);
				window.display();
			}

			holdCurrentState = true;
			

			delete buttonLeft;
			delete buttonRight;

			break;
		}
		case 1:
		{
			Tictactoe game(computerIsPlayerTwo, playersOneMarkIsX);

			float board_element_size = 100;
			float board_margines = 20;

			sf::Text resultText;
			sf::Font resultFont;
			resultFont.loadFromFile("Fonts/EncodeSans-Black.ttf");
			resultText.setFont(resultFont);
			resultText.setCharacterSize(board_element_size);
			resultText.setFillColor(sf::Color::Yellow);
			resultText.setStyle(sf::Text::Bold);


			

			SFMLButton* gameboard = new SFMLButton[9];

			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
				{
					gameboard[j + i * 3].resize({ board_element_size, board_element_size });
					gameboard[j + i * 3].move({ float(0.5 * windowX - 1.5 * board_element_size - board_margines) + j * (board_element_size + board_margines), margines + i * (board_element_size + board_margines) });
				}


				while (holdCurrentState)
				{
					window.draw(background);

					while (window.pollEvent(event))
					{
						switch (event.type)
						{
						case sf::Event::Closed:
						{
							window.close();
							return 0;
							break;
						}
						case sf::Event::Resized:
						{
							buttonMenu->windowResized();
							buttonClose->windowResized();

							for (int i = 0; i < 9; ++i)
								(gameboard + i)->windowResized();
							break;
						}
						
						case sf::Event::KeyPressed:
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							{
								window.close();
								break;
							}
						}
						case sf::Event::MouseMoved:
						{
							buttonMenu->mousePosition(sf::Mouse::getPosition(window));
							buttonClose->mousePosition(sf::Mouse::getPosition(window));

							for (int i = 0; i < 9; ++i)
								(gameboard + i)->mousePosition(sf::Mouse::getPosition(window));
							break;
						}
						case sf::Event::MouseButtonPressed:
						{
							buttonMenu->mousePressed();
							buttonClose->mousePressed();

							for (int i = 0; i < 9; ++i)
								(gameboard + i)->mousePressed();
							break;
						}
						case sf::Event::MouseButtonReleased:
						{
							buttonMenu->mouseReleased();
							buttonClose->mouseReleased();

							for (int i = 0; i < 9; ++i)
								(gameboard + i)->mouseReleased();
							break;
						}
						};
					}

					if (buttonClose->pressed())
					{
						buttonClose->clear();
						window.close();
						return 0;
					}

					if (buttonMenu->pressed())
					{
						for (int i = 0; i < 9; ++i)
							(gameboard + i)->draw(window);
						buttonMenu->draw(window);
						buttonClose->draw(window);
						window.display();

						app_state = 0;
						break;
					}

					if (computerIsPlayerTwo && !playersOneMove)
					{
						playersOneMove ^= 1;
						if (playersOneMarkIsX)
							gameboard[game.computerMove('O')].setPicture("Pictures/o_button.png");
						else
							gameboard[game.computerMove('X')].setPicture("Pictures/x_button.png");
					}

					for (int i = 0; i < 9 && !game.result(); ++i)
					{
												
						if ((gameboard + i)->pressed())
						{
							if (game.at(i) == '-')
							{
								(gameboard + i)->clear();
								game.mark(playersOneMove, i);

								if (playersOneMarkIsX)
									if(playersOneMove)
										gameboard[i].setPicture("Pictures/x_button.png");
									else
										gameboard[i].setPicture("Pictures/o_button.png");
								else
									if (playersOneMove)
										gameboard[i].setPicture("Pictures/o_button.png");
									else
										gameboard[i].setPicture("Pictures/x_button.png");

								playersOneMove ^= 1;
							}
						
							

							if (game.result())			
								break;
							
					}
				}

					for (int i = 0; i < 9; ++i)
						(gameboard + i)->draw(window);
					buttonMenu->draw(window);
					buttonClose->draw(window);

					if (game.result())
					{
						for (int i = 0; i < 9; ++i)
						{
							(gameboard + i)->turnOff(1);
						}

						if (game.result() == 3)
							resultText.setString("REMIS");
						else if (game.result() == 1)
						{
							if (computerIsPlayerTwo)
								resultText.setString("WYGRANA");
							else
								resultText.setString("WYGRYWA GRACZ 1");
						}
						else
						{
							if (computerIsPlayerTwo)
								resultText.setString("PRZEGRANA");
							else
								resultText.setString("WYGRYWA GRACZ 2");
						}

						resultText.setPosition({ (windowX - resultText.getLocalBounds().width) / 2 , margines + board_element_size + board_margines });
						window.draw(resultText);
					}
					window.display();
				}

				holdCurrentState = true;
				delete [] gameboard;

				break;
			}
	};
		
	}
	
	delete buttonMenu;
	delete buttonClose;

	return 0;
}