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
