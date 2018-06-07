#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Need.h"
namespace ek {
	class Map 
	{
	public:
		Map() 
		{
			MapPosition.x = 20;
			MapPosition.y = 20;
		};
		sf::Vector2u GetSize()
		{
			return MapPosition;
		}
	private:
		sf::Vector2u MapPosition;
	};
	//sf::Vector2u MapPosition(40, 10);
};
