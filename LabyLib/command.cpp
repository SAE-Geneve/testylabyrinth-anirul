#include "command.h"

#include <iostream>
#include <vector>

bool Command::ProcessCommand()
{
	// Get the command from the keyboard.
	std::cout << "] ";
	std::string command_str;
	std::getline(std::cin, command_str);
	switch (command_str[0])
	{
	case 'q':
		return false;
	case 'n':
		world_.GetHero().SetPosition(world_.North(world_.GetHero()));
		break;
	case 's':
		world_.GetHero().SetPosition(world_.South(world_.GetHero()));
		break;
	case 'e':
		world_.GetHero().SetPosition(world_.East(world_.GetHero()));
		break;
	case 'w':
		world_.GetHero().SetPosition(world_.West(world_.GetHero()));
		break;
	case 'a':
		world_.HeroAttack();
		break;
	case 'h':
	default:
		ShowCommands();
		break;
	}
	// Finish the process command.
	world_.Regen();
	world_.EraseDead();
	world_.EnemyAttack();
	// Check victory condition.
	if (!world_.HasEnemies())
	{
		std::cout << "You WON!\n";
		return false;
	}
	// Check death.
	if (world_.GetHero().IsDead())
	{
		std::cout << "You are DEAD!\n";
		return false;
	}
	return true;
}

void Command::ShowCommands()
{
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit   -> quit the game.\n";
	std::cout << "\t[n]orth  -> move north.\n";
	std::cout << "\t[s]outh  -> move south.\n";
	std::cout << "\t[w]est   -> move west.\n";
	std::cout << "\t[e]ast   -> move east.\n";
	std::cout << "\t[a]ttack -> attack enemies.\n\n";
}

void Command::ShowState()
{
	world_.ShowMap();
	world_.ShowHero();
	world_.ShowEnemies();
}
