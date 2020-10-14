#pragma once

#include <memory>
#include <gtest/gtest.h>
#include "../LabyLib/command.h"

namespace test {

	class CommandTest : public testing::Test {
	public:
		CommandTest() = default;

	protected:
		std::unique_ptr<Command> command_;
	};

} // End namespace test.