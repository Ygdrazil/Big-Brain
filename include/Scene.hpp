#ifndef SCENE_H
#define SCENE_H
#include "GameObject.hpp"

class Scene
{
    public:
        Scene();
        Scene(int map[30][17]);
        int getSceneMap();
        void addObject(int texId, int posX, int posY, bool isHurting, bool isSolid, bool isTrigger, AssetManager am);
        GameObject getObject(int i);
        int getObjectCount();
        virtual ~Scene();
        int sceneMap[30][17];
        GameObject objectList[20];
        int objectCount;

    private:
};

#endif // SCENE_H
