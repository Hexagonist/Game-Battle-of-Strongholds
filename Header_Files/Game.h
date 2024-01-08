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

    //Background
    std::vector<sf::Sprite> Grass;
    sf::Sprite Sky;

    //UI
    sf::Sprite StoneHUD;
    sf::Sprite SpawnBar;
    sf::RectangleShape RedBar;


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
    void initEnemies_S();
    void initBase();
    void initBase_S();
    void spawnUnit(BasicUnit Unit, float posX, float posY);
    void spawnEnemyUnits();
    void spawnEnemyUnits_S();
    void spawnPlayerUnit();
    void spawnPlayerUnit_S();
    
    // Game mechanics
    void enemyUnitsUpdate();
    void enemyUnitsUpdate_S();
    void playerUnitsUpdate();
    void playerUnitsUpdate_S();
    float Unit1_speed;

    // Main menu
    void initMainMenu();

    // Textures
    sf::Texture castle;
    sf::Texture unit1_T;

    //Troubleshooting
    sf::FloatRect windowBounds;
    sf::FloatRect rectangleBounds;

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


