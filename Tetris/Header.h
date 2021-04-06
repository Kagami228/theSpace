#pragma once
#include <SFML/Graphics.hpp>
#include"Ship.h"
#include "Abstrsct.h"

using namespace sf;

class Enemy : public IGameElement {
    int damage = 10, w = 5, h = 5, health = 50;
    RenderWindow& _window;
    Texture _texture;
    int x[34] = { 10,30,50,70,110,130,200,230,270,290,310,340,370,400,430,460,490,510,540,570,600,640,670,700,720,730,770,800,830,870,900,930,965,990 };
    int y[6] = { 20,30,50,70,120,150 };
    Sprite _sprite;
public:

    Enemy(RenderWindow& w, int i, int j) :_window(w) {
        _texture.loadFromFile("res/enemy.png");
        _sprite.setTexture(_texture);
        _sprite.setPosition(x[i], y[j]);
    }

    void movement();
    void shots();
    void MoveLeft() override {
        _sprite.move(-15, 0);
    }
    void MoveRight() override {
        _sprite.move(15, 0);
        auto pos = _sprite.getPosition();
    }
    void MoveTop() override {

    }
    void MoveDown() override {

    }
    void Draw() override {
        _window.draw(_sprite);
    }
};  
