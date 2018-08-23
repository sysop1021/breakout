#pragma once
#include <SFML/Graphics.hpp>

class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        GameLoop();

    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

        sf::Event event;
};
