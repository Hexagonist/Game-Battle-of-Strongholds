#include <iostream>
#include "../Header_Files/Game.h"
#include "Game.cpp"


// void button_set(Button *btn, unsigned int window_width, unsigned int window_height, unsigned int btn_width, 
// unsigned int btn_height, sf::Font font){
//     btn->setPosition({static_cast<unsigned int>(window_width / 2) - btn_width / 2, static_cast<unsigned int>(window_height / 2) - btn_height / 2});  // Warning 
//     btn->setFont(font);
//     // btn->
// } 


int main()
{
    // Init Game engine
    Game game;


    /*Here it was [==]*/

    // Main loop
    while (game.running())
    {
        std::cout<<"start!!\n";

        //Update
        game.update();

        //Render
        game.render();

        // Cutted main game loop



        // // Menu.h issue
        // // main_menu.draw(window);
        // if (_mainmenu_state)
        // {
        //     btn_start.drawTo(window);
        //     btn_settings.drawTo(window);
        //     btn_exit.drawTo(window);
        // }
        // // temp game states
        // if (_game_state) {btn_menu.drawTo(window);}
    }

    return 0;
}









    /* [==]
    // Game state variables
    bool _game_state = false, _mainmenu_state = true, _pause_state = false;

    //variables
    unsigned int window_width = 1280, window_height = 720;

    //window
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // Font implementation
    sf::Font arial;
    if (!arial.loadFromFile("../Resource_Files/ARIAL.TTF")) {
        // Handle font loading error
        return EXIT_FAILURE;
    }
    arial.loadFromFile("../Resource_Files/ARIAL.TTF");

    // Just temp text for game loop
    sf::Text game_text;
    game_text.setFont(arial);
    game_text.setString("Game loop");
    game_text.setPosition(window_width/2, window_height/2);
    game_text.setColor(sf::Color::Magenta);


    float menu_btns_mod = -1; // Menu buttons y pos modificator 
    // Start Button (text, {width, height}, font_size, button_background_color, text_color)
    unsigned int btn_start_width = 200, btn_start_height = 50, font_size = 20;
    // Main.h issue
    // std::string main_menu_btns_names[3] = {"Start", "Options", "Exit"};
    // Menu main_menu(3, main_menu_btns_names, window_width, window_height, arial);

    Button btn_start("Start", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, sf::Color::Black);

    // std::cout<<btn1.get_Size().x;
    // button_set(&btn_start, window_width, window_height, btn_start_width, btn_start_height, arial);

    btn_start.setPosition({static_cast<unsigned int>(window_width / 2) - btn_start_width / 2, static_cast<unsigned int>(window_height / 2) + menu_btns_mod*btn_start_height});  // Warning 
    btn_start.setFont(arial);
    menu_btns_mod+=1.5;

    Button btn_settings("Settings", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, sf::Color::Black);
    btn_settings.setPosition({static_cast<unsigned int>(window_width / 2) - btn_start_width / 2, static_cast<unsigned int>(window_height / 2) + menu_btns_mod*btn_start_height});  // Warning 
    btn_settings.setFont(arial);
    menu_btns_mod+=1.5;

    Button btn_exit("Exit", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, sf::Color::Black);
    btn_exit.setPosition({static_cast<unsigned int>(window_width / 2) - btn_start_width / 2, static_cast<unsigned int>(window_height / 2) + menu_btns_mod*btn_start_height});  // Warning 
    btn_exit.setFont(arial);

    // temp game loop
    Button btn_menu("Game loop, press to menu", {btn_start_width, btn_start_height}, font_size, sf::Color::Red, sf::Color::Black);
    btn_menu.setPosition({100, 100}); 
    btn_menu.setFont(arial);




    int cntr = 0; // test var


    */