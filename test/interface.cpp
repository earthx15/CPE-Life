#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdio.h>

int main()
{

	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML tutorial", sf::Style::Close | sf::Style::Resize);
	window.setFramerateLimit(60);

	sf::Font font_test_01;
	if (!font_test_01.loadFromFile("font/BebasNeue-Regular.ttf"))
		printf("fail");

	sf::Text Text01("Test01", font_test_01, 80);
	Text01.setFillColor(sf::Color::White);
	Text01.setStyle(1);
	Text01.setOutlineColor(sf::Color::Blue);
	Text01.setOutlineThickness(2);

	sf::Text Text02("Test02", font_test_01, 80);
	Text02.setFillColor(sf::Color::White);
	Text02.setStyle(1);
	Text02.setOutlineColor(sf::Color::Blue);
	Text02.setOutlineThickness(2);

	sf::Text Text03("Test03", font_test_01, 80);
	Text03.setFillColor(sf::Color::White);
	Text03.setStyle(1);
	Text03.setOutlineColor(sf::Color::Blue);
	Text03.setOutlineThickness(2);

	sf::Text Text04("x", font_test_01, 40);
	Text04.setFillColor(sf::Color::White);
	Text04.setStyle(1);
	Text04.setOutlineColor(sf::Color::Blue);
	Text04.setOutlineThickness(2);

	sf::Text Text05("y", font_test_01, 40);
	Text05.setFillColor(sf::Color::White);
	Text05.setStyle(1);
	Text05.setOutlineColor(sf::Color::Blue);
	Text05.setOutlineThickness(2);



	Text01.setPosition(100, 160);
	Text02.setPosition(100, 220 + 60);
	Text03.setPosition(100, 280 + 120);
	Text04.setPosition(0, 0);
	Text05.setPosition(0, 33);




	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();

			}

		}

		if (Text01.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			Text01.setFillColor(sf::Color::Blue);
			Text01.setStyle(4);
			Text01.setString("Text I");
			Text01.setOutlineColor(sf::Color::White);
		}

		else if (Text02.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			Text02.setFillColor(sf::Color::Blue);
			Text02.setStyle(4);
			Text02.setString("Text II");
			Text02.setOutlineColor(sf::Color::White);
		}

		else if (Text03.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			Text03.setFillColor(sf::Color::Blue);
			Text03.setStyle(4);
			Text03.setString("Text III");
			Text03.setOutlineColor(sf::Color::White);
		}
		else
		{
			Text01.setFillColor(sf::Color::White);
			Text01.setStyle(1);
			Text01.setString("Text01");
			Text01.setOutlineColor(sf::Color::Blue);
			Text02.setFillColor(sf::Color::White);
			Text02.setStyle(1);
			Text02.setString("Text02");
			Text02.setOutlineColor(sf::Color::Blue);
			Text03.setFillColor(sf::Color::White);
			Text03.setStyle(1);
			Text03.setString("Text03");
			Text03.setOutlineColor(sf::Color::Blue);

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (Text01.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				printf("Event 1\n");
			}
			else if (Text02.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				printf("Event 2\n");
			}
			else if (Text03.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				printf("Event 3\n");
			}
		}




		int n1 = sf::Mouse::getPosition(window).x;
		Text04.setString("Mouse.X = " + std::to_string(n1));

		int n2 = sf::Mouse::getPosition(window).y;
		Text05.setString("Mouse.y = " + std::to_string(n2));


		window.clear();
		window.draw(Text01);
		window.draw(Text02);
		window.draw(Text03);
		window.draw(Text04);
		window.draw(Text05);
		window.display();

	}
	//testtesttest


	return 0;
}