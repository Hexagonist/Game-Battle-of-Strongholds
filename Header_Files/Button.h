#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Button {

private:
sf::RectangleShape button;
sf::Text text;

public:
    // Button() {}
    Button();
    Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Font &font, sf::Color textColor);
    ~Button();

    // Mozliwy problem bo bez importu nowej czcionki w main.cpp
    void setFont(sf::Font &font);
    void setBackColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    void drawTo(sf::RenderWindow &window); // To delete
    void render(sf::RenderTarget* target);
    bool isMouseOver(sf::RenderWindow &window);
    void printPos();


};  

