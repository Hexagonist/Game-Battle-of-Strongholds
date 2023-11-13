#include <SFML/Graphics.hpp>

#include "Header Files\Button.h"

int main()
{
    // window 
    // to implement:    (sf::VideoMode::getDesktopMode().width / 2), (sf::VideoMode::getDesktopMode().height / 2)

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    sf::RenderWindow window(sf::VideoMode(900, 900),  "War of Age Game");
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Button btn1("Start", {200, 50}, 20, sf::Color::Red, sf::Color::Black);
    btn1.setPosition({100, 300});
    //btn1.setFont(arial);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // event closing window after Event::Closed triggered
            if (event.type == sf::Event::Closed)    window.close();

            // button 1 's reactions to mouse
            if (event.type == sf::Event::MouseMoved) {
                if (btn1.isMouseOver(window)) {
                    btn1.setBackColor(sf::Color::White);
                }
                else {
                    btn1.setBackColor(sf::Color::Red);
                }
            }
        }

        window.clear();
        btn1.drawTo(window);
        window.draw(shape);
        window.display();
    }

    return 0;
}