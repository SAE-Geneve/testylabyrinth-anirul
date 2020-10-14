#include "command_test.h"

namespace test {

	TEST_F(CommandTest, CreateCommandTest)
	{
		EXPECT_FALSE(command_);
		World world{};
		command_ = std::make_unique<Command>(world);
		EXPECT_TRUE(command_);
	}

}