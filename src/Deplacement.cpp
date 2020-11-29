#include <SFML/Graphics.hpp>
#include "../include/Deplacement.hpp"

sf::Vector2f velocityPerso(float *gravite, int *isGrounded, int *isJumping, int *isCogne){
    sf::Vector2f velocite;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocite.x+=10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocite.x+=-10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        if(!*isJumping && *isGrounded)
        {
            *gravite = -15;
            *isGrounded = 0;
            *isJumping = 1;
        }


    velocite.y += *gravite;
    *gravite += 0.5;
    if(*isGrounded || *isCogne)
    {
        velocite.y = 0;
        *gravite = 0;
        *isCogne = 0;
    }
    return velocite;
}

void checkPosition(sf::RectangleShape *t3, sf::RectangleShape *test, int *isJumping, int *isGrounded, int *isCogne){
    sf::Vector2f posJoueur(test->getPosition());
    sf::Vector2f posObstacle(t3->getPosition());
    sf::Vector2f moitieJoueur(test->getSize().x/2,test->getSize().y/2);
    sf::Vector2f moitieObstacle(t3->getSize().x/2,t3->getSize().y/2);
    sf::Vector2f delta(posObstacle.x-posJoueur.x, posObstacle.y-posJoueur.y);
    float dx = abs(delta.x) - (moitieJoueur.x+moitieObstacle.x);
    float dy = abs(delta.y) - (moitieJoueur.y+moitieObstacle.y);

    if(dx<0 && dy< 0){

        if(dx<dy){
            if(delta.y >= 0)
            {

                test->setPosition(posJoueur.x, posObstacle.y-moitieJoueur.y-moitieObstacle.y);
                *isJumping = 0;
                *isGrounded = 1;
            }
            else{
                test->setPosition(posJoueur.x, posObstacle.y+moitieJoueur.y+moitieObstacle.y);
                *isCogne = 1;
            }

        }
        else{
            if(delta.x>=0)
            {
                test->setPosition(posObstacle.x-moitieJoueur.x-moitieObstacle.x, posJoueur.y);
            }
            else{
                test->setPosition(posObstacle.x+moitieJoueur.x+moitieObstacle.x, posJoueur.y);
            }
        }
    }
}
