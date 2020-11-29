#include "../include/LevelManager.hpp"
#include "../include/GameObject.hpp"
#include "../include/Scene.hpp"
#include "../include/Door.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

LevelManager::LevelManager()
{

}

void LevelManager::loadLevel(Scene scene, AssetManager am, int *gameVictory)
{
    am.loadTex(&(this->player.sprite),13);
    if(*gameVictory == 0){
    this->player.setPos(100,960);
    }else if(*gameVictory == 1){
    this->player.setPos(100,100);
    }else if(*gameVictory == 2){
    this->player.setPos(100,100);
    }else if(*gameVictory == 3){
    this->player.setPos(100,100);
    }else if(*gameVictory == 4){
    this->player.setPos(100,100);
    }
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<17; j++)
        {
            switch(scene.sceneMap[i][j])
            {
            case 0:
                am.loadTex(&(this->tileMap[i][j].sprite), 0);
                this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                break;
            case 1:
                am.loadTex(&(this->tileMap[i][j].sprite), 1);
                this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                break;
            case 2:
                am.loadTex(&(this->tileMap[i][j].sprite), 2);
                break;
            case 3:
                am.loadTex(&(this->tileMap[i][j].sprite), 3);
                this->tileMap[i][j].setProperties(false, true, false);
                this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                break;
            case 4:
                //this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                am.loadTex(&(this->tileMap[i][j].sprite), 12);
                this->tileMap[i][j].setProperties(false, false, false);
                break;
            case 5:
                am.loadTex(&(this->tileMap[i][j].sprite), 5);
                this->tileMap[i][j].setProperties(false, false, false);
                this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                this->tileMap[i][j].sprite.setScale(1,1);
                break;

            case 6:
                am.loadTex(&(this->tileMap[i][j].sprite), 9);
                this->tileMap[i][j].setProperties(true,true,false);
                this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                break;
            case 7:
                this->tileMap[i][j] = Door();
                am.loadTex(&(this->tileMap[i][j].sprite), 10);
                this->tileMap[i][j].setProperties(false, false, true);
                this->tileMap[i][j].sprite.setPosition(i*64,j*64);
                this->tileMap[i][j].sprite.setScale(2,2);
                break;
            }
        }
    }
}


void LevelManager::update(sf::RenderWindow& fen, float deltaTime, Scene scene)
{
    this->player.isGrounded = false;
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<17; j++)
        {
            this->tileMap[i][j].drawObject(fen);
            this->player.checkCollision(tileMap[i][j]);
        }
    }
    this->objetCount = scene.objectCount;
    if(objetCount > 0)
    {
        for(int k=0; k<objetCount; k++)
        {
            printf("get objectCount, %i\n", objetCount);
            //this->objectList[k].update();

            scene.objectList[k].drawObject(fen);
            this->player.checkCollision(scene.objectList[k]);
        }
    }
    this->player.drawObject(fen);
    this->player.update();
}

void LevelManager::resetObjects(Scene *scene)
{
    scene->objectCount = 0;
}

LevelManager::~LevelManager()
{
    //dtor
}
