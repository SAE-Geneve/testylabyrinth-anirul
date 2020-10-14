#pragma once

#include <string>

class Character {
public:
	Character(
		std::pair<int, int> xy, 
		int health_points, 
		int attack, 
		int defence, 
		const std::string& name);
	void Attack(Character& enemy) const;
	bool IsDead() const;
	float Distance(const Character& character) const;

public:
	void SetHealthPoints(int health_points) { health_points_ = health_points; }
	int GetHealthPoints() const { return health_points_; }
	int GetAttack() const { return attack_; }
	int GetDefence() const { return defence_; }
	void SetPosition(std::pair<int, int> xy) { xy_ = xy; }
	std::pair<int, int> GetPosition() const { return xy_; }
	const std::string& GetName() const { return name_; }

protected:
	std::pair<int, int> xy_;
	int health_points_;
	int attack_;
	int defence_;
	std::string name_;
};
