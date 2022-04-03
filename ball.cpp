#include "ball.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using std::sqrt;
using namespace std;


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
        acelY = 9.8/144;
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
    for (int i = index+1; i < size; i++)
    {
        if (i != index)
        {
            float center1_x = circle.getPosition().x + circle.getRadius();
            float center1_y = circle.getPosition().y + circle.getRadius();
            float center2_x = balls[i].circle.getPosition().x + balls[i].circle.getRadius();
            float center2_y = balls[i].circle.getPosition().y + balls[i].circle.getRadius();
            float distance = sqrt((center1_x-center2_x)*(center1_x-center2_x) + (center1_y-center2_y)*(center1_y-center2_y));
            if (distance <= circle.getRadius() + balls[i].circle.getRadius()){
                float radsVector[2] = {center2_x-center1_x,center2_y-center1_y};
                // Here i separate the circles to not be together
                float errorToCorrect = (distance - (circle.getRadius() + balls[i].circle.getRadius()))/2;
                float uRadsVector[2] = {radsVector[0]/distance,radsVector[1]/distance};
                balls[i].circle.move(-uRadsVector[0]*errorToCorrect,-uRadsVector[1]*errorToCorrect);
                circle.move(uRadsVector[0]*errorToCorrect,uRadsVector[1]*errorToCorrect);


                // I update de rad vector
                center1_x = circle.getPosition().x + circle.getRadius();
                center1_y = circle.getPosition().y + circle.getRadius();
                center2_x = balls[i].circle.getPosition().x + balls[i].circle.getRadius();
                center2_y = balls[i].circle.getPosition().y + balls[i].circle.getRadius();
                radsVector[0] = center2_x-center1_x;
                radsVector[1] = center2_y-center1_y;
                
                // Here I calculate the new velocities
                float vel1_vect[2] = {velX,velY};
                float vel2_vect[2] = {balls[i].velX,balls[i].velY};
                // I calculate the projection on the vector joining the centers 
                float proj = dot2DProduct(vel1_vect,radsVector)/dot2DProduct(radsVector,radsVector);
                balls[i].velX += proj*radsVector[0];
                balls[i].velY += proj*radsVector[1];
                velX -= proj*radsVector[0];
                velY -= proj*radsVector[1];

                float inverseRadVector[2]={-radsVector[0],-radsVector[1]};
                float proj2 = dot2DProduct(vel2_vect,inverseRadVector)/dot2DProduct(inverseRadVector,inverseRadVector);
                balls[i].velX -= proj2*inverseRadVector[0];
                balls[i].velY -= proj2*inverseRadVector[1];
                velX += proj2*inverseRadVector[0];
                velY += proj2*inverseRadVector[1];
            }  
        } 
    }
    
}

float ball::dot2DProduct(float vect1[2], float vect2[2]){
    return vect1[0]*vect2[0] + vect1[1]*vect2[1];
}