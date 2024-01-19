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
    this->Unit1_speed = 5.f;

    // Font loading from file
    if (!this->defaultFont.loadFromFile("../Resource_Files/ARIAL.TTF")) {
        // Handle font loading error
        std::cout<<"/////////////// Font load failed ! ///////////////\n";
    }
    this->defaultFont.loadFromFile("../Resource_Files/ARIAL.TTF");

    // Game states
    this->_mainmenu_state = true;
    this->_game_state = false;
    this->_pause_state = false;

    


    this->initTextures();
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
}

void Game::initWindow()
{
    this->videoMode.width = 1200;
    this->videoMode.height = 700;
    // this->videoMode.getDesktopMode() future possible implementation
    this->window = new sf::RenderWindow(this->videoMode,  "War of Age Game");

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




void Game::initMainMenu()
{
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
    this->btn_menu = Button("Game loop, press to menu", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, this->defaultFont, sf::Color::Black);
    this->btn_menu.setPosition({100, 100});
    this->btn_menu.setFont(this->defaultFont);


    this->cntr = 0; // test var
}

void Game::initUIbtns()
{
    BasicUnit Btn = BasicUnit(this->T_castle, sf::Vector2f(1.f, 1.f), 50.f, 50.f, 50.f, "Unit", 10.f, 0.f);
    Btn.update_S(25.f, 25.f);
}

// Constructor / Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initMainMenu();
    this->initEnemies_S();

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
    if ((this->playerSpawnTimer < this->playerSpawnTimerMax) && (!this->_mainmenu_state))
        this->playerSpawnTimer += 1.f;
    else
    {
        if((this->PlayerUnits.size() < this->max_PlayerUnits) && (this->playerSpawnQueueNum > 0))
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

                if (_mainmenu_state){
                if (this->btn_start.isMouseOver(*this->window)) {
                    this->btn_start.setBackColor(sf::Color::White);
                    std::cout<<"White\n";
                }
                else {
                    this->btn_start.setBackColor(sf::Color::Red);
                }

                if (this->btn_settings.isMouseOver(*this->window)) {
                    this->btn_settings.setBackColor(sf::Color::White);
                    std::cout<<"White\n";
                }
                else {
                    this->btn_settings.setBackColor(sf::Color::Red);
                }

                if (this->btn_exit.isMouseOver(*this->window)) {
                    this->btn_exit.setBackColor(sf::Color::White);
                    std::cout<<"White\n";
                }
                else {
                    this->btn_exit.setBackColor(sf::Color::Red);
                }
                }

                // temp game loop
                if (_game_state){
                    if (this->btn_menu.isMouseOver(*this->window)) {
                        this->btn_menu.setBackColor(sf::Color::White);
                        std::cout<<"White\n";
                    }
                    else {
                        this->btn_menu.setBackColor(sf::Color::Red);
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
                //         main_menu.get_Btn(i).setBackColor(sf::Color::Green);
                //         }
                // }

                if (this->ev.mouseButton.button == sf::Mouse::Left){

                    if (this->_mainmenu_state){

                    if (this->btn_start.isMouseOver(*this->window)) {
                        std::cout<<this->cntr<<" Start\n";
                        this->cntr+=1;
                        this->btn_start.setBackColor(sf::Color::Green);
                        this->_mainmenu_state = false;
                        this->_game_state = true;
                        }

                    if (btn_settings.isMouseOver(*this->window)) {
                        std::cout<<this->cntr<<" Settings\n";
                        this->cntr+=1;
                        this->btn_settings.setBackColor(sf::Color::Green);
                        }

                    if (this->btn_exit.isMouseOver(*this->window)) {
                        this->window->close();
                        }
                    }

                    // temp game states
                    if ((this->_game_state) && (this->btn_menu.isMouseOver(*this->window)))
                    {
                        this->_game_state=false;
                        this->_mainmenu_state=true;
                    }



                    if((this->ev.mouseButton.button == sf::Mouse::Left) && (this->playerSpawnQueueNum < this->playerSpawnQueueNumMax) && (!this->_mainmenu_state))
                        this->playerSpawnQueueNum += 1;
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
        this->spawnEnemyUnits_S();
        this->spawnPlayerUnit_S();

        this->enemyUnitsUpdate_S();
        this->playerUnitsUpdate_S();
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
    if(this->_mainmenu_state)
    {
        this->btn_start.render(this->window);
        this->btn_settings.render(this->window);
        // this->btn_menu.render(this->window);
        this->btn_exit.render(this->window);
        std::cout<<"Menu Rendered!!!\n";
        this->btn_start.printPos();

    }


    // Game render
    if(this->_game_state)
    {
        // PlayerBase.render(this->window);
        // EnemyBase.render(this->window);

        // sf::Texture grass;
        // if (!grass.loadFromFile("../Resource_Files/Textures/Dirt.png")) {
        //     std::cout<<"Loading base texture failed!!!";
        // }

        //Game Background
        // Variables
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

        for(auto &i : this->Grass)
        {
            this->window->draw(i);
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
        this->window->draw(this->Sky);
        


        // UI
        float StoneHUD_sizeX = this->videoMode.width;
        float StoneHUD_sizeY = 100.f;

        sf::Texture stoneHUD;
        if (!stoneHUD.loadFromFile("../Resource_Files/Textures/StoneHUD.png")) {
            std::cout<<"Loading base texture failed!!!";
        }

        if(StoneHUD_sizeX != (stoneHUD).getSize().x)
        {
            scaleFactor_x = StoneHUD_sizeX / stoneHUD.getSize().x;
            scaleFactor_y = StoneHUD_sizeY / stoneHUD.getSize().y;
        }
        // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
        if(scaleFactor_x == 0) {scaleFactor_x = 1;}
        if(scaleFactor_y == 0) {scaleFactor_y = 1;}
        // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
        // std::cout<<"Dirt: "<<stoneHUD.getSize().x<<"   "<<stoneHUD.getSize().y<<"\n";

        this->StoneHUD = sf::Sprite(stoneHUD);
        this->StoneHUD.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
        this->window->draw(this->StoneHUD);

        //Player's Unit spawn spawn bar
        float SpawnBar_sizeX = 400.f;
        float SpawnBar_sizeY = 20.f;

        sf::Texture spawnbar;
        if (!spawnbar.loadFromFile("../Resource_Files/Textures/loading_bar.png")) {
            std::cout<<"Loading base texture failed!!!";
        }

        if(SpawnBar_sizeX != (spawnbar).getSize().x)
        {
            scaleFactor_x = SpawnBar_sizeX / spawnbar.getSize().x;
            scaleFactor_y = SpawnBar_sizeY / spawnbar.getSize().y;
        }
        // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
        if(scaleFactor_x == 0) {scaleFactor_x = 1;}
        if(scaleFactor_y == 0) {scaleFactor_y = 1;}
        // std::cout<<"GrassScale: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
        // std::cout<<"Dirt: "<<spawnbar.getSize().x<<"   "<<spawnbar.getSize().y<<"\n";

        this->SpawnBar = sf::Sprite(spawnbar);
        this->SpawnBar.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
        this->SpawnBar.setPosition(this->videoMode.width/2 - SpawnBar_sizeX/2, StoneHUD_sizeY);
        this->window->draw(this->SpawnBar);

        float RedBar_sizeX = SpawnBar_sizeX - 40.f;
        float RedBar_sizeY = SpawnBar_sizeY - 6.f;

        this->RedBar.setSize(sf::Vector2f(RedBar_sizeX, RedBar_sizeY));
        this->RedBar.setFillColor(sf::Color::Red);
        this->RedBar.setPosition(this->videoMode.width/2 - RedBar_sizeX/2, StoneHUD_sizeY + 3.f);
        this->RedBar.setSize(sf::Vector2f(RedBar_sizeX - (this->playerSpawnTimer/this->spawnTimerMax * 2.f * RedBar_sizeX) , RedBar_sizeY));
        this->window->draw(this->RedBar);

        //UI Btns
        
        // this->initUIbtns();
        // this->btn_spwn_Knight.setTexture(T_unit1);
        // this->btn_spwn_Knight.setScale(50.f/T_unit1.getSize().x, 50.f/T_unit1.getSize().y);
        // this->window->draw(this->btn_spwn_Knight);





        // Sprites
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


        sf::Texture texture;
        if (!texture.loadFromFile("../Resource_Files/Textures/castle.png")) {
            // Handle the error if the texture fails to load
            std::cout<<"Loading base texture failed!!!";
        }
        // else{std::cout<<"Loading base texture succeded!!!";}

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
            this->PlayerUnits.erase(this->PlayerUnits.begin() + i);

        for (int j = 0; j < this->EnemyUnits.size(); j++)
        {
            if(this->PlayerUnits[i].getSprite().getGlobalBounds().intersects(this->EnemyUnits[j].getSprite().getGlobalBounds()))
            {
                this->PlayerUnits.erase(this->PlayerUnits.begin() + i);
                this->EnemyUnits.erase(this->EnemyUnits.begin() + j);
                //Troubleshooting
                std::cout<<"Units Collision DETECTED! ! !                      *"<<"\n";
            }
        }


    }
}

// Game mechanics
