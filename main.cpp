#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(600,600), "Existence is dormant");
	float x = 150;
	float y = 150;
	float xa = 0;
	float ya = 0;
	float s = 0.5;
	bool xb = false;
	bool yb = false;
	float eps = 0.00001;
	float speed = 10000;
	while(window.isOpen())
	{
		sf::Time dt = clock.getElapsedTime();
		clock.restart();

		xb = false;
		yb = false;
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::A)
				{
					xa += (-1-xa) * s;
					xb = true;
				}
				if(event.key.code == sf::Keyboard::D)
				{
					xa += ( 1-xa) * s;
					xb = true;
				}
				if(event.key.code == sf::Keyboard::W)
				{
					ya += (-1-ya) * s;
					yb = true;
				}
				if(event.key.code == sf::Keyboard::S)
				{
					ya += ( 1-ya) * s;
					yb = true;
				}
			}
		}
		if(!xb)
		{
			xa *= s;
			if(abs(xa) < eps)
				xa = 0;
		}
		if(!yb)
		{
			yb *= s;
			if(abs(ya) < eps)
				ya = 0;
		}
		x += speed * xa * dt.asSeconds();
		y += speed * ya * dt.asSeconds();

		window.clear(sf::Color::Black);
		sf::RectangleShape rect(sf::Vector2<float>(300,300));
		rect.setPosition(sf::Vector2<float>(x,y));
		window.draw(rect);
		window.display();
	}
}
