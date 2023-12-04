// From main.cpp : Menu.h, string, SFML/Graphics.hpp
#include "../Header_Files/Game.h"
// #include "../Header_Files/Menu.h"

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
    // this->enemy.setPosition();
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
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