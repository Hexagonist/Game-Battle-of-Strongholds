#pragma once

#include <SFML/Graphics.hpp>
#include <string>
// #include <map> //for textures for sprites

class Stronghold
{
private:
    float scale;
    float BaseWidth;
    float BaseHeight;
    float GrassBelt;
    sf::Color FillColor;
    sf::RectangleShape Base;
    std::string name;


    // Private Functions
    void init();
    void update();

    
public:
    Stronghold();
    Stronghold(float scale, float BaseWidth, float BaseHeight, float GrassBelt, std::string name, sf::Color FillColor, sf::VideoMode* videoMode);
    ~Stronghold();
    void render(sf::RenderTarget* target);
};
