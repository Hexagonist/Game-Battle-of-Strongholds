#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// #include <map> //for textures for sprites

class BasicUnit
{
private:
    float BasicWidth;
    float BasicHeight;
    float GrassBelt;
    float health, speed;
    sf::Vector2f scale;
    sf::Color FillColor;
    sf::RectangleShape Unit;
    std::string name;

    // Sprite
    sf::Sprite Unit_S;
    sf::Texture texture;

    // Game mechanics

    // Private Functions
    void init();
    void init_S();

    
public:
    // BasicUnit();
    BasicUnit(sf::Vector2f scale, float BasicWidth, float BasicHeight, float GrassBelt, std::string name, sf::Color FillColor, float health, float speed);
    BasicUnit(sf::Texture texture, sf::Vector2f scale, float BasicWidth, float BasicHeight, float GrassBelt, std::string name, float health, float speed);
    ~BasicUnit();
    void render(sf::RenderTarget* target);
    void render(sf::Texture texture,sf::RenderTarget* target);
    void update(float posX, float posY);
    void update_S(float posX, float posY);
    float get_width();
    sf::RectangleShape getRect();
    sf::FloatRect getBounds();
    sf::Sprite getSprite();
    void move();
    void move_S();

};
