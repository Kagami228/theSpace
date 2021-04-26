#include "Header.h"

using namespace sf;
bool dieen = false;
int count = 0;

bool ColisionShip_damage_to_enemy(Enemy &e,Shoot &s) {
    if (s._x >=(e._x-5) and s._x <=(e._x+25) and (s._y<=e._y+25)) {
        return true;
    }
    return false;
}

bool heal_enemy_0( Shoot& s, Enemy& e) {
    e.health = e.health - s.damege;
    if (e.health == 0) {
        return true;
    }
    return false;
}
bool ColisionShip_damage_to_boss(Boss& b, Shoot& s) {
    if (s._x >= (b._x - 5) and s._x <= (b._x + 25) and (b._y <= b._y + 25)) {
        return true;
    }
    return false;
}

bool heal_boss_0(Shoot& s, Boss& b) {
    b.health = b.health - s.damege;
    if (b.health == 0) {
        return true;
    }
    return false;
}

bool ColisionShip_damage_to_ship(Ship& sh, Shoot& s) {
    if (s._x >= (sh.x) and s._x <= (sh.x + 100) and (s._y >= sh.y )and (s._y <= sh.y +10)) {
        return true;
    }
    return false;
}
bool heal_ship_0(Shoot& s, Ship& e) {
    e.health = e.health - s.damege;
    if (e.health == 0) {
        return true;
    }
    return false;
}


int main() {
    srand(time(NULL));
    int x[21] = { 110,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100};
    int y[11] = { 10,20,30,40,50,55,60,100,80,90,70 };
    int score = 0;
    Texture textureGame_over;
    textureGame_over.loadFromFile("res/game_over.jpg");
    Sprite spriteGame_over(textureGame_over);
    RenderWindow window(VideoMode(1200, 900), "The Game!");
    // Создание и загрузка текстуры
    Ship s(window);//корабль 
    int ij,ji,rnd;

    clock_t clock1;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {}
            else if (event.key.code == Keyboard::Left) s.MoveLeft();
            else if (event.key.code == Keyboard::Right) s.MoveRight();
            else if (event.key.code == Keyboard::B) s.Shot(all_shoots);
        }
        window.clear(Color::Black);
        clock1 = clock();

        //BOSSS

       // if (bossy.size() < 1) {
       //     auto bos = new Boss(window, 2);
       //     bossy.push_back(bos);
       // }
       // if ((clock1) % 700 == 0) {
       //     bossy[0]->Shot(all_shoots);
       // }
       // bossy[0]->MoveDown();
       // bossy[0]->Draw();
        //

        if ((clock1) % 400 == 0) {
            ij = rand() % 21;
            ji = rand() % 11;
            auto en = new Enemy(window, x[ij], y[ji]);
            enemys.push_back(en);
        }if ((clock1) % 450 == 0) {
            int rr = rand() % 5;
            if (enemys.size() != 0) {
                for (int il = 0; il < rr; il++) {
                    rnd = rand() % enemys.size();
                    enemys[rnd]->Shot(all_shoots);
                }
            }
        }if ((clock1) % 500 == 0) {
            for (int l = 0; l < bossy.size(); l++) {
                bossy[l]->Shot(all_shoots);
            }
        }
        for (int i = 0; i < all_shoots.size(); i++) {
            all_shoots[i]->Move();
            all_shoots[i]->Draw();
        }


        for (auto shoo = all_shoots.begin(); shoo != all_shoots.end(); shoo++) {
            if ((**shoo).actor == 1) {
                if ((*shoo)->_y > 800) {
                    delete* shoo;
                    shoo = all_shoots.erase(shoo);
                    //break;
                }
                else if (ColisionShip_damage_to_ship(s, **shoo)) {
                    if (heal_ship_0(**shoo, s)) {
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
                    delete* shoo;
                    shoo = all_shoots.erase(shoo);
                }
            }
            if (shoo == all_shoots.end()) {
                break;
            }
        }



        for (auto shoo = all_shoots.begin(); shoo != all_shoots.end(); shoo++) {
            if ((**shoo).actor == -1) {
                if ((*shoo)->_y < 70) {
                    delete* shoo;
                    shoo = all_shoots.erase(shoo);
                    // break;
                }
            }
            for (auto e = enemys.begin(); e != enemys.end(); e++) {
                if ((*e)->_y > 800) {
                    delete* e;
                    e = enemys.erase(e);
                }if ((**shoo).actor == -1) {
                        if (ColisionShip_damage_to_enemy(**e, **shoo)) {
                            if (heal_enemy_0(**shoo, **e)) {
                                score = score + (*e)->score;
                                delete* e;
                                e = enemys.erase(e);
                            }
                            delete* shoo;
                            shoo = all_shoots.erase(shoo);
                            break;
                        }
                    }
                if (e == enemys.end()) {
                    break;
                }
            }
            if (shoo == all_shoots.end()) {
                break;
            }
        }

        if (score % 200 == 0 and bossy.size() == 0 and score > 0) {
            int k = rand() % 3;
            auto bbos = new Boss(window,k);
            bossy.push_back(bbos);
        }
        
        for (int bos = 0;bos < bossy.size();bos++) {
            bossy[bos]->MoveDown();
            bossy[bos]->Draw();
        }
        for (int c = 0; c < enemys.size(); c++) {
            enemys[c]->MoveDown();
            enemys[c]->Draw();
        }
        s.Draw();
        window.display();
        sleep(milliseconds(1));
    }
    std::cout << score;

    return 0;
}
