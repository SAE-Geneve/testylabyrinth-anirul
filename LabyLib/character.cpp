#include "character.h"

#include <cmath>
#include <limits>

Character::Character(
	std::pair<int, int> xy, 
	int health_points, 
	int attack, 
	int defence, 
	const std::string& name) :
		xy_(xy),
		health_points_(health_points),
		attack_(attack),
		defence_(defence),
		name_(name) {}

void Character::Attack(Character& enemy) const
{
	// TODO: Complete me!
}

bool Character::IsDead() const
{
	// TODO: Complete me!
	return false;
}

float Character::Distance(const Character& character) const
{
	// TODO: Complete me!
	return 1.0f;
}
