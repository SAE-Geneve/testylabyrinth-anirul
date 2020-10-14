#include "world_test.h"

namespace test {

	TEST_F(WorldTest, CreateWorldTest)
	{
		EXPECT_FALSE(world_);
		world_ = std::make_unique<World>();
		EXPECT_TRUE(world_);
	}

	TEST_F(WorldTest, HasEnemiesTest)
	{
		EXPECT_FALSE(world_);
		world_ = std::make_unique<World>();
		EXPECT_TRUE(world_);
		EXPECT_TRUE(world_->HasEnemies());
		{
			World world2(
				"###"
				"#P#"
				"###", 
				3);
			EXPECT_FALSE(world2.HasEnemies());
		}
	}

	TEST_F(WorldTest, CannotMoveTest)
	{
		EXPECT_FALSE(world_);
		world_ = std::make_unique<World>(
			"###"
			"#P#"
			"###", 
			3);
		EXPECT_TRUE(world_);
		{
			auto pos = world_->North(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second, pos.second);
		}
		{
			auto pos = world_->South(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second, pos.second);
		}
		{
			auto pos = world_->West(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second, pos.second);
		}
		{
			auto pos = world_->East(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second, pos.second);
		}
	}
	
	TEST_F(WorldTest, CanMoveTest)
	{
		EXPECT_FALSE(world_);
		world_ = std::make_unique<World>(
			"#####"
			"#...#"
			"#.P.#"
			"#...#"
			"#####", 5);
		EXPECT_TRUE(world_);
		{
			auto pos = world_->North(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second - 1, pos.second);
		}
		{
			auto pos = world_->South(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second + 1, pos.second);
		}
		{
			auto pos = world_->West(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first - 1, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second, pos.second);
		}
		{
			auto pos = world_->East(world_->GetHero());
			EXPECT_EQ(world_->GetHero().GetPosition().first + 1, pos.first);
			EXPECT_EQ(world_->GetHero().GetPosition().second, pos.second);
		}
	}

	TEST_F(WorldTest, HeroCanKillTest)
	{
		EXPECT_FALSE(world_);
		world_ = std::make_unique<World>(
			"#####"
			"#.E.#"
			"#.P.#"
			"#...#"
			"#####", 5);
		EXPECT_TRUE(world_);
		int i = 0;
		while (world_->HasEnemies())
		{
			world_->HeroAttack();
			world_->EraseDead();
			if (++i > 50) break;
		}
		EXPECT_LT(i, 50);
		EXPECT_FALSE(world_->HasEnemies());
	}

	TEST_F(WorldTest, EnemyCanKillTest)
	{
		EXPECT_FALSE(world_);
		world_ = std::make_unique<World>(
			"#####"
			"#.E.#"
			"#.P.#"
			"#...#"
			"#####", 5);
		EXPECT_TRUE(world_);
		int i = 0;
		while (!world_->GetHero().IsDead())
		{
			world_->EnemyAttack();
			world_->EraseDead();
			if (++i > 50) break;
		}
		EXPECT_LT(i, 50);
		EXPECT_TRUE(world_->GetHero().IsDead());
	}

} // End namespace test.