#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  //Needed?
#include <SFML/Window.hpp>  //Needed?
#include <SFML/Audio.hpp>   //Needed?
#include <SFML/Network.hpp> //Needed?
#include <string>
#include <vector>

#include "../Header_Files/Stronghold.h"
#include "../Source_Files/BasicUnit.h"
#include "SwagBall.h"



class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Game objects
    sf::RectangleShape enemy;

    // Player
    Stronghold PlayerBase;
    std::vector<BasicUnit> PlayerUnits;
    int max_PlayerUnits;

    // Enemy
    Stronghold EnemyBase;
    std::vector<BasicUnit> EnemyUnits;
    int max_EnemyUnits;
    float spawnTimer;
    float spawnTimerMax;
    float playerSpawnTimer;
    float playerSpawnTimerMax;
    unsigned int playerSpawnQueueNum;
    unsigned int playerSpawnQueueNumMax;


    // Test
    std::vector<SwagBall> swagBalls;


    // Private Functions
    void initVariables();
    void initWindow();
    void initEnemies();
    void initBase();
    void spawnUnit(BasicUnit Unit, float posX, float posY);
    void spawnEnemyUnits();
    void spawnPlayerUnit();
    
    // Game mechanics
    void enemyUnitsUpdate();
    void playerUnitsUpdate();

public:
    // Constructor / Destructor
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;


    // Functions
    void pollEvents();
    void update();
    void render();

    //Test
    void spawnSwagBalls();
};


