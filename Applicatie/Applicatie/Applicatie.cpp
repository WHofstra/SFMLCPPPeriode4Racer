#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1364, 664), "SFML C++ Periode 4 Racer");
    Game* console = new Game(&window);

    //Game is Running
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            console->CheckQuitInput(&event);
        }

        window.clear();
        console->Update();
        console->Draw();
        window.display();
    }

    return 0;
}