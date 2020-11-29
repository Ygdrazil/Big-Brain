#include "../include/AssetManager.hpp"
#include "../include/definitions.hpp"

AssetManager::AssetManager()
{
    this->addResource("./assets/textures/bg.png");
    this->addResource("./assets/textures/Start.png");
    this->addResource("./assets/textures/Leave.png");
    this->addResource("./assets/textures/BriqueMarron.png");
    this->addResource("./assets/textures/reset.png");
    this->addResource("./assets/textures/bgGame.png");
    this->addResource("./assets/textures/bkTitre.png");
    this->addResource("./assets/textures/resume.png");
    this->addResource("./assets/textures/BriqueGrise.png");
    this->addResource("./assets/textures/SpikeT.png");
    this->addResource("./assets/textures/porteOuverte.png");
    this->addResource("./assets/textures/bkGround_explication.png");
    this->addResource("./assets/textures/vide.png");
    this->addResource("./assets/textures/Perso.png");
    this->addResource("./assets/textures/PersoMort.png");
}


int AssetManager::addResource(std::string texPath)
{
    if (!BBG::resources[this->texCount].loadFromFile(texPath))
        return EXIT_FAILURE;
    this->texCount++;
    return texCount;
}

void AssetManager::loadTex(sf::Sprite *sprite, int idTexture)
{
    sprite->setTexture(BBG::resources[idTexture]);
}

AssetManager::~AssetManager()
{
    //dtor
}
