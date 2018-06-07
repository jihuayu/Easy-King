#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Need.h"
#include "Map.h"
#include "Bullet.h"
//#include "Game.hpp"
extern const int level[];
namespace ek
{
	
	class Hero
	{
	private:
		int HP;
		sf::Vector2u HeroPosition;
		sf::Vector2u MoveSize;
		int Direction;
	public:
		Hero(sf::Vector2u _position, int _HP)
		{
			Direction = 0;
			HeroPosition = _position;
			HP = _HP;
			MoveSize = Map().GetSize();
		}
		sf::Vector2u get(ek::Key _key)
		{
			if (_key == W) {
				if (Direction != _key) {
					Direction = _key;
					return HeroPosition;
				}
				if (HeroPosition.y > 0) {
					HeroPosition.y--;
					if (level[HeroPosition.y * 20 + HeroPosition.x])
						HeroPosition.y++;
				}
				return HeroPosition;
			}
			if (_key == S) {
				if (Direction != _key) {
					Direction = _key;
					return HeroPosition;
				}
				if (HeroPosition.y < MoveSize.y - 1) {
					HeroPosition.y++;
					if (level[HeroPosition.y * 20 + HeroPosition.x])
						HeroPosition.y--;
				}

				return HeroPosition;
			}
			if (_key == D) {
				if (Direction != _key) {
					Direction = _key;
					return HeroPosition;
				}
				if (HeroPosition.x < MoveSize.x - 1) {
					HeroPosition.x++;
					if (level[HeroPosition.y * 20 + HeroPosition.x])
						HeroPosition.x--;
				}

				return HeroPosition;
			}
			if (_key == A) {
				if (Direction != _key) {
					Direction = _key;
					return HeroPosition;
				}
				if (HeroPosition.x > 0) {
					HeroPosition.x--;
					if (level[HeroPosition.y * 20 + HeroPosition.x])
						HeroPosition.x++;
				}
				return HeroPosition;
			}
			return HeroPosition;
			if (_key = J)
			{
				return HeroPosition;
			}
		}
		int GetDirection()
		{
			return Direction;
		}
		int BeHit(int _HP)
		{
			HP -= _HP;
			return HP;
		}
		int GetHP()
		{
			return HP;
		}
		sf::Vector2u GetPosition() {
			return HeroPosition;
		}
	};
};