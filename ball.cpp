#include "ball.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using std::sqrt;

void ball::draw(sf::RenderWindow& window){
    window.draw(circle);
}

ball::ball(float initX, float initY,int radious,float vX , float vY , float aX , float aY ){
    circle = sf::CircleShape(radious);
    circle.setFillColor(sf::Color(200,100,50));
    circle.setPosition(initX,initY);
    velX = vX;
    velY = vY;
    acelX = aX;
    acelY = aY;
}

void ball::move(float movX, float movY){
    circle.move(movX,movY);
}

void ball::update(bool gravity){
    if (gravity){
        acelY = 9.8/1000000000;
    }
    velX += acelX;
    velY += acelY;
    move(velX,velY);
}

void ball::testWalls(){
    if (circle.getPosition().x + 2*circle.getRadius() >= 800 || circle.getPosition().x <= 0)
    {
        velX = -velX;
    }
    if (circle.getPosition().y + 2*circle.getRadius() >= 800 || circle.getPosition().y <= 0)
    {
        velY = -velY;
    }
}
void ball::testBallCollisions(ball balls[],int index,int size){
    for (int i = index; i < size; i++)
    {
        float center1_x = circle.getPosition().x + circle.getRadius();
        float center1_y = circle.getPosition().y + circle.getRadius();
        float center2_x = balls[i].circle.getPosition().x + balls[i].circle.getRadius();
        float center2_y = balls[i].circle.getPosition().y + balls[i].circle.getRadius();
        if (sqrt((center1_x-center2_x)*(center1_x-center2_x) + (center1_y-center2_y)*(center1_y-center2_y)) <= circle.getRadius() + balls[i].circle.getRadius()){
            radsVector = 
        }   
    }
    
}
