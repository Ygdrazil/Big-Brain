#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Player : public GameObject
{
    public:
        Player();
        void updateInput();
        virtual ~Player();
        void checkCollision(GameObject other);
        void update();
        bool isGrounded;
        int mort;
        bool getVictory();
        void setVictory(bool state);

    private:
        void Move(sf::Vector2f velocity);
        sf::Vector2f velocityPerso();
        bool isJumping;
        bool isVictorious;
        bool isCogne;
        float gravite;
};

#endif // PLAYER_H
