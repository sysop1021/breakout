#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800
#define WINDOW_BITS 32

#define X_SPEED 3.0
#define Y_SPEED 3.0
#define RADIUS 10.0f

#define COLS 8
#define ROWS 8

#include <SFML/Graphics.hpp>

class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        void InitBall();
        void InitBricks();
        void InitPaddle();

        void GameLoop();
        void RunWindow();

        void RenderScene();
        void BeginDraw();
        void Draw();
        void EndDraw();

    private:
        sf::RenderWindow window;
        sf::CircleShape ball;
        sf::RectangleShape bricks[COLS][ROWS];
        sf::RectangleShape paddle;

        sf::Event event;
        sf::Vector2f speed;

        int paddlePosX = WINDOW_WIDTH / 2;
};

#endif
