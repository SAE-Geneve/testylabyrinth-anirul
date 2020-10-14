#pragma once

#include <memory>
#include <gtest/gtest.h>
#include "../LabyLib/hero.h"

namespace test {

	class HeroTest : public testing::Test {
	public:
		HeroTest() = default;

	protected:
		std::unique_ptr<Hero> hero_ = nullptr;
	};

} // End namespace test.
