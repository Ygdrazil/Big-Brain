#ifndef LEVELCREATOR_H
#define LEVELCREATOR_H
#include "LevelManager.hpp"

class LevelCreator
{
    public:
        LevelCreator(int tileMap[30][17]);
        void playLevel();
        void addObject();
        virtual ~LevelCreator();
    private:
        LevelManager lm;
};

#endif // LEVELCREATOR_H
