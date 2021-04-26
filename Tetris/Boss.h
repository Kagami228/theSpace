#pragma once
#include "Header.h"

using namespace sf;

class Boss :public IGameElement {
    int special_skill[3] = {1,2,3};
    int ssll;
    RenderWindow& _window;
    CircleShape _circle;
    //Texture _texture;
    //Sprite _sprite;
public:
   
    const int actor = 1;
    int damage = 50, health = 50, core = 100;
    double  _x, _y;
    Texture texture_boss;
    Sprite sprite_boss;
    Boss(RenderWindow& w, int i) :_window(w), ssll(special_skill[i]), _circle(45.f) {

        _circle.setFillColor(Color(230, 230, 230));
        //_texture.loadFromFile("res/boss.png");
        //_sprite.setTexture(_texture);
        _circle.setPosition(500, 100);
        _x = 500;
        _y = 100;
    }

    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}
    void Shot(std::vector<Shoot*>& all) {
        if (ssll == 1) {
            auto sh = new Shoot(_window, damage, 0.5, actor, _x + 20, _y + 20);
            all.push_back(sh);
        }
        else if (ssll == 2) {
            auto sh1 = new Shoot(_window, damage, 0.2, actor, _x + 30, _y + 20);
            all.push_back(sh1);
            auto sh2 = new Shoot(_window, damage, 0.2, actor, _x + 15, _y + 20);
            all.push_back(sh2);
        }else if (ssll == 3) {
            auto sh1 = new Shoot(_window, damage, 0.2, actor, _x + 45, _y + 20);
            all.push_back(sh1);
            auto sh2 = new Shoot(_window, damage, 0.2, actor, _x + 30, _y + 20);
            all.push_back(sh2);
            auto sh3 = new Shoot(_window, damage, 0.2, actor, _x + 15, _y + 20);
            all.push_back(sh3);
        }

    }
    void MoveDown() override {
        _y = _y + 0.04;
        _circle.move(0, 0.04);
    }
    void Draw() override {
        _window.draw(_circle);
    }

};
