#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "Game.hpp"
#include "Hero.h"
#include "Bullet.h"


extern sf::Sprite Spr1;
extern sf::RenderWindow window;
extern sf::Texture Tex1;
extern sf::Sprite Sprzd;
extern sf::Texture Texzd;
extern TileMap map;
ek::Bullet Bul1;
sf::Clock clock1;
int main() {

	InitGame();
	ek::Hero First(sf::Vector2u(0,1),100);
	sf::Vector2u Position(0,1),Position2(-1, -1);
	Spr1.setPosition(Position.x*32 , Position.y * 32);
	window.display();
	
	while (1)
	{
		if (clock1.getElapsedTime().asMilliseconds() > 50) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				Position = First.get(ek::S);
				Position.x++;
				Position.y++;
				Spr1.setRotation(ek::S * 90);
				//std::cout << Position.x <<"^" <<Position.y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				Position = First.get(ek::W);
				Spr1.setRotation(ek::W * 90);
				//std::cout << Position.x << "^" << Position.y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				Position = First.get(ek::D);
				Position.x++;
				Spr1.setRotation(ek::D * 90);
				//std::cout << Position.x << "^" << Position.y << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				Position = First.get(ek::A);
				Position.y++;
				Spr1.setRotation(ek::A * 90);
				//std::cout << Position.x << "^" << Position.y << std::endl;
			}
			clock1.restart();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
				//Bul1.Set(First.GetDirection(), First.get(ek::J));
				Bul1.Set(First.GetDirection(), First.GetPosition());
				//std::cout << Position.x << "^" << Position.y << std::endl;
			}
			Spr1.setPosition(Position.x * 32, Position.y * 32+32);
			Position2 = Bul1.Move();
			std::cout << Position2.x << "^" << Position2.y <<"*"<<Bul1.GetDirection()<< std::endl;
			Sprzd.setPosition(Position2.x * 32 + 16, Position2.y * 32 + 48);
			if (Bul1.GetPosition() == First.GetPosition())
			{
				First.BeHit(1);
				Bul1.Delete();
				std::cout << First.GetHP() << "^^";
				//std::cout << Bul1.GetPosition().x<<"&&&"<< Bul1.GetPosition().y << "^^";
				//std::cout << First.GetPosition().x << "&&&" << First.GetPosition().y << "^^";
			}
			window.clear();
			window.draw(map);
			window.draw(Spr1);
			window.draw(Sprzd);
			window.display();
			//std::cout << Position.x << "*" << Position.y << std::endl;

		}
	}
	return 0;
}