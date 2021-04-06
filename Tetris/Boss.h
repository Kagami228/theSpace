#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"

class Boss : public Enemy {
    bool special_skill;
public:
    Texture texture_boss;
    Sprite sprite_boss;
    Boss();
};