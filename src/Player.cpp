#include "../include/Player.hpp"
#include <stdlib.h>

Player::Player()
{
    this->gravite = -15.0f;
    this->isJumping=0;
    this->isGrounded=0;
    this->isCogne=0;
    this->mort = 0;
    this->isVictorious = false;
}

Player::~Player()
{
    //dtor
}

void Player::Move(sf::Vector2f velocity)
{
    this->sprite.move(velocity);
}

void Player::checkCollision(GameObject other)
{
    if(other.getProps("solid") ||other.getProps("trigger"))
    {
        sf::Vector2f posJoueur(this->sprite.getPosition());
        sf::Vector2f posObstacle(other.sprite.getPosition());
        sf::Vector2f moitieJoueur((this->sprite.getTexture()->getSize().x * this->sprite.getScale().x)/2, (this->sprite.getTexture()->getSize().y) * this->sprite.getScale().y/2);
        sf::Vector2f moitieObstacle((other.sprite.getTexture()->getSize().x * other.sprite.getScale().x)/2, (other.sprite.getTexture()->getSize().y) * other.sprite.getScale().y/2);
        sf::Vector2f delta(posObstacle.x-posJoueur.x, posObstacle.y-posJoueur.y);
        float dx = abs(delta.x) - (moitieJoueur.x+moitieObstacle.x);
        float dy = abs(delta.y) - (moitieJoueur.y+moitieObstacle.y);


            if(dx<0 && dy< 0){
                if(other.getProps("solid"))
                {
                    if(dx<dy){
                        if(delta.y >= 0)
                        {
                            this->setPos(posJoueur.x, posObstacle.y-moitieJoueur.y-moitieObstacle.y);
                            this->isJumping = 0;
                            this->isGrounded = 1;
                        }
                        else{
                            this->setPos(posJoueur.x, posObstacle.y+moitieJoueur.y+moitieObstacle.y);
                            this->isCogne = 1;
                        }

                    }
                    else{
                        if(delta.x>=0)
                        {
                            this->setPos(posObstacle.x-moitieJoueur.x-moitieObstacle.x, posJoueur.y);
                        }
                        else{
                            this->setPos(posObstacle.x+moitieJoueur.x+moitieObstacle.x, posJoueur.y);
                        }
                    }
                    if(other.getProps("hurting")){
                        this->mort = 1;
                    }
                }
            else if(other.getProps("trigger"))
            {
                this->isVictorious = other.setTrigger(true);
            }
        }
    }
}

sf::Vector2f Player::velocityPerso(){
    sf::Vector2f velocite;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocite.x+=10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocite.x+=-10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        if(!this->isJumping && this->isGrounded)
        {
            this->gravite = -15;
            this->isGrounded = 0;
            this->isJumping = 1;
        }


    velocite.y += this->gravite;
    this->gravite += 0.5;
    if(this->isGrounded || this->isCogne)
    {
        velocite.y = 0;
        this->gravite = 0;
        this->isCogne = 0;
    }
    return velocite;
}

void Player::update()
{
    sf::Vector2f velocity = velocityPerso();
    this->Move(velocity);
}

bool Player::getVictory()
{
    return isVictorious;
}

void Player::setVictory(bool state)
{
    this->isVictorious = state;
}
