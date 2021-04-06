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


class Ship : public IGameElement {
    RenderWindow& _window;
    Texture _texture;

    const int w = 10, h = 10, damage = 50;
    int x = 450;
    int y = 500;
    int health = 350;
    Sprite _sprite;
public:
    double wx, hy=y;

    Ship(RenderWindow& w) :_window(w) {
        _texture.loadFromFile("res/ship.png");
        _sprite.setTexture(_texture);
        _sprite.setPosition(x, y);
    }
    ~Ship() {}
    void shot() {

    }

    void MoveLeft() override {
        wx = x + w / 2;
        _sprite.move(-15, 0);
    }
    void MoveRight() override {
         wx = x + w / 2;
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



class Enemy : public IGameElement {
    int damage = 10, w = 5, h = 5, health = 50;
    RenderWindow& _window;
    Texture _texture;
    int x[29] = {110,130,200,230,270,290,310,340,370,400,430,460,490,510,540,570,600,640,670,700,720,730,770,800,830,870,900,930,965 };
    int y[6] = { 20,30,50,70,120,150 };
    Sprite _sprite;
public:
    double _x,_y;
    Enemy(RenderWindow& w, int i, int j) :_window(w) {
        _texture.loadFromFile("res/enemy.png");
        _sprite.setTexture(_texture);
        _x=x[i];
        _y = y[j];
        _sprite.setPosition(_x, _y);
    }

    void shots();
    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}

    void MoveDown() override {
        _y= _y + 0.01;
        _sprite.move(0, 0.01);
    }

    void Draw() override {
        _window.draw(_sprite);
    }
    std::string died(Ship &s) {
        std::string str="";
        if (_y+100> s.hy) {
            str = "die";
            return str;
        }
        return "Play";
    }
};



class Boss : public Enemy {
    bool special_skill;
public:
    Texture texture_boss;
    Sprite sprite_boss;
    Boss();
};

static void updateGameOverLabel(sf::Text& label, const std::string& text)
{
    label.setString(text);
 //   utils::centerizeTextOrigin(label);
}

std::vector<Enemy> enemys;

int main()
{
    srand(time(0));
    Texture textureGame_over;
    textureGame_over.loadFromFile("res/game_over.jpg");
    Sprite spriteGame_over(textureGame_over);
    RenderWindow window(VideoMode(1000, 600), "The Game!");
    // Создание и загрузка текстуры

    Ship s(window);
    Enemy en(window, 4, 4);
   
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {}
            else if (event.key.code == Keyboard::Left) s.MoveLeft();
            else if (event.key.code == Keyboard::Right) s.MoveRight();
        }
        en.MoveDown();

        window.clear(Color::White);
        if (en.died(s) == "die") {
            break;
        }
        en.Draw();
        s.Draw();
        window.display();
    }
    Clock clock;
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.draw(spriteGame_over);
        window.display();
    }
    return 0;
}
