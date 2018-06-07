#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Need.h"
#include "Map.h"
#include "Hero.h"
namespace ek
{
	class Bullet
	{
	public:
		Bullet() 
		{
			Direction = -1;
			Position = sf::Vector2u(-1, -1);
		}
		void Set(int _direction, sf::Vector2u _position)
		{
			if (Direction == -1) {
				Direction = _direction;
				Position = _position;
				MoveSize = Map().GetSize();
			}
		}
		//~Bullet();
		sf::Vector2u Move()
		{
			if (Direction == W) {
				if (Position.y > 0)
					Position.y--;
				else 
				{
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}
				if (level[Position.y * 20 + Position.x]) {
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}
			}
			if (Direction == S) {
				if (Position.y < MoveSize.y-1)
					Position.y++;
				else 
				{
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}	
				if (level[Position.y * 20 + Position.x]) {
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}
			}
			if (Direction == D) {
				if (Position.x < MoveSize.x-1)
					Position.x++;
				else 
				{
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}		
				if (level[Position.y * 20 + Position.x]) {
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}
			}
			if (Direction == A) {
				if (Position.x > 0)
					Position.x--;
				else 
				{
					Position = sf::Vector2u(-1, -1);
					Direction = -1;

				}	
				if (level[Position.y * 20 + Position.x]) {
					Position = sf::Vector2u(-1, -1);
					Direction = -1;
				}
			}
			return Position;
			
		}
		sf::Vector2u GetPosition() 
		{
			return Position;
		}
		int GetDirection() 
		{
			return Direction;
		}
		void Delete()
		{
			Position = sf::Vector2u(-1, -1);
		}
	private:
		int Direction;
		sf::Vector2u Position;
		sf::Vector2u MoveSize;
	};
}

