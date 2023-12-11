#include "Button.h"


// Constructor and Destructor

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Font &font, sf::Color textColor)
{
    this->text.setString(t);
    this->text.setColor(textColor);
    this->text.setCharacterSize(charSize); 

    this->button.setSize(size);
    this->button.setFillColor(bgColor);


    // Mozliwy problem bo bez importu nowej czcionki w main.cpp
    this->setFont(font);
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

    std::cout<<text.getGlobalBounds().height;
    float xPos = (pos.x + button.getGlobalBounds().width / 2 );//- (text.getGlobalBounds().width / 2));
    float yPos = (pos.y + button.getGlobalBounds().height / 2 - (text.getGlobalBounds().height / 2));       // couldn't get text height (always =0)
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
    std::cout<<"Button 1 Drawed\n";
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

