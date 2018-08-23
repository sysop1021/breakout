#pragma once
#include <SFML/Graphics.hpp>

class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        InitStuff();
        GameLoop();
        RunWindow();

    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

        sf::Event event;
};
