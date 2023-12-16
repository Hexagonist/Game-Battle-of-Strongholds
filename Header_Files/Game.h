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
#include "../Header_Files/Button.h"



class Game
{
private:
    // Variables
    int max_EnemyUnits;
    float spawnTimer;
    float spawnTimerMax;
    float playerSpawnTimer;
    float playerSpawnTimerMax;
    unsigned int playerSpawnQueueNum;
    unsigned int playerSpawnQueueNumMax;
    sf::Font defaultFont;

    // Game states
    bool _mainmenu_state;
    bool _game_state;
    bool _pause_state;

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


    // Test
    std::vector<SwagBall> swagBalls;

    // Main menu
    Button btn_start;
    Button btn_settings;
    Button btn_exit;
    Button btn_menu;
    int cntr;


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

    // Main menu
    void initMainMenu();

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


