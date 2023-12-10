// From main.cpp : Menu.h, string, SFML/Graphics.hpp
#include "../Header_Files/Game.h"
#include "../Header_Files/Stronghold.h"

// #include "../Header_Files/Menu.h"


// Next G1 Part 4


// Private Functions
void Game::initVariables()
{
    this->window = nullptr;

}

void Game::initWindow()
{
    this->videoMode.width = 1200;
    this->videoMode.height = 700;
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
    float scale = 1.0f; 
    float BaseWidth = 100.f, BaseHeight = 200.f;
    float GrassBelt = 50.f;

    this->PlayerBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Player", sf::Color::Cyan, &this->videoMode);
    this->EnemyBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Enemy", sf::Color::Red, &this->videoMode);

    // // Enenmy base init
    // this->EnemyBase.setPosition(this->videoMode.width-(BaseWidth*scale), this->videoMode.height - (BaseHeight*scale) - GrassBelt*scale);
    // this->EnemyBase.setSize(sf::Vector2f(BaseWidth, BaseHeight));
    // this->EnemyBase.setScale(sf::Vector2f(scale, scale));
    // this->EnemyBase.setFillColor(sf::Color::Cyan);
    // this->EnemyBase.setOutlineColor(sf::Color::Yellow);
    // this->EnemyBase.setOutlineThickness(1.f);

    // // Player base init
    // this->PlayerBase.setPosition(sf::Vector2f(0.f, this->videoMode.height - (BaseHeight*scale) - GrassBelt*scale));
    // this->PlayerBase.setSize(sf::Vector2f(BaseWidth, BaseHeight));
    // this->PlayerBase.setScale(sf::Vector2f(scale, scale));
    // this->PlayerBase.setFillColor(sf::Color::Red);
    // this->PlayerBase.setOutlineColor(sf::Color::Yellow);
    // this->PlayerBase.setOutlineThickness(1.f);

    
}

// Constructor / Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
    this->initBase();
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

        default: break;
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

    // Printing mouse pos
    // std::cout<<"Mouse pos: "
    // <<sf::Mouse::getPosition(*this->window).x
    // <<" "<<sf::Mouse::getPosition(*this->window).y<<"\n";
    
    

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
    // this->window->draw(this->enemy);
    PlayerBase.render(this->window);
    EnemyBase.render(this->window);

    // this->window->draw(this->EnemyBase);
    // this->window->draw(this->PlayerBase);

    this->window->display();
}