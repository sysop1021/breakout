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
    this->InitStuff();
    this->GameLoop();
}

void GameWindow::InitStuff()
{
    ball.setRadius(RADIUS);
    ball.setFillColor(sf::Color::Cyan);
    ball.setOrigin(RADIUS, RADIUS);
    ball.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    speed.x = X_SPEED;
    speed.y = Y_SPEED;

    brickSize.x = (WINDOW_WIDTH / COLS);
    brickSize.y = (20.f);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            bricks[i][j].setSize(brickSize);
            bricks[i][j].setFillColor(sf::Color::Red);
            bricks[i][j].setOutlineColor(sf::Color::White);
            bricks[i][j].setOutlineThickness(3.0f);
            bricks[i][j].setPosition(j * brickSize.x, i * brickSize.y); // TODO: hot mess
        }
    }
}

void GameWindow::GameLoop()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        this->RenderScene();
        ball.move(speed);

        if (ball.getPosition().x + RADIUS >= WINDOW_WIDTH || ball.getPosition().x - RADIUS <= 0) // hor col
        {
            speed.x *= -1;
        }

        if (ball.getPosition().y + RADIUS >= WINDOW_HEIGHT || ball.getPosition().y - RADIUS <= 0) // vert col
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
