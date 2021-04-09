#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "IGameElement.h"

using namespace sf;


class Ship : public IGameElement {
    RenderWindow& _window;
    Texture _texture;

    const int w = 10, h = 10, damage = 50, b = 1;
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
    void shot() {

    }

    void MoveLeft() override {
        _sprite.move(-25, 0);
    }
    void MoveRight() override {
        _sprite.move(25, 0);
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