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
    this->max_EnemyUnits = 0;
    this->spawnTimerMax = 120.f;
    this->spawnTimer = this->spawnTimerMax;
    this->playerSpawnTimerMax = 60.f;
    this->playerSpawnTimer = 0.f;
    this->playerSpawnQueueNum = 0;
    this->playerSpawnQueueNumMax = 5;
    this->Unit1_speed = 10.f;

    // Game mechanics
    this->coins = 130;
    this->unit_1_cost = 10;
    this->unit_1_dmg = 10;
    this->player_base_health = 10;
    this->enemy_base_health = 10;


    // Font loading from file
    if (!this->defaultFont.loadFromFile("../Resource_Files/ARIAL.TTF")) {
        // Handle font loading error
        std::cout<<"/////////////// Font load failed ! ///////////////\n";
    }
    this->defaultFont.loadFromFile("../Resource_Files/ARIAL.TTF");

    if (!this->medievalFont.loadFromFile("../Resource_Files/A letra do reino.ttf")) {
        // Handle font loading error
        std::cout<<"/////////////// Font load failed ! ///////////////\n";
    }
    this->medievalFont.loadFromFile("../Resource_Files/A letra do reino.ttf");

    // Game states
    this->_mainmenu_state = true;
    this->_game_state = false;
    this->_pause_state = false;
    this->_gameOver_state = false;
    this->_gameWon_state = false;

    this->initTextures();

    // UI
    this->txt_bases_health_fSize = 18;

    this->txt_coins.setFont(this->defaultFont); // Set the font
    this->txt_coins.setCharacterSize(24); // Set the character size
    this->txt_coins.setFillColor(sf::Color(255,215,0)); // Set the fill color

    this->txt_player_base_health.setFont(this->defaultFont); // Set the font
    this->txt_player_base_health.setCharacterSize(this->txt_bases_health_fSize); // Set the character size
    this->txt_player_base_health.setFillColor(sf::Color::Red); // Set the fill color

    this->txt_enemy_base_health.setFont(this->defaultFont); // Set the font
    this->txt_enemy_base_health.setCharacterSize(this->txt_bases_health_fSize); // Set the character size
    this->txt_enemy_base_health.setFillColor(sf::Color::Red); // Set the fill color

    this->initUIbtns();

    // Game over window
    this->Destroyed_castle = sf::Sprite(this->T_destroyed_castle);

    // Game won window
    this->Game_won = sf::Sprite(this->T_saved_castle);

    // Game paused window
    
}

void Game::initGameReset()
{
    this->max_PlayerUnits = 5;
    this->max_EnemyUnits = 0;
    this->spawnTimerMax = 120.f;
    this->spawnTimer = this->spawnTimerMax;
    this->playerSpawnTimerMax = 60.f;
    this->playerSpawnTimer = 0.f;
    this->playerSpawnQueueNum = 0;
    this->playerSpawnQueueNumMax = 5;
    this->Unit1_speed = 10.f;

    // Game mechanics
    this->coins = 130;
    this->unit_1_cost = 10;
    this->unit_1_dmg = 10;
    this->player_base_health = 10;
    this->enemy_base_health = 10;

    // Game states
    this->_mainmenu_state = true;
    this->_game_state = false;
    this->_pause_state = false;
    this->_gameOver_state = false;
    this->_gameWon_state = false;
}

void Game::initTextures()
{
    // Texture load test
    // Units Textures
    sf::Texture T_unit1;
    if (!T_unit1.loadFromFile("../Resource_Files/Textures/Knight.png")) {
        // Handle the error if the texture fails to load
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_unit1 = T_unit1;

    sf::Texture dirt;
    if (!dirt.loadFromFile("../Resource_Files/Textures/Dirt.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_dirt = dirt;

    sf::Texture sky;
    if (!sky.loadFromFile("../Resource_Files/Textures/Sky.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_sky = sky;

    sf::Texture btn_background_1;
    if (!btn_background_1.loadFromFile("../Resource_Files/Textures/btn_background_1.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_btn_background_1 = btn_background_1;

    sf::Texture destroyed_castle;
    if (!destroyed_castle.loadFromFile("../Resource_Files/Textures/you_lost.jpg")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_destroyed_castle = destroyed_castle;

    sf::Texture saved_castle;
    if (!saved_castle.loadFromFile("../Resource_Files/Textures/victory.jpg")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_saved_castle = saved_castle;

    sf::Texture queue_frame;
    if (!queue_frame.loadFromFile("../Resource_Files/Textures/queue.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_queue_frame = queue_frame;

    sf::Texture stoneHUD;
    if (!stoneHUD.loadFromFile("../Resource_Files/Textures/StoneHUD.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_stoneHUD = stoneHUD;

    sf::Texture spawnbar;
    if (!spawnbar.loadFromFile("../Resource_Files/Textures/loading_bar.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_spawnbar = spawnbar;

    sf::Texture scroll;
    if (!scroll.loadFromFile("../Resource_Files/Textures/scroll.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_scroll = scroll;

    sf::Texture wood_frame;
    if (!wood_frame.loadFromFile("../Resource_Files/Textures/wood_frame.png")) {
        std::cout<<"Loading base texture failed!!!";
    }
    this->T_wood_frame = wood_frame;

}

void Game::initWindow()
{
    this->videoMode.width = 1200;
    this->videoMode.height = 700;
    // this->videoMode.getDesktopMode() future possible implementation
    this->window = new sf::RenderWindow(this->videoMode,  "Battle of Strongholds");

    this->window->setFramerateLimit(60);


    //Troubleshooting
    sf::FloatRect windowBounds(0, 0, this->window->getSize().x, this->window->getSize().y);
    this->windowBounds = windowBounds;
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

void Game::initEnemies_S()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
}

void Game::initBase()
{
    float scale = 1.0f;
    float BaseWidth = 100.f, BaseHeight = 200.f;
    float GrassBelt = 50.f;

    this->PlayerBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Player", sf::Color::Cyan, &this->videoMode);
    this->EnemyBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Enemy", sf::Color::Red, &this->videoMode);
}

// Sprite
void Game::initBase_S()
{
    float scale = 1.0f;
    float BaseWidth = 100.f, BaseHeight = 100.f;
    float GrassBelt = 50.f;

    //Texture init
    sf::Texture texture;
    if (!texture.loadFromFile("../Resource_Files/Textures/castle.png")) {
        // Handle the error if the texture fails to load
        std::cout<<"Loading base texture failed!!!";
    }
    else{std::cout<<"Loading base texture succeded!!!";}
    this->T_castle = texture;

    this->PlayerBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Player", this->T_castle, &this->videoMode);
    this->EnemyBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Enemy", this->T_castle, &this->videoMode);

    // // Sets positions
    // this->EnemyBase.getSprite().setPosition(this->EnemyBase.getSprite().getPosition().x + 1000);

    // this->PlayerBase.getSprite().setPosition(100, 100);
}

void Game::initGameOverWindow()
{
    float scale_x = static_cast<float>(this->window->getSize().x)/this->T_destroyed_castle.getSize().x;
    float scale_y = static_cast<float>(this->window->getSize().y)/this->T_destroyed_castle.getSize().y;
    this->Destroyed_castle.setScale(scale_x, scale_y);

    this->txt_game_over.setFont(this->medievalFont); // Set the font
    this->txt_game_over.setCharacterSize(120); // Set the character size
    this->txt_game_over.setFillColor(sf::Color::Red); // Set the fill color
    this->txt_game_over.setString("YOU LOST!"); 
    this->txt_game_over.setPosition(this->window->getSize().x/2 - this->txt_game_over.getGlobalBounds().getSize().x / 2, this->txt_game_over.getGlobalBounds().getSize().y / 2);

    // Background sprite
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    float frame_offset = 10.f;

    if((this->txt_game_over.getGlobalBounds().width != (this->T_wood_frame).getSize().x) || (txt_game_over.getGlobalBounds().height != (T_wood_frame).getSize().y))
    {
        scaleFactor_x = (this->txt_game_over.getGlobalBounds().width + 6*frame_offset)  / (this->T_wood_frame).getSize().x;
        scaleFactor_y = (this->txt_game_over.getGlobalBounds().height + 3*frame_offset) / (this->T_wood_frame).getSize().y;
    }
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"Scale factors: "<<scaleFactor_x<<"  "<<scaleFactor_y<<"\n";
    // std::cout<<"Txt game title: "<<txt_game_over.getGlobalBounds().width<<"  "<<txt_game_over.getGlobalBounds().height<<"\n";

    this->Game_over_background = sf::Sprite(this->T_wood_frame);
    this->Game_over_background.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
    this->Game_over_background.setPosition(this->window->getSize().x/2 - this->Game_over_background.getGlobalBounds().getSize().x / 2, this->Game_over_background.getGlobalBounds().getSize().y - 2.5*frame_offset);
}

void Game::initGameWonWindow()
{
    float scale_x = static_cast<float>(this->window->getSize().x)/this->T_saved_castle.getSize().x;
    float scale_y = static_cast<float>(this->window->getSize().y)/this->T_saved_castle.getSize().y;
    this->Game_won.setScale(scale_x, scale_y);

    this->txt_game_won.setFont(this->medievalFont); // Set the font
    this->txt_game_won.setCharacterSize(120); // Set the character size
    this->txt_game_won.setFillColor(sf::Color::Green); // Set the fill color
    this->txt_game_won.setString("VICTORY"); 
    this->txt_game_won.setPosition(this->window->getSize().x/2 - this->txt_game_won.getGlobalBounds().getSize().x / 2, this->txt_game_won.getGlobalBounds().getSize().y / 2);

    // Background sprite
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    float frame_offset = 10.f;

    if((this->txt_game_won.getGlobalBounds().width != (this->T_wood_frame).getSize().x) || (txt_game_won.getGlobalBounds().height != (T_wood_frame).getSize().y))
    {
        scaleFactor_x = (this->txt_game_won.getGlobalBounds().width + 6*frame_offset)  / (this->T_wood_frame).getSize().x;
        scaleFactor_y = (this->txt_game_won.getGlobalBounds().height + 3*frame_offset) / (this->T_wood_frame).getSize().y;
    }
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"Scale factors: "<<scaleFactor_x<<"  "<<scaleFactor_y<<"\n";
    // std::cout<<"Txt game title: "<<txt_game_won.getGlobalBounds().width<<"  "<<txt_game_won.getGlobalBounds().height<<"\n";

    this->Game_won_background = sf::Sprite(this->T_wood_frame);
    this->Game_won_background.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
    this->Game_won_background.setPosition(this->window->getSize().x/2 - this->Game_won_background.getGlobalBounds().getSize().x / 2, this->Game_won_background.getGlobalBounds().getSize().y - 2.5*frame_offset);
}

void Game::initGamePausedWindow()
{
    // Create a grey, half-transparent rectangle
    this->pause_rect = sf::RectangleShape(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->pause_rect.setFillColor(sf::Color(128, 128, 128, 128)); // Grey with 50% transparency
    // this->pause_rect.setPosition(300.f, 225.f);

    this->txt_game_paused.setFont(this->medievalFont); // Set the font
    this->txt_game_paused.setCharacterSize(90); // Set the character size
    this->txt_game_paused.setFillColor(sf::Color::Black); // Set the fill color
    this->txt_game_paused.setString("Game paused"); 
    this->txt_game_paused.setPosition(this->window->getSize().x/2 - this->txt_game_paused.getGlobalBounds().getSize().x / 2, this->window->getSize().y/2 - this->txt_game_paused.getGlobalBounds().getSize().y / 2);
}

void Game::initMainMenu()
{
    // Game title
    this->txt_game_title.setFont(this->medievalFont); // Set the font
    this->txt_game_title.setCharacterSize(90); // Set the character size
    this->txt_game_title.setFillColor(sf::Color::Black); // Set the fill color
    this->txt_game_title.setString("BATTLE OF STRONGHOLDS"); 
    this->txt_game_title.setPosition(this->window->getSize().x/2 - this->txt_game_title.getGlobalBounds().getSize().x / 2, this->txt_game_title.getGlobalBounds().getSize().y / 2);
    
    float menu_btns_mod = -1; // Menu buttons y pos modificator
    // Start Button (text, {width, height}, font_size, button_background_color, text_color)
    unsigned int btn_start_width = 200, btn_start_height = 50, font_size = 20;

    this->btn_start = Button("Start", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, this->defaultFont, sf::Color::Black);

    // std::cout<<btn1.get_Size().x;
    // button_set(&btn_start, window_width, window_height, btn_start_width, btn_start_height, arial);


    this->btn_start.setPosition(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) + menu_btns_mod*btn_start_height});  // Warning

    this->btn_start.setFont(this->defaultFont);
    menu_btns_mod+=1.5;

    this->btn_settings = Button("Settings", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, this->defaultFont, sf::Color::Black);
    this->btn_settings.setPosition(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) + menu_btns_mod*btn_start_height});  // Warning

    this->btn_settings.setFont(this->defaultFont);
    menu_btns_mod+=1.5;

    this->btn_exit = Button("Exit", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, this->defaultFont, sf::Color::Black);
    this->btn_exit.setPosition(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) + menu_btns_mod*btn_start_height});  // Warning

    this->btn_exit.setFont(this->defaultFont);

    // temp game loop
    // this->btn_menu = Button("Game loop, press to menu", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, this->defaultFont, sf::Color::Black);
    // this->btn_menu.setPosition({100, 100});
    // this->btn_menu.setFont(this->defaultFont);


    this->cntr = 0; // test var
}

void Game::initMainMenu_S()
{
    // Game title
    this->txt_game_title.setFont(this->medievalFont); // Set the font
    this->txt_game_title.setCharacterSize(90); // Set the character size
    this->txt_game_title.setFillColor(sf::Color::Black); // Set the fill color
    this->txt_game_title.setString("BATTLE OF STRONGHOLDS"); 
    this->txt_game_title.setPosition(this->window->getSize().x/2 - this->txt_game_title.getGlobalBounds().getSize().x / 2, this->txt_game_title.getGlobalBounds().getSize().y / 2);
    
    // Title Background sprite
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    float frame_offset = 10.f;

    if((this->txt_game_title.getGlobalBounds().width != (this->T_wood_frame).getSize().x) || (txt_game_title.getGlobalBounds().height != (T_wood_frame).getSize().y))
    {
        scaleFactor_x = (this->txt_game_title.getGlobalBounds().width + 6*frame_offset)  / (this->T_wood_frame).getSize().x;
        scaleFactor_y = (this->txt_game_title.getGlobalBounds().height + 3*frame_offset) / (this->T_wood_frame).getSize().y;
    }
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"Scale factors: "<<scaleFactor_x<<"  "<<scaleFactor_y<<"\n";
    // std::cout<<"Txt game title: "<<txt_game_title.getGlobalBounds().width<<"  "<<txt_game_title.getGlobalBounds().height<<"\n";

    this->game_title_background = sf::Sprite(this->T_wood_frame);
    this->game_title_background.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
    this->game_title_background.setPosition(this->window->getSize().x/2 - this->game_title_background.getGlobalBounds().getSize().x / 2, this->game_title_background.getGlobalBounds().getSize().y - 4*frame_offset);
    // std::cout<<"game title background pos: "<<this->game_title_background.getPosition().x<<"  "<<this->game_title_background.getPosition().y<<"\n";
    // std::cout<<"T_frame Size: "<<this->T_wood_frame.getSize().x<<"  "<<this->T_wood_frame.getSize().y<<"\n";
    // std::cout<<"Scale: "<<this->game_title_background.getScale().x<<"  "<<this->game_title_background.getScale().y<<"\n";

    // BUTTONS
    float menu_btns_mod = -1; // Menu buttons y pos modificator
    // Start Button (text, {width, height}, font_size, button_background_color, text_color)
    unsigned int btn_start_width = 200, btn_start_height = 50, font_size = 28;

    this->btn_start = Button("Start", {btn_start_width, btn_start_height}, font_size, &this->T_scroll, this->medievalFont, sf::Color::Black);

    // std::cout<<btn1.get_Size().x;
    // button_set(&btn_start, window_width, window_height, btn_start_width, btn_start_height, arial);


    this->btn_start.setPosition_S(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) + menu_btns_mod*btn_start_height});  // Warning

    this->btn_start.setFont(this->medievalFont);
    menu_btns_mod+=1.5;

    this->btn_settings = Button("Settings", {btn_start_width, btn_start_height}, font_size, &this->T_scroll, this->medievalFont, sf::Color::Black);
    this->btn_settings.setPosition_S(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) + menu_btns_mod*btn_start_height});  // Warning

    this->btn_settings.setFont(this->medievalFont);
    menu_btns_mod+=1.5;

    this->btn_exit = Button("Exit", {btn_start_width, btn_start_height}, font_size, &this->T_scroll, this->medievalFont, sf::Color::Black);
    this->btn_exit.setPosition_S(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) + menu_btns_mod*btn_start_height});  // Warning

    this->btn_exit.setFont(this->medievalFont);

    this->cntr = 0; // test var


    // temp game loop
    this->btn_menu = Button("Main Menu", {btn_start_width, btn_start_height}, font_size, &this->T_scroll, this->defaultFont, sf::Color::Black);
    this->btn_menu.setPosition_S(
    {static_cast<unsigned int>(this->videoMode.width / 2) - btn_start_width / 2,
    static_cast<unsigned int>(this->videoMode.height / 2) - btn_start_height / 2});

    this->btn_menu.setFont(this->medievalFont);
}

void Game::initBackground()
{
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    float Grass_size = 50.f;
    float Sky_sizeX = this->videoMode.width;
    float Sky_sizeY = this->videoMode.height - 50.f;

    // Grass
    if(Grass_size != (this->T_dirt).getSize().x)
    {
        scaleFactor_x = Grass_size / this->T_dirt.getSize().x;
        scaleFactor_y = Grass_size / this->T_dirt.getSize().y;
    }
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";

    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    // std::cout<<"Dirt: "<<this->T_dirt.getSize().x<<"   "<<this->T_dirt.getSize().y<<"\n";

    for (int i = 0; i < this->videoMode.width; i+=50)
    {
        sf::Sprite temp = sf::Sprite(this->T_dirt);

        // Troubleshooting
        // std::cout<<"ScaleFactor: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
        // std::cout<<"Scale: "<<this->scale<<"\n";
        // std::cout<<"Size: "<<Grass_size<<"  "<<Grass_size<<"\n";
        temp.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
        temp.setPosition(i, this->videoMode.height - 50);
        this->Grass.push_back(temp);
    }

    // Sky
    if(Sky_sizeY != (this->T_sky).getSize().y)
    {
        scaleFactor_x = Sky_sizeX / this->T_sky.getSize().x;
        scaleFactor_y = Sky_sizeY / this->T_sky.getSize().y;
    }
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    // std::cout<<"Dirt: "<<sky.getSize().x<<"   "<<sky.getSize().y<<"\n";

    this->Sky = sf::Sprite(this->T_sky);
    this->Sky.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
}

void Game::renderBackground()
{
    // Grass
    for(auto &i : this->Grass)
    {
        this->window->draw(i);
    }

    // Sky
    this->window->draw(this->Sky);
}

void Game::initUIbtns() 
{
    BasicUnit Btn = BasicUnit(this->T_castle, sf::Vector2f(1.f, 1.f), 50.f, 50.f, 50.f, "Unit", 10.f, 0.f);
    Btn.update_S(25.f, 25.f);

    this->btn_spwn_background = sf::Sprite(this->T_btn_background_1);
    this->btn_spwn_Knight.setScale(50.f/this->T_unit1.getSize().x, 50.f/this->T_unit1.getSize().y);

    this->btn_spwn_Knight = sf::Sprite(this->T_unit1);
    this->btn_spwn_Knight.setScale(40.f/this->T_unit1.getSize().x, 40.f/this->T_unit1.getSize().y);
}

void Game::updateUIbtns()
{
    this->btn_spwn_background.setPosition(20.f, 20.f);
    this->btn_spwn_Knight.setPosition(25.f, 25.f);
}

void Game::initHUD()
{
    float StoneHUD_sizeX = this->videoMode.width;
    float StoneHUD_sizeY = 100.f;
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    
    if(StoneHUD_sizeX != (this->T_stoneHUD).getSize().x)
    {
        scaleFactor_x = StoneHUD_sizeX / this->T_stoneHUD.getSize().x;
        scaleFactor_y = StoneHUD_sizeY / this->T_stoneHUD.getSize().y;
    }
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    // std::cout<<"Dirt: "<<this->T_stoneHUD.getSize().x<<"   "<<this->T_stoneHUD.getSize().y<<"\n";

    this->StoneHUD = sf::Sprite(this->T_stoneHUD);
    this->StoneHUD.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));

    //Player's Unit spawn spawn bar
    float SpawnBar_sizeX = 400.f;
    float SpawnBar_sizeY = 20.f;

    if(SpawnBar_sizeX != (this->T_spawnbar).getSize().x)
    {
        scaleFactor_x = SpawnBar_sizeX / this->T_spawnbar.getSize().x;
        scaleFactor_y = SpawnBar_sizeY / this->T_spawnbar.getSize().y;
    }
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    // std::cout<<"Dirt: "<<this->T_spawnbar.getSize().x<<"   "<<this->T_spawnbar.getSize().y<<"\n";

    this->SpawnBar = sf::Sprite(this->T_spawnbar);
    this->SpawnBar.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
    this->SpawnBar.setPosition(this->videoMode.width/2 - SpawnBar_sizeX/2, StoneHUD_sizeY);

    // Red bar
    float RedBar_sizeX = SpawnBar_sizeX - 40.f;
    float RedBar_sizeY = SpawnBar_sizeY - 6.f;

    this->RedBar.setSize(sf::Vector2f(RedBar_sizeX, RedBar_sizeY));
    this->RedBar.setFillColor(sf::Color::Red);
    this->RedBar.setPosition(this->videoMode.width/2 - RedBar_sizeX/2, StoneHUD_sizeY + 3.f);
}

void Game::initUnitsQueue()
{
    // Background
    float scale_x = 258.f / this->T_queue_frame.getSize().x;
    float scale_y = 50.f / this->T_queue_frame.getSize().y;
    this->UnitsQueue_background = sf::Sprite(this->T_queue_frame);
    this->UnitsQueue_background.setScale(sf::Vector2f(scale_x, scale_y));
    this->UnitsQueue_background.setPosition(this->window->getSize().x/2 - this->UnitsQueue_background.getGlobalBounds().width/2, 100.f + 20.f); // 100.f is stonehud height and 20.f is spawn bar height
}

void Game::updateUnitsQueue()
{
    // Queue
    float scale_x = 40.f / this->T_unit1.getSize().x;
    float scale_y = 40.f / this->T_unit1.getSize().y;

    for (unsigned int i = this->UnitsQueue.size(); i < this->playerSpawnQueueNum; i++)
    {
        sf::Sprite temp = sf::Sprite(this->T_unit1);
        temp.setScale(scale_x, scale_y);
        temp.setPosition(
            this->UnitsQueue_background.getPosition().x + 5.f + i*temp.getGlobalBounds().width + i*10.f,
            this->UnitsQueue_background.getPosition().y + 5.f);
        this->UnitsQueue.push_back(temp);
    }
    std::cout<<"Units queue: "<<this->UnitsQueue.size()<<"\n";
}

// Constructor / Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initBackground();
    this->initHUD();
    this->initMainMenu_S();
    this->initGameOverWindow();
    this->initGameWonWindow();
    this->initGamePausedWindow();
    this->initEnemies_S();
    this->initUnitsQueue();

    // Sprite
    this->initBase_S();
    // this->initBase();
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
            BasicUnit U = BasicUnit(sf::Vector2f(1.f, 1.f), 50.f, 50.f, 50.f, "Unit", sf::Color::Red, 10.f, -5.f);
            U.update(this->videoMode.width - this->EnemyBase.getWidth() - U.get_width(), this->videoMode.height);

            this->EnemyUnits.push_back(U);
            this->spawnTimer = 0.f;

            std::cout<<"//////////New unit//////////\n";
            // std::cout<<EnemyUnits[0].get_width()<<"\n";
            // std::cout<<EnemyUnits.size()<<"\n";



        }
    }
}

void Game::spawnEnemyUnits_S()
{
    // Timer
    if (this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else
    {
        if(this->EnemyUnits.size() < this->max_EnemyUnits)
        {
            BasicUnit U = BasicUnit(this->T_castle, sf::Vector2f(-1.f, 1.f), 50.f, 50.f, 50.f, "Unit", 10.f, -this->Unit1_speed);
            U.update_S(this->videoMode.width - this->EnemyBase.getWidth(), this->videoMode.height);

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
                BasicUnit U = BasicUnit(sf::Vector2f(1.f, 1.f), 50.f, 50.f, 50.f, "Unit", sf::Color::Blue, 10.f, 5.f);
                U.update(this->EnemyBase.getWidth(), this->videoMode.height);

                this->PlayerUnits.push_back(U);

                std::cout<<"//////////New Player unit!!!!!!!!!!!!!\n";
                this->playerSpawnQueueNum -= 1;
                this->playerSpawnTimer = 0.f;
            }
    }

}

void Game::spawnPlayerUnit_S()
{
    if ((this->playerSpawnTimer < this->playerSpawnTimerMax) && (!this->_mainmenu_state) && (this->playerSpawnQueueNum > 0))
        this->playerSpawnTimer += 1.f;
    else
    {
        if((this->PlayerUnits.size() < this->max_PlayerUnits) && (this->playerSpawnQueueNum > 0) && (this->playerSpawnTimer == this->playerSpawnTimerMax))
            {
                BasicUnit U = BasicUnit(this->T_castle, sf::Vector2f(1.f, 1.f), 50.f, 50.f, 50.f, "Unit", 10.f, this->Unit1_speed);
                U.update_S(this->PlayerBase.getWidth(), this->videoMode.height);
                //Troubleshooting
                std::cout<<"PBwidth: "<<this->PlayerBase.getWidth()<<"\n";
                std::cout<<"SpawnPUPos: "<<U.getSprite().getPosition().x<<"   "<<U.getSprite().getPosition().y<<"\n";

                this->PlayerUnits.push_back(U);

                std::cout<<"//////////New Player unit!!!!!!!!!!!!!\n";
                this->playerSpawnQueueNum -= 1;
                this->playerSpawnTimer = 0.f;

                // Deleting one element from spawn queue indicator
                if(!this->UnitsQueue.empty()) 
                {
                    this->UnitsQueue.erase(this->UnitsQueue.begin());
                    for (auto& sprite : this->UnitsQueue) 
                    {
                        sprite.setPosition(sprite.getPosition().x - 50.f, sprite.getPosition().y);
                    }
                }
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



// Events
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

            if (this->ev.key.code == sf::Keyboard::Space)
            {
                if ((this->_game_state) && (!this->_pause_state))
                    this->_pause_state = true;

                else if((!this->_game_state) && (this->_pause_state))
                {
                    this->_pause_state = false;
                    this->_game_state = true;
                }
            }


        // moge dac do menu.h
        // Start button 's reactions to mouse
        case sf::Event::MouseMoved:
                // // Menu.h issue
                // // for (int i = 0; i < main_menu.get_Btns_num(); i++)
                // // {
                // //     if (main_menu.isMouseOverBtn(i, window)) {
                // //         main_menu.setBackColorBtn(i, sf::Color::White);
                // //         std::cout<<"White\n";
                // //     }
                // //     else {
                // //         main_menu.setBackColorBtn(i, sf::Color::Red);
                // //     }
                // // }

                this->mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->window));

                if ((this->btn_menu.isMouseOver_S(*this->window)) && ((this->_gameOver_state)||(this->_gameWon_state)))
                {
                    this->btn_menu.setTextColor(sf::Color::Red);
                    std::cout<<"Red\n";
                }
                else {this->btn_menu.setTextColor(sf::Color::Black);}

                if (_mainmenu_state)
                {
                    if (this->btn_start.isMouseOver_S(*this->window)) {
                        this->btn_start.setTextColor(sf::Color::Red);
                        std::cout<<"Red\n";
                    }
                    else {
                        this->btn_start.setTextColor(sf::Color::Black);
                    }

                    if (this->btn_settings.isMouseOver_S(*this->window)) {
                        this->btn_settings.setTextColor(sf::Color::Red);
                        std::cout<<"Red\n";
                    }
                    else {
                        this->btn_settings.setTextColor(sf::Color::Black);
                    }

                    if (this->btn_exit.isMouseOver_S(*this->window)) {
                        this->btn_exit.setTextColor(sf::Color::Red);
                        std::cout<<"Red\n";
                    }
                    else {
                        this->btn_exit.setTextColor(sf::Color::Black);
                    }
                }

                // temp game loop
                if (_game_state){
                    if (this->btn_menu.isMouseOver_S(*this->window)) {
                        this->btn_menu.setTextColor(sf::Color::Red);
                        std::cout<<"Red\n";
                    }
                    else {
                        this->btn_menu.setTextColor(sf::Color::Black);
                    }
                }

            case sf::Event::MouseButtonPressed:
                // Menu.h issue
                // nie moge dac do menu.h Daj do publi c buttonsy
                // for (int i = 0; i < main_menu.get_Btns_num(); i++)
                // {
                //     if (main_menu.get_Btn(i).isMouseOver(window)) {
                //         std::cout<<cntr<<" Start\n";
                //         cntr+=1;
                //         main_menu.get_Btn(i).setTextColor(sf::Color::Green);
                //         }
                // }

                if (this->ev.mouseButton.button == sf::Mouse::Left){

                    if ((this->btn_menu.isMouseOver_S(*this->window)) && ((this->_gameOver_state)||(this->_gameWon_state)))
                    {
                        this->_game_state=false;
                        this->_gameOver_state=false;
                        this->_gameWon_state=false;
                        this->_mainmenu_state=true;
                        this->initGameReset();
                    }

                    if (this->_mainmenu_state)
                    {
                        if (this->btn_start.isMouseOver_S(*this->window)) 
                        {
                            std::cout<<this->cntr<<" Start\n";
                            this->cntr+=1;
                            this->btn_start.setTextColor(sf::Color::Green);
                            this->_mainmenu_state = false;
                            this->_game_state = true;
                        }

                        if (btn_settings.isMouseOver_S(*this->window)) 
                        {
                            std::cout<<this->cntr<<" Settings\n";
                            this->cntr+=1;
                            this->btn_settings.setTextColor(sf::Color::Green);
                        }

                        if (this->btn_exit.isMouseOver_S(*this->window)) 
                        {
                            this->window->close();
                        }
                    }

                    // temp game states
                    // if ((this->_game_state) && (this->btn_menu.isMouseOver_S(*this->window)))
                    // {
                    //     this->_game_state=false;
                    //     this->_mainmenu_state=true;
                    // }



                    if((this->ev.mouseButton.button == sf::Mouse::Left) && 
                    (this->btn_spwn_background.getGlobalBounds().contains(this->mousePosition)) &&
                    (this->playerSpawnQueueNum < this->playerSpawnQueueNumMax) && 
                    (this->coins >= 10) &&
                    (!this->_mainmenu_state) &&
                    (!this->_pause_state))
                    {
                        this->playerSpawnQueueNum += 1;
                        this->coins -= 10;
                    }
                }

                default: break;
            }


    }

}





void Game::update()
{
    this->pollEvents();
    // this->spawnTimer=0.f;
    // this->spawnSwagBalls();

    // if(this->_mainmenu_state)
    // {
    //     this->initMainMenu();
    // }

    if(this->_game_state)
    {
        // Checks if game is over
        if(this->player_base_health <= 0)
        {
            this->_gameOver_state = true;
            this->_game_state = false;
        }

        // Game won
        if(this->enemy_base_health <= 0)
        {
            this->_gameWon_state = true;
            this->_game_state = false;
        }

        // Game paused
        if(this->_pause_state)
        {
            this->_game_state = false;
        }
        // else if((!this->_mainmenu_state) && (!this->_gameWon_state) && (!this->_gameOver_state))
        // {
        //     this->_game_state = true;
        // }

        // UI update
        std::string temp = "Coins: ";
        temp += std::to_string(this->coins);
        this->txt_coins.setString(temp);

        temp = "(";
        temp += std::to_string(this->player_base_health);
        temp += "/100)";
        this->txt_player_base_health.setString(temp);

        temp = "(";
        temp += std::to_string(this->enemy_base_health);
        temp += "/100)";
        this->txt_enemy_base_health.setString(temp);

        
        if(!this->_pause_state)
        {
            this->spawnEnemyUnits_S();
            this->spawnPlayerUnit_S();

            this->enemyUnitsUpdate_S();
            this->playerUnitsUpdate_S();

            this->updateUnitsQueue();
        }
    }



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

    // Main menu render
    // if(this->_mainmenu_state)
    // {
    //     this->renderBackground();
    //     this->window->draw(this->txt_game_title);
    //     this->btn_start.render(this->window);
    //     this->btn_settings.render(this->window);
    //     // this->btn_menu.render(this->window);
    //     this->btn_exit.render(this->window);
    //     std::cout<<"Menu Rendered!!!\n";

    //     // Debugging
    //     // this->btn_start.printPos();

    //     // Strongholds' Sprites
    //     this->PlayerBase.render_S(this->T_castle, this->window);
    //     this->EnemyBase.render_S(this->T_castle, this->window);
    // }

    if(this->_mainmenu_state)
    {
        this->renderBackground();
        this->window->draw(this->game_title_background);
        this->window->draw(this->txt_game_title);
        this->btn_start.render_S(this->window);
        this->btn_settings.render_S(this->window);
        // this->btn_menu.render_S(this->window);
        this->btn_exit.render_S(this->window);
        // std::cout<<"Menu Rendered!!!\n";

        // Debugging
        // this->btn_start.printPos();

        // Strongholds' Sprites
        this->PlayerBase.render_S(this->T_castle, this->window);
        this->EnemyBase.render_S(this->T_castle, this->window);
    }

    // Game over state
    if(this->_gameOver_state)
    {
        this->window->draw(this->Destroyed_castle);
        this->window->draw(this->Game_over_background);
        this->window->draw(this->txt_game_over);
        this->btn_menu.render_S(this->window); 
    }

    // Game won state
    if(this->_gameWon_state)
    {
        this->window->draw(this->Game_won);
        this->window->draw(this->Game_won_background);
        this->window->draw(this->txt_game_won);
        this->btn_menu.render_S(this->window); 
    }

    // Game render
    if((this->_game_state) || (this->_pause_state))
    {
        //Game Background
        // Variables
        float scaleFactor_x = 1;
        float scaleFactor_y = 1;
        float Grass_size = 50.f;
        float Sky_sizeX = this->videoMode.width;
        float Sky_sizeY = this->videoMode.height - 50.f;

        // // Grass
        // for(auto &i : this->Grass)
        // {
        //     this->window->draw(i);
        // }

        // // Sky
        // this->window->draw(this->Sky);

        this->renderBackground();
        

        // UI
        float StoneHUD_sizeX = this->videoMode.width;
        float StoneHUD_sizeY = 100.f;

        this->window->draw(this->StoneHUD);

        // //Player's Unit spawn spawn bar
        this->window->draw(this->SpawnBar);

        // Red bar
        float RedBar_sizeX = this->SpawnBar.getGlobalBounds().width - 40.f;
        float RedBar_sizeY = this->SpawnBar.getGlobalBounds().height - 6.f;

        this->RedBar.setSize(sf::Vector2f(RedBar_sizeX - (this->playerSpawnTimer/this->spawnTimerMax * 2.f * RedBar_sizeX) , RedBar_sizeY));
        this->window->draw(this->RedBar);

        // UI indicators
        this->txt_coins.setPosition(0.f, this->StoneHUD.getGlobalBounds().getSize().y);
        this->window->draw(this->txt_coins);

        this->txt_player_base_health.setPosition(0.f, this->window->getSize().y - Grass_size - this->PlayerBase.getHeight() - this->txt_bases_health_fSize);
        this->window->draw(this->txt_player_base_health);

        this->txt_enemy_base_health.setPosition(this->window->getSize().x - this->EnemyBase.getWidth(), this->window->getSize().y - Grass_size - this->EnemyBase.getHeight() - this->txt_bases_health_fSize);
        this->window->draw(this->txt_enemy_base_health);

        // Player units queue
        this->window->draw(this->UnitsQueue_background); 

        for (const auto& sprite : this->UnitsQueue) 
        {
            this->window->draw(sprite);
        }
        

        //UI Btns
        
        // this->initUIbtns();
        // this->btn_spwn_Knight.setTexture(T_unit1);
        
        this->updateUIbtns();
        this->window->draw(this->btn_spwn_background);
        this->window->draw(this->btn_spwn_Knight);

        // Strongholds' Sprites
        this->PlayerBase.render_S(this->T_castle, this->window);
        this->EnemyBase.render_S(this->T_castle, this->window);

        //Troubleshooting
        // sf::FloatRect rectangleBounds = this->PlayerBase.getSprite().getGlobalBounds();
        // sf::FloatRect rectangleBoundsPU = this->PlayerUnits[0].getSprite().getGlobalBounds();
        // if (this->windowBounds.intersects(rectangleBounds)) {
        // std::cout<<"Intersects!! PB\n";
        // }
        // else {std::cout<<"DOESNT Intersects!!\n";}
        // if (this->windowBounds.intersects(rectangleBoundsPU)) {
        // std::cout<<"Intersects!! PU\n";
        // }
        // else {std::cout<<"DOESNT Intersects!! PU\n";}
        // std::cout<<"PURectPos: "<<rectangleBoundsPU.getPosition().x<<"   "<<rectangleBoundsPU.getPosition().y<<"\n";
        // std::cout<<"PUSPos: "<<this->PlayerUnits[0].getSprite().getPosition().x<<"   "<<this->PlayerUnits[0].getSprite().getPosition().y<<"\n";



        // this->window.get
        // if(windowBounds.intersects(rectangleBounds)) {
        //     // The rectangle is at least partially within the window
        //     // It's considered to be drawn on the window
        //     // std::cout<<"Intersects!!\n";
        // }

        // Troubleshooting
        // std::cout<<"PBPX:"<<this->PlayerBase.getSprite().getPosition().x<<"\n";
        // std::cout<<"PBPY:"<<this->PlayerBase.getSprite().getPosition().y<<"\n";
        // std::cout<<"EBPX:"<<this->EnemyBase.getSprite().getPosition().x<<"\n";
        // std::cout<<"EBPY:"<<this->EnemyBase.getSprite().getPosition().y<<"\n";
        // std::cout<<"WinX:"<<this->videoMode.width<<"\n";
        // std::cout<<"WinY:"<<this->videoMode.height<<"\n";
        // std::cout<<"Window:"<<this->window->getSize().x<<"   "<<this->window->getSize().y<<"\n";
        // std::cout<<"PBS:"<<this->PlayerBase.getWidth()<<"   "<<this->PlayerBase.getHeight()<<"\n";
        // std::cout<<"EBS:"<<this->EnemyBase.getWidth()<<"   "<<this->EnemyBase.getHeight()<<"\n";


        //Troubleshooting
        // sf::FloatRect rectangleBounds = this->PlayerBase.getSprite().getGlobalBounds();
        // sf::FloatRect windowBounds(0, 0, this->window->getSize().x, this->window->getSize().y);
        // if (windowBounds.intersects(rectangleBounds)) {
        //     // std::cout<<"Intersects!!\n";
        // }
        // else {std::cout<<"DOESNT Intersects!!\n";}

        // Test Sprite
        // sf::Sprite test;
        // test.setTexture(texture);
        // float scaleFactor_x = 100.f / texture.getSize().x;
        // float scaleFactor_y = 100.f / texture.getSize().y;
        // // test.setTextureRect(sf::IntRect(100, 100, 100, 100));
        // test.setScale(1*scaleFactor_x, 1*scaleFactor_y);
        // test.setPosition(100, 100);
        // this->window->draw(test);



        // for(auto i : this->swagBalls)
        // {
        //     i.render(this->window);


        //     sf::FloatRect rectangleBounds = i.getCircle().getGlobalBounds();

        //     if (windowBounds.intersects(rectangleBounds)) {
        //         // std::cout<<"Intersects!!\n";
        //     }


        //     // std::cout<<"rendered\n";
        // }




        //Player's units render
        // Previous
        // for(auto i : this->PlayerUnits)
        // {
        //     i.render(this->window);
        // }

        //Sprites render
        for(auto &i : this->PlayerUnits)
        {
            i.render(this->T_unit1, this->window);
        }

        //Enemie's units render
        for(auto &i : this->EnemyUnits)
        {
            i.render(this->T_unit1, this->window);


            sf::FloatRect rectangleBounds = i.getRect().getGlobalBounds();

            //Troubleshooting
            // if (windowBounds.intersects(rectangleBounds)) {
            //     // The rectangle is at least partially within the window
            //     // It's considered to be drawn on the window
            //     // std::cout<<"Intersects!!\n";
            // }



            // std::cout<<"rendered\n";
        }
        //Troubleshooting
        // std::cout<<this->EnemyUnits.size()<<"\n";
        // if(this->EnemyUnits.size() > 0)
        //     this->EnemyUnits[0].render(this->window);
        // this->window->draw(this->EnemyBase);
        // this->window->draw(this->PlayerBase);

        //Sprites render


    }

    // Game paused state
    if(this->_pause_state)
    {
        this->window->draw(this->pause_rect);
        this->window->draw(this->txt_game_paused);
    }

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

void Game::enemyUnitsUpdate_S()
{
    // std::cout<<"Move\n";
    for(auto &i : this->EnemyUnits)
    {
        i.move_S();
    }


    for (int i = 0; i < this->EnemyUnits.size(); i++)
    {
        if(this->EnemyUnits[i].getSprite().getGlobalBounds().intersects(this->PlayerBase.getSprite().getGlobalBounds()))
        {
            this->EnemyUnits.erase(this->EnemyUnits.begin() + i);
            this->player_base_health -= this->unit_1_dmg;
        }
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

void Game::playerUnitsUpdate_S()
{
    for(auto &i : this->PlayerUnits)
    {
        i.move_S();
        //Troubleshooting
        // std::cout<<"PUPos: "<<i.getSprite().getPosition().x<<"   "<<i.getSprite().getPosition().y<<"\n";
    }

    //Troubleshooting
    // std::cout<<"PlayerUGB: "<<this->PlayerUnits[0].getSprite().getGlobalBounds()<<"\n";
    

    for (int i = 0; i < this->PlayerUnits.size(); i++)
    {
        if(this->PlayerUnits[i].getSprite().getGlobalBounds().intersects(this->EnemyBase.getSprite().getGlobalBounds()))
        {
            this->PlayerUnits.erase(this->PlayerUnits.begin() + i);
            this->enemy_base_health -= this->unit_1_dmg;
        }

        for (int j = 0; j < this->EnemyUnits.size(); j++)
        {
            if(this->PlayerUnits[i].getSprite().getGlobalBounds().intersects(this->EnemyUnits[j].getSprite().getGlobalBounds()))
            {
                this->PlayerUnits.erase(this->PlayerUnits.begin() + i);
                this->EnemyUnits.erase(this->EnemyUnits.begin() + j);
                //Troubleshooting
                std::cout<<"Units Collision DETECTED! ! !                      *"<<"\n";
                this->coins += 15;
            }
        }


    }
}

// Game mechanics
