#ifndef BRICK_OBJ
#define BRICK_OBJ

#include <SFML/Graphics.hpp>

class BrickObj
{
    public:
        BrickObj(); //default ctor - pos = (0,0) and not visible
        BrickObj(sf::Vector2f brickPos);
        ~BrickObj(); // dtor

        bool checkVisibility();
        void setVisibility(bool vis);

    private:
        sf::RectangleShape BrickRect;
        bool isVisible;
};

#endif
