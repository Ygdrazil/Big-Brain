#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "../include/AssetManager.hpp"
#include "../include/GameObject.hpp"
#include "../include/LevelManager.hpp"


using namespace sf;
int menu(sf::RenderWindow& app, AssetManager am)
{
    GameObject wall(am, 0,0,0);
    GameObject btStart(am, 1,800,425);
    GameObject btLeave(am, 2,800,615);
    GameObject titre(am, 6, 640, 100);


    int game = 0, select = 0;


    while(game == 0)
    {
        Event event;
        while (app.pollEvent(event))
        {
            app.clear(Color::Blue);
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Vector2i mousePos = Mouse::getPosition();
                if(mousePos.x > 800 && mousePos.x < 1066){
                    if(mousePos.y > 425 && mousePos.y < 544){
                        game = 1;
                    }else if(mousePos.y > 615 && mousePos.y < 734){
                        game = 2;
                    }
                }
            }
            wall.drawObject(app);
            btStart.drawObject(app);
            btLeave.drawObject(app);
            titre.drawObject(app);
            app.display();
        }
    }
    app.clear();
    return game;

}

int menuPause(RenderWindow& app, AssetManager am)
{
    GameObject btResume(am, 7, 800, 190);

    GameObject btReset(am, 4, 800,440);

    GameObject btLeave(am, 2, 800, 690);


    int select = 0, resume = 0;


    while(resume == 0)
    {
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Vector2i mousePos = Mouse::getPosition();
                if(mousePos.x > 800 && mousePos.x < 1066){
                    if(mousePos.y > 190 && mousePos.y < 309){
                        resume = 1;
                    }else if(mousePos.y > 440 && mousePos.y < 559){
                        resume = 2;
                    }else if(mousePos.y > 690 && mousePos.y < 809){
                        resume = 3;
                    }
                }
            }
            btResume.drawObject(app);
            btReset.drawObject(app);
            btLeave.drawObject(app);
            app.display();
        }
    }
    app.clear();
    return resume;
}
