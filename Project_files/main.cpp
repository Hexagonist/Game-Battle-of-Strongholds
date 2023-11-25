// before debuger: 
#include <SFML/Graphics.hpp>
#include "Header Files\Button.h"

int main()
{
    //variables
    unsigned int window_height = 900, window_width = 900;

    // window 
    // to implement:    (sf::VideoMode::getDesktopMode().width / 2), (sf::VideoMode::getDesktopMode().height / 2)

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    sf::RenderWindow window(sf::VideoMode(window_height, window_width),  "War of Age Game");
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Font arial;
    if (!arial.loadFromFile("ARIAL.TTF")) {
        // Handle font loading error
        return EXIT_FAILURE;
    }
    arial.loadFromFile("ARIAL.TTF");

    unsigned int btn1_width = 200, btn1_height = 50;
    Button btn1("Start", {btn1_width, btn1_height}, 20, sf::Color::Red, sf::Color::Black);
    // std::cout<<btn1.get_Size().x;
    btn1.setPosition({static_cast<unsigned int>(window_width / 2) - btn1_width / 2, static_cast<unsigned int>(window_height / 2) - btn1_height / 2});  // Warning 
    btn1.setFont(arial);
    int cntr = 0;


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

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if (btn1.isMouseOver(window)) {
                    std::cout<<cntr<<" Start\n";
                    cntr+=1;
                    }
            }
        }

        window.clear();
        btn1.drawTo(window);
        // window.draw(shape); // Basic Circle example
        window.display();
    }

    return 0;
}