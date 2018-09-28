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


void GameWindow::InitBricks()
{
    //  TODO fix this
    sf::Vector2f brickSize;
    brickSize.x = (WINDOW_WIDTH / COLS);
    brickSize.y = (20.f);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sf::Vector2f brickPos((j * brickSize.x), ((i * brickSize.y) + 3.f));
            bricks[i][j].setPos(brickPos);
            bricks[i][j].setVisibility(true);
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

    // TODO rewrite with BrickObj
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            window.draw(bricks[i][j].getBrickRect());
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
