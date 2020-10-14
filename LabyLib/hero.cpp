#include "hero.h"

#include <cmath>

Hero::Hero(std::pair<int, int> xy) : 
	Character(xy, 100, 20, 5, "Gurdil"),
	experience_(0),
	health_regen_(5),
	max_health_points_(100) {}

void Hero::Regen()
{
	health_points_ += std::max(0, health_regen_);
	health_points_ = std::min(health_points_, max_health_points_);
}
