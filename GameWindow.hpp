class GameWindow
{
    public:
        GameWindow();
        ~GameWindow();

        GameLoop();

    private:
        sf::RenderWindow window;
        sf::CircleShape shape;

        sf::Event event;
};
