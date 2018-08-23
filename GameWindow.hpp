#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>

class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        void InitStuff();
        void GameLoop();
        void RunWindow();

        void RenderScene();
        void BeginDraw();
        void Draw();
        void EndDraw();

    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

        sf::Event event;
};

#endif
