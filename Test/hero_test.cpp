#include "hero_test.h"

namespace test {

	TEST_F(HeroTest, CreateHeroTest)
	{
		EXPECT_FALSE(hero_);
		hero_ = std::make_unique<Hero>(std::make_pair<int, int>(10, 10));
		EXPECT_TRUE(hero_);
	}

	TEST_F(HeroTest, CharacterHeroGetterTest)
	{
		EXPECT_FALSE(hero_);
		hero_ = std::make_unique<Hero>(std::make_pair<int, int>(10, 10));
		EXPECT_TRUE(hero_);
		EXPECT_EQ(10, hero_->GetPosition().first);
		EXPECT_EQ(10, hero_->GetPosition().second);
		EXPECT_EQ("Gurdil", hero_->GetName());
	}

	TEST_F(HeroTest, RegenTest)
	{
		EXPECT_FALSE(hero_);
		hero_ = std::make_unique<Hero>(std::make_pair<int, int>(10, 10));
		EXPECT_TRUE(hero_);
		hero_->Regen();
		EXPECT_EQ(100, hero_->GetHealthPoints());
		hero_->SetHealthPoints(10);
		hero_->Regen();
		EXPECT_EQ(15, hero_->GetHealthPoints());
	}

} // End namespace test.