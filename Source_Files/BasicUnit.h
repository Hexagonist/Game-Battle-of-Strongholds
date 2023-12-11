#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// #include <map> //for textures for sprites

class BasicUnit
{
private:
    float scale;
    float BasicWidth;
    float BasicHeight;
    float GrassBelt;
    float health, speed;
    sf::Color FillColor;
    sf::RectangleShape Unit;
    std::string name;

    // Game mechanics

    // Private Functions
    void init();

    
public:
    // BasicUnit();
    BasicUnit(float scale, float BasicWidth, float BasicHeight, float GrassBelt, std::string name, sf::Color FillColor, float health, float speed);
    ~BasicUnit();
    void render(sf::RenderTarget* target);
    void update(float posX, float posY);
    float get_width();
    sf::RectangleShape getRect();
    sf::FloatRect getBounds();
    void move();

};
