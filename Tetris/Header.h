#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "IGameElement.h"
#include "Ship.h"
#include "Enemy.h"
#include "Shoot.h"
#include "Boss.h"


std::vector<Shoot*> all_shoots;
std::vector<Enemy*> enemys;
std::vector<Boss*> bossy;