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

Stronghold::Stronghold(float scale, float BaseWidth, float BaseHeight, float GrassBelt, std::string name,  sf::Color FillColor, sf::VideoMode* videoMode)
{
    this->scale = scale;
    this->BaseWidth = BaseWidth;
    this->BaseHeight = BaseHeight;
    this->GrassBelt = GrassBelt;
    this->FillColor = FillColor;
    this->name = name;

    float posX = 0;
    if(this->name == "Player") posX = 0;
    else if(this->name == "Enemy") posX = videoMode->width - (BaseWidth*scale);


    this->Base.setPosition(posX, videoMode->height - (BaseHeight*scale) - GrassBelt*scale);
    this->Base.setSize(sf::Vector2f(BaseWidth, BaseHeight));
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