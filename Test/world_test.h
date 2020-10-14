#pragma once

#include <memory>
#include <gtest/gtest.h>
#include "../LabyLib/world.h"

namespace test {

	class WorldTest : public testing::Test {
	public:
		WorldTest() = default;

	protected:
		std::unique_ptr<World> world_ = nullptr;
	};

} // End namespace test.
