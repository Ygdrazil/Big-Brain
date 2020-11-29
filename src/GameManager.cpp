#include <SFML/Audio.hpp>
#include "../include/GameManager.hpp"
#include "../include/Menu.hpp"
#include <unistd.h>
#include "../include/GameObject.hpp"
#include "../include/LevelManager.hpp"
#include "../include/Levels.hpp"
#include "../include/Scene.hpp"

GameManager::GameManager()
{
    game.create(sf::VideoMode(1920,1080),"gametest", sf::Style::Fullscreen);
    game.setFramerateLimit(60);
}

void GameManager::run()
{
    LevelManager lm;

    Scene scene1(lvl::Level1);
    scene1.addObject(9, 500, 960, true, true, false, am);
    scene1.addObject(11, 700, 100, false, false, false, am);
    Scene scene2(lvl::Level2);
    Scene scene3(lvl::Level3);
    Scene scene4(lvl::Level4);
    Scene scene5(lvl::Level5);

    sf::Music music;
    if(!music.openFromFile("./assets/sounds/music.ogg"))
    {
        printf("Music could not load");
    }
    music.setLoop(true);
    music.play();

    int gameState = 0;
    int gameVictory = 0;
    int nbVies = 0;
    while(game.isOpen())
    {
        int state = menu(game, this->am);
        if(state == 2)
            game.close();
        int resume = 0;
        while(state == 1)
        {
            gameState = 1;
            switch(gameVictory)
            {
            case 0:
                lm.loadLevel(scene1, this->am, &gameVictory);
                lm.player.setVictory(false);
                nbVies = 5;
                break;
            case 1:
                lm.loadLevel(scene2, this->am, &gameVictory);
                lm.player.setVictory(false);
                nbVies = 2;
                break;
            case 2:
                lm.loadLevel(scene3, this->am, &gameVictory);
                lm.player.setVictory(false);
                nbVies = 4;
                break;
            case 3:
                lm.loadLevel(scene4, this->am, &gameVictory);
                lm.player.setVictory(false);
                nbVies = 8;
                break;
            case 4:
                lm.loadLevel(scene5, this->am, &gameVictory);
                lm.player.setVictory(false);
                nbVies = 11;
                break;
            }
            while(gameState == 1)
            {
                game.clear();
                sf::Event event;
                sf::Clock clock;
                float deltaTime = clock.restart().asSeconds();
                int resume = 0;
                if(lm.player.getVictory())
                {
                    gameVictory++;
                    gameState = 0;
                    lm.player.setVictory(false);
                }
                switch(gameVictory)
                {
                case 0:
                    lm.update(game, deltaTime, scene1);
                    break;
                case 1:
                    lm.update(game, deltaTime, scene2);
                    break;
                case 2:
                    lm.update(game, deltaTime, scene3);
                    break;
                case 3:
                    lm.update(game, deltaTime, scene4);
                    break;
                case 4:
                    lm.update(game, deltaTime, scene5);
                    break;
                }
                game.display();

                if(game.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        game.close();
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        resume = menuPause(game, this->am);
                    }
                    if (event.key.code == sf::Keyboard::V)
                    {
                        gameVictory=1;
                        gameState=0;
                    }
                    if(resume == 2){
                        if(gameVictory == 0){
                            lm.resetObjects(&scene1);
                        }else if(gameVictory == 1){
                            lm.resetObjects(&scene2);
                        }else if(gameVictory == 2){
                            lm.resetObjects(&scene3);
                        }else if(gameVictory == 3){
                            lm.resetObjects(&scene4);
                        }else if(gameVictory == 4){
                            lm.resetObjects(&scene5);
                        }
                        gameState = 0;
                    }
                    if(resume == 3 || nbVies == 0){
                        lm.resetObjects(&scene1);
                        lm.resetObjects(&scene2);
                        lm.resetObjects(&scene3);
                        lm.resetObjects(&scene4);
                        lm.resetObjects(&scene5);
                        gameVictory = 0;
                        state = 0;
                        gameState = 0;
                    }
                }
                if(lm.player.mort == 1){
                    if(gameVictory == 0){
                        scene1.addObject(14,lm.player.sprite.getPosition().x,lm.player.sprite.getPosition().y, false, true, false, am);
                        lm.player.sprite.setPosition(200, 960);
                    }else if(gameVictory == 1){
                        scene2.addObject(14,lm.player.sprite.getPosition().x,lm.player.sprite.getPosition().y, false, true, false, am);
                        lm.player.sprite.setPosition(100,100);
                    }else if(gameVictory == 2){
                        scene3.addObject(14,lm.player.sprite.getPosition().x,lm.player.sprite.getPosition().y, false, true, false, am);
                        lm.player.sprite.setPosition(100,100);
                    }else if(gameVictory == 3){
                        scene4.addObject(14,lm.player.sprite.getPosition().x,lm.player.sprite.getPosition().y, false, true, false, am);
                        lm.player.sprite.setPosition(100,100);
                    }else if(gameVictory == 4){
                        scene5.addObject(14,lm.player.sprite.getPosition().x,lm.player.sprite.getPosition().y, false, true, false, am);
                        lm.player.sprite.setPosition(100,100);
                    }
                    nbVies--;
                    lm.player.mort = 0;
                }
            }
        }
    }
}

GameManager::~GameManager()
{

}



