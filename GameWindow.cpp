#include "GameWindow.hpp"

GameWindow::GameWindow()
{
    window.create({WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS}, "SUPER Breakout!", sf::Style::Default);
}

GameWindow::~GameWindow()
{

}

void GameWindow::RunWindow()
{
    this->InitBall();
    this->InitBricks();
    this->InitPaddle();
    this->GameLoop();
}

void GameWindow::InitBall()
{
    ball.setRadius(RADIUS);
    ball.setFillColor(sf::Color::Cyan);
    ball.setOrigin(RADIUS, RADIUS);
    ball.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    speed.x = X_SPEED;
    speed.y = Y_SPEED;
}

/**
    TODO: This works when ROWS and COLS are the exact same number,
    but does some weird shit when they are different!?
*/

void GameWindow::InitBricks()
{
    sf::Vector2f brickSize;
    brickSize.x = (WINDOW_WIDTH / COLS);
    brickSize.y = (20.f);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            bricks[i][j].setSize(brickSize);
            bricks[i][j].setFillColor(sf::Color::Red);
            //TODO: for debugging purposes. I still have no idea what is going wrong
            /*switch(i)
            {
            case 0:
                bricks[i][j].setFillColor(sf::Color::Red);
                break;

            case 1:
                bricks[i][j].setFillColor(sf::Color::Yellow);
                break;

            case 2:
                bricks[i][j].setFillColor(sf::Color::Green);
                break;

            case 3:
                bricks[i][j].setFillColor(sf::Color::Blue);
                break;

            case 4:
                bricks[i][j].setFillColor(sf::Color::Magenta);
                break;
            }*/

            bricks[i][j].setOutlineColor(sf::Color::White);
            bricks[i][j].setOutlineThickness(3.0f);
            bricks[i][j].setPosition((j * brickSize.x), (i * brickSize.y));
        }
    }
}

void GameWindow::InitPaddle()
{
    sf::Vector2f paddleSize(80.f, 20.f);

    paddle.setSize(paddleSize);
    paddle.setFillColor(sf::Color::Blue);
    paddle.setOrigin(30.f, 10.f);
    paddle.setPosition(paddlePosX, WINDOW_HEIGHT * 0.85);
}

void GameWindow::GameLoop()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                paddlePosX = sf::Mouse::getPosition(window).x;
            }
        }

        this->RenderScene();
        ball.move(speed);
        paddle.setPosition(paddlePosX, WINDOW_HEIGHT * 0.85);

        // wall collision
        if (ball.getPosition().x + RADIUS >= WINDOW_WIDTH || ball.getPosition().x - RADIUS <= 0)
        {
            speed.x *= -1;
        }

        // floor/ceil collision
        if (ball.getPosition().y + RADIUS >= WINDOW_HEIGHT || ball.getPosition().y - RADIUS <= 0)
        {
            speed.y *= -1;
        }

        // paddle collision IFF ball is travelling down (pos y)
        if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()) && speed.y > 0)
        {
            speed.y *= -1;
        }
    }
}

void GameWindow::RenderScene()
{
    this->BeginDraw();
    this->Draw();
    this->EndDraw();
}

void GameWindow::Draw()
{
    window.draw(ball);
    window.draw(paddle);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            window.draw(bricks[i][j]);
        }
    }
}

void GameWindow::BeginDraw()
{
    window.clear(sf::Color::White);
}

void GameWindow::EndDraw()
{
    window.display();
}
