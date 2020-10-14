#include "world.h"

#include <cassert>
#include <iostream>
#include <limits>

World::World(const std::string& map, int length) : hero_({0, 0})
{
	for (int j = 0; j < map.size();) 
	{
		for (int i = 0; i < length; ++i)
		{
			auto pair = std::pair<int, int>(i, j / length);
			if (map[j] == 'E')
			{
				Enemy enemy(pair);
				enemies_.push_back(enemy);
				map_[pair] = '.';
			}
			else if (map[j] == 'P')
			{
				hero_.SetPosition(pair);
				map_[pair] = '.';
			}
			else 
			{
				assert(map[j] == '.' || map[j] == '#');
				map_[pair] = map[j];
			}
			++j;
		}
	}
}

void World::EraseDead()
{
	auto pos = std::remove_if(
		enemies_.begin(),
		enemies_.end(),
		[](const Enemy& enemy)
		{
			return enemy.IsDead();
		});
	enemies_ = { enemies_.begin(), pos };
}

bool World::HasEnemies() const
{
	return (bool)enemies_.size();
}

std::pair<int, int> World::North(const Character& character) const
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.second -= 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

std::pair<int, int> World::South(const Character& character) const
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.second += 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

std::pair<int, int> World::East(const Character& character) const
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.first += 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

std::pair<int, int> World::West(const Character& character) const
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.first -= 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

void World::HeroAttack()
{
	for (auto& enemy : enemies_)
	{
		float dist = enemy.Distance(hero_);
		if (std::abs(dist - 1.0f) < std::numeric_limits<float>::epsilon()) 
		{
			hero_.Attack(enemy);
		}
	}
}

void World::ShowMap() const
{
	// Show the maze to the user.
	std::cout << "Maze :\n";
	for (int i = -1; i < 2; ++i)
	{
		std::cout << "\t +---+---+---+\n\t";
		for (int j = -1; j < 2; ++j)
		{
			auto pair = std::pair<int, int>(
				hero_.GetPosition().first + j,
				hero_.GetPosition().second + i);
			std::cout << " | " << GetTile(pair);
		}
		std::cout << " |\n";
	}
	std::cout << "\t +---+---+---+\n\n";
}

void World::ShowHero() const
{
	// Show the player info the user.
	std::cout 
		<< "Player(" 
		<< hero_.GetPosition().first 
		<< ", " 
		<< hero_.GetPosition().second 
		<< ") :\n";
	std::cout << "\tname       : " << hero_.GetName() << "\n";
	std::cout << "\thit points : " << hero_.GetHealthPoints() << "\n";
	std::cout << "\n";
}

void World::ShowEnemies() const
{
	// Show the enemy that are within view of the user.
	for (const auto& enemy : enemies_)
	{
		float dist = enemy.Distance(hero_);
		if (std::abs(dist - 1.0f) < std::numeric_limits<float>::epsilon()) 
		{
			std::cout
				<< "Enemy(" 
				<< enemy.GetPosition().first 
				<< ", " 
				<< enemy.GetPosition().second 
				<< ")\n";
			std::cout << "\tname       : " << enemy.GetName() << "\n";
			std::cout << "\thit points : " << enemy.GetHealthPoints() << "\n";
			std::cout << "\n";
		}
	}
}

void World::EnemyAttack()
{
	for (auto& enemy : enemies_)
	{
		float dist = enemy.Distance(hero_);
		if (std::abs(dist - 1.0f) < std::numeric_limits<float>::epsilon())
		{
			enemy.Attack(hero_);
		}
	}
}

std::pair<int, int> World::CheckPosition(
	std::pair<int, int> begin, 
	std::pair<int, int> end) const
{
	// Check if the player is there.
	if (end == hero_.GetPosition())
		return begin;
	// Check if there is an enemy in there.
	for (const auto& item : enemies_)
	{
		if (end == item.GetPosition())
			return begin;
	}
	// Check if there is a wall in there.
	if (map_.at(std::make_pair(end.first, end.second)) == '#')
		return begin;
	return end;
}

char World::GetTile(std::pair<int, int> xy) const
{
	for (const auto& enemy : enemies_)
	{
		if (enemy.GetPosition() == xy)
		{
			return 'E';
		}
	}
	if (hero_.GetPosition() == xy)
	{
		return 'P';
	}
	else if (map_.find(xy) == map_.end())
	{
		return ' ';
	}
	return map_.at(xy);
}
