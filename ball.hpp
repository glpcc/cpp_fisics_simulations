#include <SFML/Graphics.hpp>

class ball
{
private:
    sf::CircleShape circle;
    float velX;
    float velY;
    float acelX;
    float acelY;
public:
    ball(float initX, float initY,int radious,float vX = 0, float vY = 0 , float aX = 0, float aY = 0);
    void draw(sf::RenderWindow&);
    void move(float,float);
    void update(bool gravity);
    void testWalls();
    void testBallCollisions(ball balls[],int index,int size);
};

