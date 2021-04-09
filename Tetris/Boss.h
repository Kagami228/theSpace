#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "Ship.h"
#include "Enemy.h"


using namespace sf;

class Boss :public IGameElement {
    int special_skill[5] = { 1,2,3,4,5 };
    int ssll;
    const int b = -1;
    int damage = 10, w = 5, h = 5, health = 50, _y = 100, _x = 500;
    RenderWindow& _window;
    CircleShape _circle;
    //Texture _texture;
    //Sprite _sprite;
public:
    Texture texture_boss;
    Sprite sprite_boss;
    Boss(RenderWindow& w, int i) :_window(w), ssll(special_skill[i]), _circle(45.f) {

        _circle.setFillColor(Color(230, 230, 230));
        //_texture.loadFromFile("res/boss.png");
        //_sprite.setTexture(_texture);
        _circle.setPosition(_x, _y);
    }

    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}
    void Shots() {
        //    Shoot s(damage, 0.02, b, _x, _y);
        //    all_shoots.push_back(s);
    }
    void MoveDown() override {
        _y = _y + 0.008;
        _circle.move(0, 0.008);
    }
    void Draw() override {
        _window.draw(_circle);
    }

};
