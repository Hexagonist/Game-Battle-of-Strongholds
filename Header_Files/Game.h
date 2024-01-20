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
    sf::Vector2f mousePosition;
    sf::Text txt_coins;
    sf::Vector2f txt_coins_Pos;

    sf::Sprite StoneHUD;
    sf::Sprite SpawnBar;
    sf::RectangleShape RedBar;
    
    sf::Sprite btn_spwn_Knight;
    sf::Sprite btn_spwn_background;
    void initUIbtns();
    void updateUIbtns();




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

    // Textures
    sf::Texture T_castle;
    sf::Texture T_unit1;
    sf::Texture T_dirt;
    sf::Texture T_sky;
    sf::Texture T_btn_background_1;

    

    // Private Functions
    void initVariables();
    void initTextures();
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
    int coins;
    int unit_1_cost;
    void enemyUnitsUpdate();
    void enemyUnitsUpdate_S();
    void playerUnitsUpdate();
    void playerUnitsUpdate_S();
    float Unit1_speed;

    // Main menu
    void initMainMenu();

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


