#include "ball.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML", sf::Style::Default, settings);
    ball ball1(200,100,20,0.1,0.1);
    ball ball2(100,200,20,-0.1,0.1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        ball1.testWalls();
        ball1.update(false);
        ball1.draw(window);
        window.display();
    }
    return 0;
}