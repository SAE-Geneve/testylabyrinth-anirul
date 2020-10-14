#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "character.h"
#include "enemy.h"
#include "hero.h"

// This is the place where the rules are written.
class World {
public:
	World(
		const std::string& map =
			"########################" // 24 * 8
			"#.....E......E.....#..P#" // P is at (22, 1)
			"#######..#####..####...#"
			"#........#.............#"
			"#.E......#...E...E.....#"
			"#..##################..#"
			"#.........E............#"
			"########################", 
		int length = 24);

public:
	void EraseDead();
	bool HasEnemies() const;
	std::pair<int, int> North(const Character& character) const;
	std::pair<int, int> South(const Character& character) const;
	std::pair<int, int> East(const Character& character) const;
	std::pair<int, int> West(const Character& character) const;
	void ShowMap() const;
	void ShowHero() const;
	void ShowEnemies() const;
	void HeroAttack();
	void EnemyAttack();

public:
	void Regen() { hero_.Regen(); }
	Hero& GetHero() { return hero_; }

private:
	std::pair<int, int> CheckPosition(
		std::pair<int, int> begin, 
		std::pair<int, int> end) const;
	char GetTile(std::pair<int, int> xy) const;

private:
	Hero hero_;
	std::vector<Enemy> enemies_;
	std::map<std::pair<int, int>, char> map_;
};
