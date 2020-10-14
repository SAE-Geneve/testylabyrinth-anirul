#pragma once

#include "world.h"

class Command {
public:
	Command(World& world) : world_(world) {}
	bool ProcessCommand();
	void ShowCommands();
	void ShowState();
	
private:
	World& world_;
};