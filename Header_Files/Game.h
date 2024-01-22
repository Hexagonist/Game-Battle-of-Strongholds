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
    sf::Font medievalFont;

    // Game states
    bool _mainmenu_state;
    bool _game_state;
    bool _pause_state;
    bool _gameOver_state;
    bool _gameWon_state;

    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Game objects
    sf::RectangleShape enemy;

    //Background
    std::vector<sf::Sprite> Grass;
    sf::Sprite Sky;
    void initBackground();
    void renderBackground();

    //UI
    sf::Vector2f mousePosition;
    sf::Text txt_coins;
    int txt_bases_health_fSize;
    sf::Text txt_player_base_health;
    sf::Text txt_enemy_base_health;
    sf::Vector2f txt_coins_Pos;

    sf::Sprite StoneHUD;
    sf::Sprite SpawnBar;
    sf::RectangleShape RedBar;
    
    sf::Sprite btn_spwn_Knight;
    sf::Sprite btn_spwn_background;
    void initUIbtns();
    void updateUIbtns();
    void initHUD();

    // Units spawn queue frame
    std::vector<sf::Sprite> UnitsQueue;
    sf::Sprite UnitsQueue_background;
    void initUnitsQueue();
    void updateUnitsQueue();




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
    sf::Texture T_stoneHUD;
    sf::Texture T_spawnbar;
    sf::Texture T_btn_background_1;
    sf::Texture T_destroyed_castle;
    sf::Texture T_saved_castle;
    sf::Texture T_queue_frame;
    sf::Texture T_scroll;

    

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
    int player_base_health, enemy_base_health;
    int unit_1_cost, unit_1_dmg;
    void enemyUnitsUpdate();
    void enemyUnitsUpdate_S();
    void playerUnitsUpdate();
    void playerUnitsUpdate_S();
    float Unit1_speed;

    // Main menu
    sf::Text txt_game_title;
    void initMainMenu();
    void initMainMenu_S();

    // Game over window
    sf::Sprite Destroyed_castle;
    void initGameOverWindow();
    sf::Text txt_game_over;

    // Victory window
    sf::Sprite Game_won;
    void initGameWonWindow();
    sf::Text txt_game_won;

    // Pause window
    sf::RectangleShape pause_rect;
    sf::Text txt_game_paused;
    void initGamePausedWindow();




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