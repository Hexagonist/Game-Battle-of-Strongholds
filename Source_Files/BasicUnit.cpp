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

void BasicUnit::init_S()
{
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

BasicUnit::BasicUnit(sf::Texture texture, float scale=1.f, float BasicWidth=50, float BasicHeight=50,
 float GrassBelt=50.f, std::string name=("Unit"), float health=10.f, float speed=1.f)
{
    this->scale = scale;
    this->BasicWidth = BasicWidth;
    this->BasicHeight = BasicHeight;
    this->GrassBelt = GrassBelt;
    this->name = name;
    this->health = health;
    this->speed = speed;

    this->texture = texture;
    // Only not to get undefined behaviour
    sf::Texture unit1_T;
    if (!unit1_T.loadFromFile("../Resource_Files/Textures/Dirt.png")) {
        // Handle the error if the texture fails to load
        std::cout<<"Loading base texture failed!!!";
    }
    this->texture = unit1_T;
    
    this->init_S();
}

BasicUnit::~BasicUnit()
{
}


// Public functions

void BasicUnit::update(float posX, float posY)
{
    this->Unit.setPosition(posX, posY - this->GrassBelt - this->BasicHeight);
}

void BasicUnit::update_S(float posX, float posY)
{
    this->Unit_S.setPosition(posX, posY - this->GrassBelt - this->BasicHeight);
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

sf::Sprite BasicUnit::getSprite()
{
    return this->Unit_S;
}

void BasicUnit::render(sf::RenderTarget *target)
{
    target->draw(this->Unit);
    // std::cout<<"Unit drawed\n";
}

void BasicUnit::render(sf::Texture texture, sf::RenderTarget *target)
{
    this->Unit_S.setTexture(texture);

    // Scale
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    if(this->BasicWidth != (texture).getSize().x)
    {
        scaleFactor_x = this->BasicWidth / texture.getSize().x;
        scaleFactor_y = this->BasicHeight / texture.getSize().y;
    }
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}
    // Troubleshooting
    // std::cout<<"ScaleFactor: "<<scaleFactor_x<<"   "<<scaleFactor_y<<"\n";
    // std::cout<<"Scale: "<<this->scale<<"\n";
    // std::cout<<"Size: "<<this->BasicWidth<<"  "<<this->BasicHeight<<"\n";
    

    this->Unit_S.setScale(sf::Vector2f(scale*scaleFactor_x, scale*scaleFactor_y));


    target->draw(this->Unit_S);
}

// Game mechanics
void BasicUnit::move()
{
    auto xPos = this->Unit.getPosition().x;
    // std::cout<<this->Unit.getPosition().x<<"PosxWczesniej\n";

    this->Unit.setPosition(xPos + this->speed, this->Unit.getPosition().y);
    // std::cout<<this->Unit.getPosition().x<<"Posx\n";
}

void BasicUnit::move_S()
{
    auto xPos = this->Unit_S.getPosition().x;
    //Troubleshooting
    // std::cout<<"Detected UPos:"<<this->Unit_S.getPosition().x<<"   "<<this->Unit_S.getPosition().y<<"\n";

    this->Unit_S.setPosition(xPos + this->speed, this->Unit_S.getPosition().y);
    // Troubleshooting
    std::cout<<"Unit_SPos: "<<this->Unit_S.getPosition().x<<"   "<<this->Unit_S.getPosition().x<<"\n";
}
