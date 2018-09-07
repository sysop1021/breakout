#include "GameWindow.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800
#define WINDOW_BITS 32

#define X_SPEED 3.0
#define Y_SPEED 3.0
#define RADIUS 50.0f

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
    shape.setRadius(RADIUS);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOrigin(RADIUS, RADIUS);
    shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    speed.x = X_SPEED;
    speed.y = Y_SPEED;
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
        shape.move(speed);

        if (shape.getPosition().x + RADIUS >= WINDOW_WIDTH || shape.getPosition().x - RADIUS <= 0) // hor col
        {
            speed.x *= -1;
        }

        if (shape.getPosition().y + RADIUS >= WINDOW_HEIGHT || shape.getPosition().y - RADIUS <= 0) // vert col
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
    window.draw(shape);
}

void GameWindow::BeginDraw()
{
    window.clear(sf::Color::White);
}

void GameWindow::EndDraw()
{
    window.display();
}
