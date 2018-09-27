#include "BrickObj.hpp"

BrickObj::BrickObj()
{
    sf::Vector2f brickSize;
    brickSize.x = (WINDOW_WIDTH / COLS);
    brickSize.y = (20.f);

    BrickRect.setSize(brickSize);
    BrickRect.setFillColor(sf::Color::Red);
    BrickRect.setOutlineColor(sf::Color::White);
    BrickRect.setOutlineThickness(3.f);
    BrickRect.setPosition(0, 0);
    isVisible = false;
}

BrickObj::BrickObj(sf::Vector2f brickPos)
{
    sf::Vector2f brickSize;
    brickSize.x = (WINDOW_WIDTH / COLS);
    brickSize.y = (20.f);

    BrickRect.setSize(brickSize);
    BrickRect.setFillColor(sf::Color::Red);
    BrickRect.setOutlineColor(sf::Color::White);
    BrickRect.setOutlineThickness(3.f);
    BrickRect.setPosition(brickPos);
    isVisible = true;
}

BrickObj::~BrickObj()
{

}

bool BrickObj::checkVisibility()
{
    return isVisible;
}

void BrickObj::setVisibility()
{
    isVisible = !isVisible;
}
