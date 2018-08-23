#include "GameWindow.hpp"

GameWindow::GameWindow()
{
    window.create({200, 200, 32}, "SFML Works!", sf::Style::Default);

    shape.setRadius(100.f);
    shape.setFillColor(sf::Color::Cyan);
}

GameWindow::~GameWindow()
{

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

        window.clear();
        window.draw(shape);
        window.display();
    }
}
