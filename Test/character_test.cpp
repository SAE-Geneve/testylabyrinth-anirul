#include "character_test.h"

namespace test {

	TEST_F(CharacterTest, CreationTest) 
	{
		EXPECT_FALSE(character_);
		character_ = std::make_unique<Character>(
			std::make_pair<int, int>(0,0), 
			10, 
			10, 
			10, 
			"test");
		EXPECT_TRUE(character_);
	}

	TEST_F(CharacterTest, GetSetPositionTest)
	{
		EXPECT_FALSE(character_);
		character_ = std::make_unique<Character>(
			std::make_pair<int, int>(0, 0),
			10,
			10,
			10,
			"test");
		EXPECT_EQ(0, character_->GetPosition().first);
		EXPECT_EQ(0, character_->GetPosition().second);
		character_->SetPosition({10, 20});
		EXPECT_EQ(10, character_->GetPosition().first);
		EXPECT_EQ(20, character_->GetPosition().second);
		EXPECT_TRUE(character_);
	}

	TEST_F(CharacterTest, AttackIsDeadTest)
	{
		EXPECT_FALSE(character_);
		character_ = std::make_unique<Character>(
			std::make_pair<int, int>(0, 0),
			100,
			100,
			10,
			"test");
		{
			Character enemy({0, 1}, 10, 10, 10, "Enemy");
			character_->Attack(enemy);
			EXPECT_TRUE(enemy.IsDead());
		}
		{
			Character enemy({10, 20}, 10, 10, 10, "Too far");
			character_->Attack(enemy);
			EXPECT_FALSE(enemy.IsDead());
		}
		EXPECT_TRUE(character_);
	}

	TEST_F(CharacterTest, DistanceTest)
	{
		EXPECT_FALSE(character_);
		character_ = std::make_unique<Character>(
			std::make_pair<int, int>(0, 0),
			10,
			10,
			10,
			"test");
		{
			Character enemy({ 0, 1 }, 10, 10, 10, "Enemy");
			EXPECT_EQ(1.0, character_->Distance(enemy));
		}
		{
			Character enemy({ 0, 20 }, 10, 10, 10, "Too far");
			EXPECT_EQ(20.0, character_->Distance(enemy));
		}
		EXPECT_TRUE(character_);
	}

	TEST_F(CharacterTest, HealthPointAccessorTest)
	{
		EXPECT_FALSE(character_);
		character_ = std::make_unique<Character>(
			std::make_pair<int, int>(0, 0),
			10,
			10,
			10,
			"test");
		EXPECT_EQ(10, character_->GetHealthPoints());
		character_->SetHealthPoints(100);
		EXPECT_EQ(100, character_->GetHealthPoints());
		EXPECT_TRUE(character_);
	}

	TEST_F(CharacterTest, ReadOnlyAccessorsTest)
	{
		EXPECT_FALSE(character_);
		character_ = std::make_unique<Character>(
			std::make_pair<int, int>(0, 0),
			11,
			12,
			13,
			"test4");
		EXPECT_EQ(12, character_->GetAttack());
		EXPECT_EQ(13, character_->GetDefence());
		EXPECT_EQ("test4", character_->GetName());
		EXPECT_TRUE(character_);
	}

}