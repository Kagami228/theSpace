#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "Ship.h"
#include "Enemy.h"
#include "Boss.h"


using namespace sf;

class Shoot :public IGameElement {
    int damege, speed, _x, _y;
    const int actor;
    CircleShape _circle;
    RectangleShape _rectangle;

public:
    Shoot(int d, int s, int b, int x, int y) : damege(d), speed(s), actor(b), _rectangle(Vector2f(10.f, 5.f)), _x(x), _y(y) {
        _rectangle.setFillColor(Color(230, 230, 230));
        _rectangle.setPosition(_x, _y);
    }
    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}
    void MoveDown() override {}
    void Move() {
        _circle.move(0, 0.008 * actor);
    }
    void Draw() override {
        _circle.move(0, 0.008);
    }
};
