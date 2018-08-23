#include "GameWindow.hpp"

GameWindow::GameWindow()
{
    window.create({600, 800, 32}, "SUPER Breakout!", sf::Style::Default);
}

GameWindow::~GameWindow()
{

}

GameWindow::RunWindow()
{
    this->InitStuff();
    this->GameLoop();
}

GameWindow::InitStuff()
{
    shape.setRadius(100.f);
    shape.setFillColor(sf::Color::Cyan);
}

GameWindow::GameLoop()
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

GameWindow::RenderScene()
{
    this->BeginDraw();
    this->Draw();
    this->EndDraw();
}

GameWindow::Draw()
{
    window.draw(shape);
}

GameWindow::BeginDraw()
{
    window.clear(sf::Color::White);
}

GameWindow::EndDraw()
{
    window.display();
}
