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
	float dist = Distance(enemy);
	if (std::abs(dist - 1.0f) < std::numeric_limits<float>::epsilon())
	{
		enemy.SetHealthPoints(
			enemy.GetHealthPoints() - 
			std::max(0, attack_ - enemy.GetDefence()));
	}
}

bool Character::IsDead() const
{
	return health_points_ <= 0;
}

float Character::Distance(const Character& character) const
{
	float a2 = std::pow((float)(xy_.first - character.xy_.first), 2.0f);
	float b2 = std::pow((float)(xy_.second - character.xy_.second), 2.0f);
	return std::sqrt(a2 + b2);
}
