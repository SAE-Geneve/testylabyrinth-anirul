#pragma once

#include "character.h"
#include "hero.h"

class Enemy : public Character
{
public:
	// Create a default Gob.
	Enemy(std::pair<int, int> xy);
};
