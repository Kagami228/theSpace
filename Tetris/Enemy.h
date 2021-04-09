#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "IGameElement.h"
#include "Ship.h"
using namespace sf;

class Enemy : public IGameElement {
    int damage = 10, w = 5, h = 5, health = 50;
    const int b = -1;
    RenderWindow& _window;
    //Texture _texture;
    CircleShape _circle;
    //Sprite _sprite;
public:
    double _x, _y;
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

    void Shots();
    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}

    void MoveDown() override {
        _y = _y + 0.1;
        _circle.move(0, 0.1);
    }

    void Draw() override {
        _window.draw(_circle);
    }
    std::string died(Ship& s) {
        std::string str = "";
        if (_y + 100 > s.hy) {
            str = "die";
            return str;
        }
        return "Play";
    }
};