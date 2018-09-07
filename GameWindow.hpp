#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800
#define WINDOW_BITS 32

#define X_SPEED 3.0
#define Y_SPEED 3.0
#define RADIUS 50.0f

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
        sf::Vector2f speed;
};

#endif
