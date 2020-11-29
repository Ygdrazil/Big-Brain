#include "../include/GameObject.hpp"

GameObject::GameObject()
{
    this->sprite.setScale(2,2);
}

GameObject::GameObject(AssetManager am, int texId, int x, int y)
{
    am.loadTex(&(this->sprite), texId);
    this->sprite.setPosition(x, y);
}

GameObject& GameObject::operator=(const GameObject& other)
{

}

void GameObject::drawObject(sf::RenderWindow& fen)
{
    fen.draw(this->sprite);
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::setProperties(bool isHurting, bool isSolid, bool isTrigger)
{
    //this->isVisible = isVisible;
    this->isHurting = isHurting;
    this->isSolid = isSolid;
    this->isTrigger = isTrigger;
}

void GameObject::setPos(int xPos, int yPos)
{
    this->sprite.setPosition(xPos, yPos);
}

bool GameObject::getProps(std::string prop)
{
    if(prop == "solid")
        return this->isSolid;
    if(prop == "trigger")
        return this->isTrigger;
    if(prop == "hurting")
        return this->isHurting;
}

bool GameObject::setTrigger(bool state)
{

}
