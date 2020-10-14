#pragma once

#include <memory>
#include <gtest/gtest.h>
#include "../LabyLib/character.h"

namespace test {

	class CharacterTest : public testing::Test {
	public:
		CharacterTest() = default;

	protected:
		std::unique_ptr<Character> character_ = nullptr;
	};

} // End namespace test.
