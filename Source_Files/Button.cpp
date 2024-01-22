#include "../Header_Files/Button.h"


// Constructor and Destructor

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Font &font, sf::Color textColor)
{
    this->fontSize = charSize;
    this->text.setString(t);
    this->text.setColor(textColor);
    this->text.setCharacterSize(charSize); 

    this->button.setSize(size);
    this->button.setFillColor(bgColor);


    // Mozliwy problem bo bez importu nowej czcionki w main.cpp
    this->setFont(font);
}

Button::Button(std::string txt, sf::Vector2f size, int charSize, sf::Texture* texture, sf::Font &font, sf::Color textColor)
{
    this->text.setString(txt);
    this->text.setColor(textColor);
    this->text.setCharacterSize(charSize);
    // Mozliwy problem bo bez importu nowej czcionki w main.cpp
    this->setFont(font);

    // Background sprite
    float scaleFactor_x = 1;
    float scaleFactor_y = 1;
    // float Sky_sizeX = this->videoMode.width;
    // float Sky_sizeY = this->videoMode.height - 50.f;

    if((size.x != (*texture).getSize().x) || (size.y != (*texture).getSize().y))
    {
        scaleFactor_x = size.x / (*texture).getSize().x;
        scaleFactor_y = size.y / (*texture).getSize().y;
    }
    if(scaleFactor_x == 0) {scaleFactor_x = 1;}
    if(scaleFactor_y == 0) {scaleFactor_y = 1;}

    this->background = sf::Sprite(*texture);
    this->background.setScale(sf::Vector2f(scaleFactor_x, scaleFactor_y));
}

Button::Button()
{
}

Button::~Button()
{
}


// Public Functions

void Button::setFont(sf::Font &font)
{
    this->text.setFont(font);
}

void Button::setBackColor(sf::Color color)
{
    this->button.setFillColor(color);
}

void Button::setTextColor(sf::Color color)
{
    this->text.setColor(color);
}

void Button::setPosition(sf::Vector2f pos)
{
    this->button.setPosition(pos);

    // std::cout<<text.getGlobalBounds().height;
    float xPos = (pos.x + button.getGlobalBounds().width / 2 - this->text.getGlobalBounds().width/2);//- (text.getGlobalBounds().width / 2));
    float yPos = (pos.y + button.getGlobalBounds().height / 2 - this->fontSize/2);       // couldn't get text height (always =0)
    this->text.setPosition({xPos, yPos});
}

void Button::setPosition_S(sf::Vector2f pos)
{
    int text_offset = fontSize/2;
    this->background.setPosition(pos);

    // std::cout<<text.getGlobalBounds().height;
    float xPos = (pos.x + background.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2);
    float yPos = (pos.y + background.getGlobalBounds().height / 2 - (text.getGlobalBounds().height) - 5.f);       // couldn't get text height (always =0)
    this->text.setPosition({xPos, yPos});

}

void Button::drawTo(sf::RenderWindow &window)
{
    window.draw(button);
    window.draw(text); 
    std::cout<<"Button 1 Drawed\n";
}

void Button::render(sf::RenderTarget *target)
{
    target->draw(this->button);
    target->draw(this->text); 
    // std::cout<<"Button Rendered\n";
}

void Button::render_S(sf::RenderTarget *target)
{
    target->draw(this->background);
    target->draw(this->text); 
}

bool Button::isMouseOver(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = this->button.getPosition().x;
    float btnPosY = this->button.getPosition().y;

    float btnxPosWidth = this->button.getPosition().x + this->button.getLocalBounds().width;
    float btnyPosHeight = this->button.getPosition().y + this->button.getLocalBounds().height;

    if(mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
        return true;
    }
    return false;
}

bool Button::isMouseOver_S(sf::RenderWindow &window)
{
    // float mouseX = sf::Mouse::getPosition(window).x;
    // float mouseY = sf::Mouse::getPosition(window).y;
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

    return this->background.getGlobalBounds().contains(worldPos);
}

void Button::printPos()
{
    std::cout<<"Button x:"<<this->button.getPosition().x <<"Button y:"<< this->button.getPosition().y<<"\n";
}
