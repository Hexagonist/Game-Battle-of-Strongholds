#include "BasicUnit.h"


// Private functions
void BasicUnit::init()
{
    this->Unit.setSize(sf::Vector2f(this->BasicWidth, this->BasicHeight));
    this->Unit.setScale(sf::Vector2f(this->scale, this->scale));
    this->Unit.setFillColor(this->FillColor);
    this->Unit.setOutlineColor(sf::Color::Yellow);
    this->Unit.setOutlineThickness(1.f);

    // this->UnitRect = sf::FloatRect(10.f, 10.f, 50.f, 50.f);
    // std::cout<<this->BasicWidth<<"\n";
}



// Constructor & Destructor
// BasicUnit::BasicUnit()
// {
// }

BasicUnit::BasicUnit(float scale=1.f, float BasicWidth=50, float BasicHeight=50,
 float GrassBelt=50.f, std::string name=("Unit"), sf::Color FillColor=sf::Color::Blue, 
 float health=10.f, float speed=1.f)
{
    this->scale = scale;
    this->BasicWidth = BasicWidth;
    this->BasicHeight = BasicHeight;
    this->GrassBelt = GrassBelt;
    this->FillColor = FillColor;
    this->name = name;
    this->health = health;
    this->speed = speed;
    this->init();

    // this->Unit.setPosition(400, 700 - (this->GrassBelt) - this->BasicHeight);
    // if(this->FillColor == sf::Color::Blue)
    //     std::cout<<"Blue\n";
    // std::cout<<this->name<<"\n";
    // std::cout<<this->health<<" "<<this->speed<<" "<<this->scale<<" "<<this->GrassBelt<<"\n";
    // std::cout<<10.f<<"\n";
    
    // std::cout<<Unit.getPosition().x<<" "<<Unit.getPosition().y<<"\n";
    // std::cout<<this->Unit.getSize().x<<"size\n";

}


BasicUnit::~BasicUnit()
{
}


// Public functions

void BasicUnit::update(float posX, float posY)
{
    this->Unit.setPosition(posX, posY - this->GrassBelt - this->BasicHeight);
}

float BasicUnit::get_width()
{
    return this->BasicWidth;
}

sf::RectangleShape BasicUnit::getRect()
{
    return this->Unit;
}

sf::FloatRect BasicUnit::getBounds()
{
    return this->Unit.getGlobalBounds();
}

void BasicUnit::render(sf::RenderTarget *target)
{
    target->draw(this->Unit);
    // std::cout<<"Unit drawed\n";
}


// Game mechanics
void BasicUnit::move()
{
    auto xPos = this->Unit.getPosition().x;
    // std::cout<<this->Unit.getPosition().x<<"PosxWczesniej\n";

    this->Unit.setPosition(xPos + this->speed, this->Unit.getPosition().y);
    // std::cout<<this->Unit.getPosition().x<<"Posx\n";
}