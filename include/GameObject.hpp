#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

class GameObject
{
    public:
        GameObject();
        GameObject(AssetManager am, int texId, int xPos, int yPos);
        GameObject& operator=(const GameObject&);
        void drawObject(sf::RenderWindow& fen);
        void setProperties(bool isHurting, bool isSolid, bool isTrigger);
        void setPos(int xPos, int yPos);
        bool getProps(std::string prop);
        virtual ~GameObject();
        sf::Sprite sprite;
        bool setTrigger(bool state);

    private:
        //bool isVisible;
        bool isHurting;
        bool isSolid;
        bool isTrigger;
};

#endif // GAMEOBJECT_H
