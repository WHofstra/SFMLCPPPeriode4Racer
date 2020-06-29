#include <iostream>
#include "Game.h"

Game::Game(sf::RenderWindow* aWindow)
    : window(aWindow)
{
    //Load Textures, These Files are Located in the 'Assets' Map
    //FindTexture(&mapTerrainTexture, "Assets/Map.png");
    //FindTexture(&spriteMap, "Assets/Sprites.png");
}

Game::~Game()
{

}

void Game::FindTexture(sf::Texture* aTexture, std::string filePath)
{
    if (!(*aTexture).loadFromFile(filePath)) {
        EXIT_FAILURE;
        window->close();
    }
    else {
        //std::cout << "Texture succesfully loaded." << std::endl;
    }
}

void Game::CheckQuitInput(sf::Event* anEvent)
{
    if (anEvent->type == sf::Event::Closed) {
        window->close();
    }

    //Press 'Shift + Escape' to Quit
    if (anEvent->KeyPressed && anEvent->key.shift && anEvent->key.code == sf::Keyboard::Escape) {
        window->close();
    }
}

void Game::Update()
{
    //Update Object Properties
}

void Game::Draw()
{
    //Draw Objects Here
    //window->draw();
}
