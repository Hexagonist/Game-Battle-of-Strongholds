// From main.cpp : Menu.h, string, SFML/Graphics.hpp
#include "../Header_Files/Game.h"
#include "../Header_Files/Stronghold.h"

// #include "../Header_Files/Menu.h"


// Next G1 Part 4

// Delete enemies G3 Part 8


// Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    this->max_PlayerUnits = 5;
    this->max_EnemyUnits = 5;
    this->spawnTimerMax = 120.f;
    this->spawnTimer = this->spawnTimerMax;
    this->playerSpawnTimerMax = 60.f;
    this->playerSpawnTimer = this->playerSpawnTimerMax;
    this->playerSpawnQueueNum = 0;
    this->playerSpawnQueueNumMax = 2;


}

void Game::initWindow()
{
    this->videoMode.width = 1200;
    this->videoMode.height = 700;
    // this->videoMode.getDesktopMode() future possible implementation
    this->window = new sf::RenderWindow(this->videoMode,  "War of Age Game");

    this->window->setFramerateLimit(60);

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
void Game::spawnEnemyUnits()
{
    // Timer
    if (this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else
    {
        if(this->EnemyUnits.size() < this->max_EnemyUnits)
        {
            BasicUnit U = BasicUnit(1.f, 50.f, 50.f, 50.f, "Unit", sf::Color::Red, 10.f, -5.f);
            U.update(this->videoMode.width - this->EnemyBase.getWidth() - U.get_width(), this->videoMode.height);

            this->EnemyUnits.push_back(U);
            this->spawnTimer = 0.f;
            
            std::cout<<"//////////New unit//////////\n";
            // std::cout<<EnemyUnits[0].get_width()<<"\n";
            // std::cout<<EnemyUnits.size()<<"\n";



        }
    }
}

void Game::spawnPlayerUnit()
{
    if (this->playerSpawnTimer < this->playerSpawnTimerMax)
        this->playerSpawnTimer += 1.f;
    else
    {
        if((this->PlayerUnits.size() < this->max_PlayerUnits) && (this->playerSpawnQueueNum > 0))
            {
                BasicUnit U = BasicUnit(1.f, 50.f, 50.f, 50.f, "Unit", sf::Color::Blue, 10.f, 5.f);
                U.update(this->EnemyBase.getWidth(), this->videoMode.height);

                this->PlayerUnits.push_back(U);
                
                std::cout<<"//////////New Player unit!!!!!!!!!!!!!\n";
                this->playerSpawnQueueNum -= 1;
                this->playerSpawnTimer = 0.f;
            }
    }

}

void Game::spawnSwagBalls()
{
    // Timer
    if (this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else
    {
        if(this->swagBalls.size() < this->max_EnemyUnits)
        {
            this->swagBalls.push_back(SwagBall());
            this->spawnTimer = 0.f;
            // std::cout<<"New ball\n";
            // std::cout<<EnemyUnits.size()<<"\n";


        }
    }
}

void Game::spawnUnit(BasicUnit Unit, float posX, float posY)
{
}




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

        case sf::Event::MouseButtonPressed:
            if((this->ev.mouseButton.button == sf::Mouse::Left) && (this->playerSpawnQueueNum < this->playerSpawnQueueNumMax))  
                this->playerSpawnQueueNum += 1;

        default: break;
        }

    }
}


void Game::update()
{
    this->pollEvents();
    // this->spawnTimer=0.f;
    // this->spawnSwagBalls();

    this->spawnEnemyUnits();
    this->spawnPlayerUnit();

    this->enemyUnitsUpdate();
    this->playerUnitsUpdate();



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
    // this->spawnSwagBalls();


    this->window->clear();

    //Draw game objects
    // this->window->draw(this->enemy);
    
    PlayerBase.render(this->window);
    EnemyBase.render(this->window);

    sf::FloatRect windowBounds(0, 0, this->window->getSize().x, this->window->getSize().y);

    // for(auto i : this->swagBalls)
    // {
    //     i.render(this->window);


    //     sf::FloatRect rectangleBounds = i.getCircle().getGlobalBounds();

    //     if (windowBounds.intersects(rectangleBounds)) {
    //         // std::cout<<"Intersects!!\n";
    //     }


    //     // std::cout<<"rendered\n";
    // }

    //Enemies render
    for(auto i : this->EnemyUnits)
    {
        i.render(this->window);


        sf::FloatRect rectangleBounds = i.getRect().getGlobalBounds();

        if (windowBounds.intersects(rectangleBounds)) {
            // The rectangle is at least partially within the window
            // It's considered to be drawn on the window
            // std::cout<<"Intersects!!\n";
        }



        // std::cout<<"rendered\n";
    }

    for(auto i : this->PlayerUnits)
    {
        i.render(this->window);
    }
    // std::cout<<this->EnemyUnits.size()<<"\n";

    // if(this->EnemyUnits.size() > 0)
    //     this->EnemyUnits[0].render(this->window);

    // this->window->draw(this->EnemyBase);
    // this->window->draw(this->PlayerBase);

    this->window->display();
} 

void Game::enemyUnitsUpdate()
{
    // std::cout<<"Move\n";
    for(auto &i : this->EnemyUnits)
    {
        i.move();
    }

    for (int i = 0; i < this->EnemyUnits.size(); i++)
    {
        if(this->EnemyUnits[i].getBounds().intersects(this->PlayerBase.getBounds()))
            this->EnemyUnits.erase(this->EnemyUnits.begin() + i);
    }
    
        
        // if(i.getBounds().intersects(this->PlayerBase.getBounds()))
        // i.move();
    
    
}

void Game::playerUnitsUpdate()
{
    for(auto &i : this->PlayerUnits)
    {
        i.move();
    }

    for (int i = 0; i < this->PlayerUnits.size(); i++)
    {
        if(this->PlayerUnits[i].getBounds().intersects(this->EnemyBase.getBounds()))
            this->PlayerUnits.erase(this->PlayerUnits.begin() + i);
        
        for (int j = 0; j < this->EnemyUnits.size(); j++)
        {
            if(this->PlayerUnits[i].getBounds().intersects(this->EnemyUnits[j].getBounds()))
            {
                this->PlayerUnits.erase(this->PlayerUnits.begin() + i);
                this->EnemyUnits.erase(this->EnemyUnits.begin() + j);
            }
        }
        
        
    }

}


// Game mechanics
