#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "Ship.h"
#include "Enemy.h"
#include "Boss.h"
#include "Shoot.h"


using namespace sf;


std::vector<Shoot> all_shoots;

std::vector<Enemy> enemys;

int main()
{
    srand(time(NULL));
    int x[34] = { 110,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750 };
    int y[11] = { 10,20,30,40,50,55,60,100,80,90,70 };
    Texture textureGame_over;
    textureGame_over.loadFromFile("res/game_over.jpg");
    Sprite spriteGame_over(textureGame_over);
    RenderWindow window(VideoMode(1800, 900), "The Game!");
    // Создание и загрузка текстуры
    Ship s(window);
    int i,j;

    Enemy en(window, 4, 4);
    enemys.push_back(en);
    clock_t clock1;
    Boss bs(window,3);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {}
            else if (event.key.code == Keyboard::Left) s.MoveLeft();
            else if (event.key.code == Keyboard::Right) s.MoveRight();
        }

        window.clear(Color::Blue);
        clock1 = clock();
        if ((clock1)%400 == 0) {
            i = rand() % 34;
            j = rand() % 11;
            Enemy en(window, x[i], y[j]);
            enemys.push_back(en);
        }
        for (int c = 0; c < enemys.size(); c++) {
            enemys[c].MoveDown();
            enemys[c].Draw();
            if (enemys[c].died(s) == "die") {
                Clock clock;
                while (window.isOpen()) {
                    Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == Event::Closed)
                            window.close();
                    }
                    window.draw(spriteGame_over);
                    window.display();
                }
            }
        }
        for (int c = 0; c < all_shoots.size(); c++) {
        
        }
        bs.MoveDown();
        bs.Draw();
        s.Draw();

        window.display();
        sleep(milliseconds(1));
    }
   
    return 0;
}
