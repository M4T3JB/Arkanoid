#pragma once
#include <SFML/Graphics.hpp>


class Palica
{
public:
    sf::Sprite s;
    float x, y;

    Palica(sf::Texture& t)
    {
        s.setTexture(t);
        x = 300, y = 440;
        s.setPosition(x, y);
    }

    void kretanje(float px)
    {
        x += px;
        s.setPosition(x, y);
    }
};