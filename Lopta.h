#pragma once
#include <SFML/Graphics.hpp>

class Lopta
{
public:
    sf::Sprite s;
    float px, py;
    float x, y;

    Lopta(sf::Texture& t)
    {
        s.setTexture(t);
        px = 2, py = 2;
        x = 300, y = 300;
    }

    void update()
    {
        x += px;
        y += py;
        s.setPosition(x, y);
    }
};