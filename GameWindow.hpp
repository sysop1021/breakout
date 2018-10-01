#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "Globals.hpp"
#include "BrickObj.hpp"

class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        void InitBall();
        void InitBricks();
        void InitPaddle();
        void InitScoreboard();

        void GameLoop();
        void RunWindow();

        void RenderScene();
        void BeginDraw();
        void Draw();
        void EndDraw();

    private:
        sf::RenderWindow window;
        sf::CircleShape ball;

        sf::Font font;
        sf::Text score;

        BrickObj bricks[ROWS][COLS];

        sf::RectangleShape paddle;

        sf::Event event;
        sf::Vector2f speed;

        int paddlePosX = WINDOW_WIDTH / 2;
        int numLives = MAX_LIVES;
        int numBricks = COLS * ROWS;
        bool gameOverBad;
        bool gameOverGood;
};

#endif
