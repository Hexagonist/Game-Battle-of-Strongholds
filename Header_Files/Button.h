#include <iostream>
#include <SFML/Graphics.hpp>


class Button {

private:
sf::RectangleShape button;
sf::Text text;

public:
    Button() {}

    Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
        text.setString(t);
        text.setColor(textColor);
        text.setCharacterSize(charSize); 

        button.setSize(size);
        button.setFillColor(bgColor);

    }

    // Mozliwy problem bo bez importu nowej czcionki w main.cpp
    void setFont(sf::Font &font) {
        text.setFont(font);
    }

    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }

    void setTextColor(sf::Color color) {
        text.setColor(color);
    }

    void setPosition(sf::Vector2f pos) {
        button.setPosition(pos);

        std::cout<<text.getGlobalBounds().height;
        float xPos = (pos.x + button.getGlobalBounds().width / 2 );//- (text.getGlobalBounds().width / 2));
        float yPos = (pos.y + button.getGlobalBounds().height / 2 - (text.getGlobalBounds().height / 2));       // couldn't get text height (always =0)
        text.setPosition({xPos, yPos});
    }

    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text); 
        std::cout<<"Button 1 Drawed\n";
    }

    bool isMouseOver(sf::RenderWindow &window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if(mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;
    }

    // sf::Vector2f get_Size(){
    //     return button.getSize();
    // }


};  