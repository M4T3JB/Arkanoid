#include <SFML/Graphics.hpp>
#include "Lopta.h"
#include "Palica.h"


int main()
{


    sf::RenderWindow apl(sf::VideoMode(520, 450), "Arkanoid-SOSS");
    apl.setFramerateLimit(60);

    sf::Texture blok;
    blok.loadFromFile("slike/blok.png");
    sf::Texture poz;
    poz.loadFromFile("slike/crno.jpg");
    sf::Texture loptica;
    loptica.loadFromFile("slike/lopta.png");
    sf::Texture pal;
    pal.loadFromFile("slike/palica.png");

    sf::Sprite pozadina(poz);

    Lopta Lopta(loptica);
    Palica Palica(pal);

    sf::Sprite blokovi[100];

    int n = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            blokovi[n].setTexture(blok);
            blokovi[n].setPosition(i * 43, j * 20);
            n++;
        }

    while (apl.isOpen())
    {
      
        if (Lopta.y > apl.getSize().y) apl.close();
        if (Lopta.x < 0 || Lopta.x>520)  Lopta.px = -Lopta.px;
        if (Lopta.y < 0 || Lopta.y>450)  Lopta.py = -Lopta.py;

        Lopta.x += Lopta.px;
        Lopta.y += Lopta.py;

        for (int i = 0; i < n; i++)
            if (sf::FloatRect(Lopta.x, Lopta.y, 1, 1).intersects(blokovi[i].getGlobalBounds()))
            {
                blokovi[i].setPosition(-100, 0); 
                Lopta.px = -Lopta.px;
            }

        
        for (int i = 0; i < n; i++)
            if (sf::FloatRect(Lopta.x, Lopta.y, 1, 1).intersects(blokovi[i].getGlobalBounds()))
            {
                blokovi[i].setPosition(-100, 0);
                Lopta.py = -Lopta.py;
            }

        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) Palica.kretanje(5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) Palica.kretanje(-5);
        if (sf::FloatRect(Lopta.x, Lopta.y, 12, 12).intersects(Palica.s.getGlobalBounds())) Lopta.py = -Lopta.py;

        Lopta.update();

        apl.clear();
        apl.draw(pozadina);
        apl.draw(Lopta.s);
        apl.draw(Palica.s);

        for (int i = 0; i < n; i++)
            apl.draw(blokovi[i]);

        apl.display();
    }

    return 0;
}