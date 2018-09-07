#include "GameWindow.hpp"

GameWindow::GameWindow()
{
    window.create({600, 800, 32}, "SUPER Breakout!", sf::Style::Default);
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
    shape.setRadius(50.f);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOrigin(50.f, 50.f);
    shape.setPosition(300, 600);

    speed.x = 3.0;
    speed.y = 3.0;
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

        if (shape.getPosition().x + 50.f >= 600 || shape.getPosition().x - 50.f <= 0) // hor col
        {
            speed.x *= -1;
        }

        if (shape.getPosition().y + 50.f >= 800 || shape.getPosition().y - 50.f <= 0) // vert col
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
