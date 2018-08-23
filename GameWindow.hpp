#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>

class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        InitStuff();
        GameLoop();
        RunWindow();

        RenderScene();
        BeginDraw();
        Draw();
        EndDraw();

    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

        sf::Event event;
};

#endif
