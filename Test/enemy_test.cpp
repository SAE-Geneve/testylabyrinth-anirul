#include "enemy_test.h"

namespace test {

	TEST_F(EnemyTest, CreateEnemyTest)
	{
		EXPECT_FALSE(enemy_);
		enemy_ = std::make_unique<Enemy>(std::make_pair<int, int>(10, 10));
		EXPECT_TRUE(enemy_);
	}

	TEST_F(EnemyTest, CharacterEnemyGetterTest)
	{
		EXPECT_FALSE(enemy_);
		enemy_ = std::make_unique<Enemy>(std::make_pair<int, int>(10, 10));
		EXPECT_TRUE(enemy_);
		EXPECT_EQ(10, enemy_->GetPosition().first);
		EXPECT_EQ(10, enemy_->GetPosition().second);
		EXPECT_EQ("Gob", enemy_->GetName());
	}

} // End namespace test.
