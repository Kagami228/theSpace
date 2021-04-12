#pragma once
#include "Header.h"
#include "Shoot.h"
using namespace sf;


class Ship : public IGameElement {
    RenderWindow& _window;
    Texture _texture;

    const int w = 10, h = 10, damage = 50, b = -1;
    int x = 450;
    int y = 800;
    int health = 350;
    Sprite _sprite;
public:
    double hy = y;

    Ship(RenderWindow& w) :_window(w) {
        _texture.loadFromFile("res/ship.png");
        _sprite.setTexture(_texture);
        _sprite.setPosition(x, y);
    }
    ~Ship() {}
    void Shot(std::vector<Shoot>& all) {
        Shoot sh(_window, damage, 0.5, b, x, y);
        all.push_back(sh);
    }

    void MoveLeft() override {
        x = x - 10;
        _sprite.move(-10, 0);
    }
    void MoveRight() override {
        x = x + 10;
        _sprite.move(10, 0);
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