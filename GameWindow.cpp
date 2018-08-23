#include "GameWindow.hpp"

GameWindow::GameWindow()
{
    window.create({600, 800, 32}, "SFML Works!", sf::Style::Default);
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

        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }
}
