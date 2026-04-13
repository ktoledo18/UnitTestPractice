/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, aab_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aab"));
}

TEST(PasswordTest, a_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("a"));
}

TEST(PasswordTest, Aaab_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Aaab"));
}

TEST(PasswordTest, percent_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("%%ab"));
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters(""));
}

//__________________________________________________________________________________________________________________________

TEST(PasswordTest, one_and_one_password)
{
	Password my_password;
	ASSERT_TRUE(my_password.count_leading_characters("Ab"));
}

TEST(PasswordTest, no_cap__password)
{
	Password my_password;
	ASSERT_TRUE(my_password.count_leading_characters("bb"));
}

TEST(PasswordTest, no_lower_password)
{
	Password my_password;
	ASSERT_TRUE(my_password.count_leading_characters("AA"));
}

TEST(PasswordTest, hard_password)
{
	Password my_password;
	ASSERT_TRUE(my_password.count_leading_characters("%*%#*(/[,.]/;/*"));
}
