#include "SFML/Graphics.hpp"
#include "../include/Scene.hpp"

Scene::Scene() : objectCount(0)
{

}

Scene::Scene(int map[30][17])
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<17; j++)
        {
            this->sceneMap[i][j] = map[i][j];
        }
    }
}

void Scene::addObject(int texId, int posX, int posY, bool isHurting, bool isSolid, bool isTrigger, AssetManager am)
{
    am.loadTex(&(this->objectList[this->objectCount].sprite), texId);
    this->objectList[this->objectCount].setPos(posX, posY);
    this->objectList[this->objectCount].setProperties(isHurting, isSolid, isTrigger);
    this->objectCount++;
}

int Scene::getObjectCount()
{
    return this->objectCount;
}

GameObject Scene::getObject(int i)
{
    return this->objectList[i];
}

Scene::~Scene()
{
    //dtor
}
