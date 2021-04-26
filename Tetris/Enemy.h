#pragma once

#include "Header.h"

using namespace sf;

class Enemy : public IGameElement {
    const int actor = 1;
    RenderWindow& _window;
    //Texture _texture;
    CircleShape _circle;
    //Sprite _sprite;
public:
    int  health = 200;
    int damage = 50, w = 5, h = 5;
    double _x, _y;
    int score = 100;
    //Enemy();
    Enemy(RenderWindow& w, int i, int j) :_window(w), _circle(15.f) {

        _circle.setFillColor(Color(230, 0, 230));
        // _texture.loadFromFile("res/enemy.png");
        // _texture.setRepeated(true);
         //_sprite.setTexture(_texture);
        _circle.setPosition(i, j);
        _x = i;
        _y = j;
    }

    void Shot(std::vector<Shoot*>& all) {
        auto sh = new Shoot(_window, damage, 0.25, actor, _x, _y);
        all.push_back(sh);
    }
    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}

    void MoveDown() override {
        _y = _y + 0.04;
        _circle.move(0, 0.04);
    }

    void Draw() override {
        _window.draw(_circle);
    }
};