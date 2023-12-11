#include "../Header_Files/Stronghold.h"
// #include "Stronghold.h"




// Private Functions

void Stronghold::init()
{
    

}

void Stronghold::update()
{
}


// Constructor & Destructor

Stronghold::Stronghold()
{
}

Stronghold::Stronghold(float scale, float BasicWidth, float BasicHeight, float GrassBelt, std::string name,  sf::Color FillColor, sf::VideoMode* videoMode)
{
    this->scale = scale;
    this->BasicWidth = BasicWidth;
    this->BasicHeight = BasicHeight;
    this->GrassBelt = GrassBelt;
    this->FillColor = FillColor;
    this->name = name;

    float posX = 0;
    if(this->name == "Player") posX = 0;
    else if(this->name == "Enemy") posX = videoMode->width - (BasicWidth*scale);


    this->Base.setPosition(posX, videoMode->height - (BasicHeight*scale) - GrassBelt*scale);
    this->Base.setSize(sf::Vector2f(BasicWidth, BasicHeight));
    this->Base.setScale(sf::Vector2f(scale, scale));
    this->Base.setFillColor(FillColor);
    this->Base.setOutlineColor(sf::Color::Yellow);
    this->Base.setOutlineThickness(1.f);
    
}

Stronghold::~Stronghold()
{
}


// Public functions
void Stronghold::render(sf::RenderTarget *target)
{
    target->draw(Base);
}

float Stronghold::getWidth()
{
    return this->BasicWidth;
}

float Stronghold::getHeight()
{
    return this->BasicHeight;
}

sf::FloatRect Stronghold::getBounds()
{
    return this->Base.getGlobalBounds();
}
