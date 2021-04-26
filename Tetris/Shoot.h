#pragma once
#include "Header.h"
using namespace sf;

class Shoot :public IGameElement {
    double speed;
    RenderWindow& _window;
    CircleShape _circle;
    RectangleShape _rectangle;

public:
    int actor;
    int damege;
    double  _x, _y;
    Shoot(RenderWindow& w,int d, double s, int b, double x, double y):_window(w),damege(d), speed(s), _rectangle(Vector2f(10.f, 5.f)), _y(y){
        if (b == -1) {
            _rectangle.setFillColor(Color(80, 220, 50));
            actor = b;
            _x = x + 50;
        }
        else if (b == 1) {
            _x=x+7;
            _rectangle.setFillColor(Color(Color::Red));
            actor = b;
        }
        _rectangle.setPosition(_x, _y);
    }
    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}
    void MoveDown() override {}
    void Move() {
        _y = _y + speed * actor;
        _rectangle.move(0, speed * actor);
    }
    void Draw() override {
        _window.draw(_rectangle);
    }
    Shoot(const Shoot&) = delete;
};
