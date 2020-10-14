#include "enemy.h"

#include <cmath>

#include "hero.h"

Enemy::Enemy(std::pair<int, int> xy) : Character(xy, 50, 15, 2, "Gob") {}
