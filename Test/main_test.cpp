#include <gtest/gtest.h>
#include "character_test.h"
#include "command_test.h"
#include "enemy_test.h"
#include "hero_test.h"
#include "world_test.h"

int main(int ac, char** av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}