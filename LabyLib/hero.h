#pragma once

#include "character.h"

class Hero : public Character {
public:
	// Create a hero.
	Hero(std::pair<int, int> xy);
	void Regen();

private:
	int experience_;
	int health_regen_;
	int max_health_points_;
};