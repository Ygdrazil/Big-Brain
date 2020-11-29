#ifndef ANIMATION_H
#define ANIMATION_H
#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
    public:
        // Créer une animation en prenant une texture, un vecteur ayant le nombre d'images et le temps entre deux frames en secondes.
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        virtual ~Animation();

        // IntRect contenant la frame d'animation à afficher.
        sf::IntRect animRect;

        // Change de frame d'animation sur la row selectionné
        void Update(int row, float deltaTime);

    protected:

    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;

        float totalTime;
        float switchTime;
};

#endif // ANIMATION_H
