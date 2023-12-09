/*
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <string>
#include <vector>

#define MAX_NUMBER_OF_BUTTONS 5

class Menu
{

public:
    Menu(unsigned int btns_num, std::string btns_names[], unsigned int window_width, unsigned int window_height,  sf::Font &btns_font, sf::Vector2f btns_size={200, 50}, 
    unsigned int font_size=20, sf::Color btns_bgColor=sf::Color::Red, sf::Color btns_textColor=sf::Color::Black) // unsigned int btn_width=200, unsigned int btn_height=50,
    {
        for(int i=0; i<btns_num; i++)   {Btns_names[i] = btns_names[i];}
        // Btns_font = btns_font; 
        Btns_size = btns_size;

        // Building menu's buttons
        float menu_btns_mod = -1; // Menu buttons y pos modificator 
        // for (unsigned int i = 0; i < btns_num; i++)
        // {
        //     Btns[i] = Button(btns_names[i], btns_size, font_size, btns_bgColor, btns_textColor);
        //     Btns[i].setPosition({static_cast<unsigned int>(window_width / 2) - btns_size.x/ 2, static_cast<unsigned int>(window_height / 2) + menu_btns_mod*btns_size.y});  // Warning 
        //     Btns[i].setFont(btns_font);
        //     menu_btns_mod+=1.5;
        // }
        
        for (unsigned int i = 0; i < btns_num; i++)
        {
            Btns.push_back(Button(btns_names[i], btns_size, font_size, btns_bgColor, btns_textColor));
            Btns[i].setPosition({static_cast<unsigned int>(window_width / 2) - btns_size.x/ 2, static_cast<unsigned int>(window_height / 2) + menu_btns_mod*btns_size.y});  // Warning 
            Btns[i].setFont(btns_font);
            menu_btns_mod+=1.5;
        }


    }
    

    void draw(sf::RenderWindow &window)
    {
        for (unsigned int i = 0; i < Btns_num; i++)
        {
            Btns[i].drawTo(window);
        }
    }

    unsigned int get_Btns_num()
    {
        return Btns_num;
    }

    // Button get_Btn(int i)
    // {
    //     return Btns[i];
    // }

    bool isMouseOverBtn(int i, sf::RenderWindow &window)
    {
        if (Btns[i].isMouseOver(window)) {
            return true;
        }
        else {
            return false;
        }

    }

    void setBackColorBtn(int i, sf::Color color)
    {
        Btns[i].setBackColor(color);
    }

private:
    unsigned int Btns_num;
    std::string Btns_names[MAX_NUMBER_OF_BUTTONS];
    // sf::Font &Btns_font;
    sf::Vector2f Btns_size;

    // unsigned int btn_start_width, btn_start_height, font_size;
    std::vector<Button> Btns; //btn_start, btn_settings, btn_exit;
    // sf::Text text[MAX_NUMBER_OF_BUTTONS];
};

*/