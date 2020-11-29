#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <string>
#include <SFML/Graphics.hpp>

class AssetManager
{
    public:
        AssetManager();
        int addResource(std::string texPath);
        void loadTex(sf::Sprite *sprite, int idTexture);
        virtual ~AssetManager();

    protected:

    private:
        int texCount = 0;
};


#endif // ASSETMANAGER_H
