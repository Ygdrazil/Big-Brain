#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include "LevelManager.hpp"

class GameManager
{
    public:
        GameManager();
        void run();
        virtual ~GameManager();
    private:
        sf::RenderWindow game;
        sf::View view;
        AssetManager am;
        int gameState;
};



#endif // GAMEMANAGER_H
