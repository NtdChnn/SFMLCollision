#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <sstream> //score
using namespace sf;
using namespace std;
int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(1000, 700), "SFMLCollosion", Style::Close );

	RectangleShape player(Vector2f(20.0f, 20.0f));
	player.setFillColor(Color::Magenta);

	RectangleShape opject(Vector2f(10.0f, 10.0f));
	opject.setFillColor(Color::Red);

	player.setPosition(Vector2f(100.0f, 350.0f));
	opject.setPosition(Vector2f(150.0f, 350.0f));

	//Score
	int currentScore = 0;

	sf::Font myFont;
	if (!myFont.loadFromFile("JSChanokNormal.ttf")) {}

	sf::Text score;
	score.setFont(myFont);
	score.setFillColor(sf::Color::Green);
	score.setStyle(sf::Text::Regular);
	score.setString("Score");
	score.setCharacterSize(30);
	score.setPosition(800, 100);

	sf::Text scoreCurrent;
	scoreCurrent.setFont(myFont);
	scoreCurrent.setFillColor(sf::Color::Magenta);
	scoreCurrent.setStyle(sf::Text::Regular);
	scoreCurrent.setCharacterSize(30);
	scoreCurrent.setPosition(870, 100);


	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
		{
			player.move(0.0f, -0.07f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A))
		{
			player.move(-0.07f, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S))
		{
			player.move(0.0f, 0.07f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D))
		{
			player.move(0.07f, 0.0f);
		}

		int xOp = rand() % 500;
		int yOp = rand() % 500;

		if (opject.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			opject.setPosition(Vector2f(xOp, yOp));
			currentScore += 5;
		}

		stringstream scoreShow;
		scoreShow << currentScore;
		scoreCurrent.setString(scoreShow.str().c_str());

		window.clear();
		window.draw(score);
		window.draw(scoreCurrent);
		window.draw(player);
		window.draw(opject);
		window.display();

		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			}

		}
	}
	return 0;
}