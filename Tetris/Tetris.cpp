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
    int y = 800;
    int health = 350;
    Sprite _sprite;
public:
    double hy=y;

    Ship(RenderWindow& w) :_window(w) {
        _texture.loadFromFile("res/ship.png");
        _sprite.setTexture(_texture);
        _sprite.setPosition(x, y);
    }
    ~Ship() {}
    void shot() {

    }

    void MoveLeft() override {
        _sprite.move(-15, 0);
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



class Enemy : public IGameElement {
    int damage = 10, w = 5, h = 5, health = 50;
    RenderWindow& _window;
    //Texture _texture;
    CircleShape _circle;
    int x[34] = {110,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750 };
    int y[11] = { 10,20,30,40,50,55,60,100,80,90,70};
    //Sprite _sprite;
public:
    double _x,_y;
    //Enemy();
    Enemy(RenderWindow& w, int i, int j) :_window(w), _circle(15.f) {

        _circle.setFillColor(Color(230, 0, 230));
       // _texture.loadFromFile("res/enemy.png");
       // _texture.setRepeated(true);
        //_sprite.setTexture(_texture);
        _x=x[i];
        _y = y[j];
        _circle.setPosition(_x, _y);
    }

    void shots();
    void MoveLeft() override {}
    void MoveRight() override {}
    void MoveTop() override {}

    void MoveDown() override {
        _y= _y + 0.01;
        _circle.move(0, 0.01);
    }

    void Draw() override {
        _window.draw(_circle);
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



class Boss :public IGameElement {
    int special_skill[5] = { 1,2,3,4,5 };
    int ssll;
    int damage = 10, w = 5, h = 5, health = 50,_y=100;
    RenderWindow& _window;
    CircleShape _circle;
    //Texture _texture;
    //Sprite _sprite;
public:
    Texture texture_boss;
    Sprite sprite_boss;
    Boss(RenderWindow& w,int i) :_window(w),ssll(special_skill[i]), _circle(45.f) {

        _circle.setFillColor(Color(230, 230, 230)); 
        //_texture.loadFromFile("res/boss.png");
        //_sprite.setTexture(_texture);
        _circle.setPosition(500, _y);
    }

    void MoveLeft() override{}
    void MoveRight() override{}
    void MoveTop() override{}

    void MoveDown() override {
        _y = _y + 0.008;
        _circle.move(0, 0.008);
    }
    void Draw() override {
        _window.draw(_circle);
    }

};



std::vector<Enemy> enemys;

int main()
{
    srand(time(0));
    Texture textureGame_over;
    textureGame_over.loadFromFile("res/game_over.jpg");
    Sprite spriteGame_over(textureGame_over);
    RenderWindow window(VideoMode(1800, 900), "The Game!");
    // Создание и загрузка текстуры

    Ship s(window);
    int i,j;

    Enemy en(window, 4, 4);
    enemys.push_back(en);
    Boss bs(window,3);
    while (window.isOpen()) {
        time_t timer = time(NULL);
        if (timer % 11 == 0) {
            i = rand() % 34;
            j = rand() % 11;
            Enemy en(window, i, j);
            enemys.push_back(en);
        }
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {}
            else if (event.key.code == Keyboard::Left) s.MoveLeft();
            else if (event.key.code == Keyboard::Right) s.MoveRight();
        }
        //window.clear(Color::Blue);
 
        for (int c = 0; c < enemys.size(); c++) {
            enemys[c].MoveDown();
            enemys[c].Draw();
            if (enemys[c].died(s) == "die") {
                Clock clock;
                while (window.isOpen()) {
                    Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == Event::Closed)
                            window.close();
                    }
                    window.draw(spriteGame_over);
                    window.display();
                }
            }
        }
        bs.MoveDown();
        bs.Draw();
        s.Draw();

        window.display();
    }
   
    return 0;
}
