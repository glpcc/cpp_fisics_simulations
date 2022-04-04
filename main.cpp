#include "ball.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML", sf::Style::Default, settings);
    window.setFramerateLimit(144);
    int num_balls = 4;
    ball balls[] = {ball(200,200,30,1,0),ball(600,300,30,-1.5,0),ball(600,100,30,-1.5,-1),ball(100,300,30,-1.5,2)};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        for (int i = 0; i < num_balls; i++)
        {
            balls[i].testWalls();
            balls[i].testBallCollisions(balls,i,num_balls);
            balls[i].update(true);
            balls[i].draw(window);
        }
        window.display();
    }
    return 0;
} 