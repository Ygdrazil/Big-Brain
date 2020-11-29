#ifndef LEVEL_H
#define LEVEL_H
#include "Scene.hpp"
#include "../include/Level.hpp"
#include "../include/AssetManager.hpp"
#include "../include/GameObject.hpp"
#include "../include/Player.hpp"

class LevelManager
{
    public:
        LevelManager();
        void loadLevel(Scene scene, AssetManager am, int *gameVictory);
        void update(sf::RenderWindow& fen, float deltaTime, Scene scene);
        void resetObjects(Scene *scene);
        virtual ~LevelManager();
        Player player;
    private:
        int objetCount = 0;
        //AssetManager am;
        GameObject tileMap[30][17];
};



#endif // LEVEL_H
