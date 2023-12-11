#include "../Header_Files/SwagBall.h"

void SwagBall::initShape()
{
    this->shape.setRadius(100.f);
    
    this->shape.setFillColor(sf::Color::Blue);
}

SwagBall::SwagBall()
{
    this->initShape();
}

SwagBall::~SwagBall()
{
}

void SwagBall::update()
{
}

void SwagBall::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

sf::CircleShape SwagBall::getCircle()
{
    return this->shape;
}
