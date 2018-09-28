#ifndef BRICK_OBJ
#define BRICK_OBJ

#include <SFML/Graphics.hpp>
#include "Globals.hpp"

class BrickObj
{
    public:
        BrickObj(); //default ctor
        ~BrickObj(); // dtor

        bool checkVisibility();
        void setVisibility(bool vis);

        void setPos(sf::Vector2f brickPos);
        sf::RectangleShape getBrickRect();
        sf::FloatRect getBrickGB();

    private:
        sf::RectangleShape BrickRect;
        bool isVisible;
};

#endif
