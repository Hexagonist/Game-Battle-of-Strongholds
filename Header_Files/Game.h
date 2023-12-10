#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  //Needed?
#include <SFML/Window.hpp>  //Needed?
#include <SFML/Audio.hpp>   //Needed?
#include <SFML/Network.hpp> //Needed?
#include <string>

#include "../Header_Files/Stronghold.h"



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
    Stronghold PlayerBase;
    Stronghold EnemyBase;

    


    // Private Functions
    void initVariables();
    void initWindow();
    void initEnemies();
    void initBase();

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
};


