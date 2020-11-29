#include "../include/Animation.h"

// Créer une animation en prenant une texture, un vecteur ayant le nombre d'images et le temps entre deux frames en secondes.
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    animRect.width = texture->getSize().x / float(imageCount.x);
    animRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
    //dtor
}

// Change de frame d'animation sur la row selectionné
void Animation::Update(int row, float deltaTime)
{
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if(currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    animRect.left = currentImage.x * animRect.width;
    animRect.top = currentImage.y * animRect.height;

}
