// From main.cpp : Menu.h, string, SFML/Graphics.hpp
#include "../Header_Files/Game.h"
#include "Game.h"
// #include "../Header_Files/Menu.h"


// Next G1 Part 4


// Private Functions
void Game::initVariables()
{
    this->window = nullptr;

}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    // this->videoMode.getDesktopMode() future possible implementation
    this->window = new sf::RenderWindow(this->videoMode,  "War of Age Game");

    this->window->setFramerateLimit(144);

}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

void Game::initBase()
{
    
}

// Constructor / Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
}


// Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}
 
// Functions
void Game::pollEvents()
{
// sf::Event event;
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {

        // event closing window after Event::Closed triggered
        case sf::Event::Closed:    
            this->window->close(); 
            break;

        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();



        // moge dac do menu.h
        // Start button 's reactions to mouse
        case sf::Event::MouseMoved: 
            break;
        }
    }
}


void Game::update()
{
    this->pollEvents();

    // Update mouse position
    // Relative to screen
    // std::cout<<"Mouse pos: "<<sf::Mouse::getPosition().x<<" "<<sf::Mouse::getPosition().y<<"\n";
    // Relative to the windows
    std::cout<<"Mouse pos: "
    <<sf::Mouse::getPosition(*this->window).x
    <<" "<<sf::Mouse::getPosition(*this->window).y<<"\n";
    

}

void Game::render()
{
    /*
        @return void

        - clear old frame
        - render objects
        - display frame in wondow

        Renders the game objects.
    */

    this->window->clear();

    //Draw game objects
    this->window->draw(this->enemy);

    this->window->display();
}