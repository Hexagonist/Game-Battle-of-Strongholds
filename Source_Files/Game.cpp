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

// Sprite
void Game::initBase_S()
{
    float scale = 1.0f; 
    float BaseWidth = 100.f, BaseHeight = 100.f;
    float GrassBelt = 50.f;
    
    // Texture init
    sf::Texture texture;
    if (!texture.loadFromFile("../Resource_Files/Textures/castle.png")) {
        // Handle the error if the texture fails to load
        std::cout<<"Loading base texture failed!!!";
    }
    else{std::cout<<"Loading base texture succeded!!!";}

    this->PlayerBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Player", texture, &this->videoMode);
    this->EnemyBase = Stronghold(scale, BaseWidth, BaseHeight, GrassBelt, "Enemy", texture, &this->videoMode);
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


// Constructor / Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initMainMenu();
    this->initEnemies();

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



                    if((this->ev.mouseButton.button == sf::Mouse::Left) && (this->playerSpawnQueueNum < this->playerSpawnQueueNumMax))  
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
        this->spawnEnemyUnits();
        this->spawnPlayerUnit();

        this->enemyUnitsUpdate();
        this->playerUnitsUpdate();
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
        this->btn_menu.render(this->window);
        this->btn_exit.render(this->window);
        std::cout<<"Menu Rendered!!!\n";
        this->btn_start.printPos();

    }


    // Game render
    if(this->_game_state)
    {

        
        // PlayerBase.render(this->window);
        // EnemyBase.render(this->window);

        // Sprite
        PlayerBase.render_S(this->window);
        EnemyBase.render_S(this->window);

        sf::Texture texture;
        if (!texture.loadFromFile("../Resource_Files/Textures/castle.png")) {
            // Handle the error if the texture fails to load
            std::cout<<"Loading base texture failed!!!";
        }
        else{std::cout<<"Loading base texture succeded!!!";}
        
        // Test
        sf::Sprite test;
        test.setTexture(texture);
        float scaleFactor_x = 100.f / texture.getSize().x;
        float scaleFactor_y = 100.f / texture.getSize().y;
        // test.setTextureRect(sf::IntRect(100, 100, 100, 100));
        test.setScale(1*scaleFactor_x, 1*scaleFactor_y);
        test.setPosition(100, 100);
        this->window->draw(test);
        

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
