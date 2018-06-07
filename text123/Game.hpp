#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tmap.h"
#include "Map.h"
sf::RenderWindow window;
sf::Sprite Spr1;
sf::Texture Tex1;
sf::Sprite Sprzd;
sf::Texture Texzd;
TileMap map;
const int level[400] =
{
	1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,
	0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,
	0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
	0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,
	0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,
	0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,
	0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,
	0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,
	0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,
	0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,
	0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,
	1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,
};
int InitGame()
{
	
	window.create(sf::VideoMode(1280, 760), "EasyKing");
	!map.load("sc\\she.png", sf::Vector2u(32, 32), level, ek::Map().GetSize().x, ek::Map().GetSize().y);
	Tex1.loadFromFile("sc\\0zhu1.png");
	Texzd.loadFromFile("sc\\zd.png");
	Sprzd.setTexture(Texzd);
	Spr1.setTexture(Tex1);
	return 0;
}
//int GameDidClose() 
//{
//
//}
//int GameLostFocus() 
//{
//	
//}
//int GameGetFocus()
//{
//	
//}
//int Game() 
//{
//
//}