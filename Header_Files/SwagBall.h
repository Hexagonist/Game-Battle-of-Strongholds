#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class SwagBall
{
private:
    sf::CircleShape shape;

    void initShape();
public:
    SwagBall();
    ~SwagBall();

    void update();
    void render(sf::RenderTarget* target);
    sf::CircleShape getCircle();

};

