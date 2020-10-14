#pragma once

#include <memory>
#include <gtest/gtest.h>
#include "../LabyLib/enemy.h"

namespace test {

	class EnemyTest : public testing::Test {
	public:
		EnemyTest() = default;

	protected:
		std::unique_ptr<Enemy> enemy_ = nullptr;
	};

} // End namespace test.
