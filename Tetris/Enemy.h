#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

struct IGameElement
{
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveTop() = 0;
    virtual void MoveDown() = 0;
    virtual void Draw() = 0;
};
class Enemy : public IGameElement {
    int damage = 10, w = 5, h = 5, health = 50;
    RenderWindow& _window;
    Texture _texture;
    int x[34] = { 10,30,50,70,110,130,200,230,270,290,310,340,370,400,430,460,490,510,540,570,600,640,670,700,720,730,770,800,830,870,900,930,965,990 };
    int y[6] = { 20,30,50,70,120,150 };
    Sprite _sprite;
public:
    Enemy(RenderWindow& w, int i, int j);
    void movement();
    void shots();
};

class Boss : public Enemy {
    bool special_skill;
public:
    Texture texture_boss;
    Sprite sprite_boss;
    Boss();
};
