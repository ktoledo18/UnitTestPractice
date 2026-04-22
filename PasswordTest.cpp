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

//______________________________________________________________________________

TEST(PasswordTest, hasMixedCase_onlyLowercase_returnsFalse)
{
    Password pw;
    ASSERT_FALSE(pw.has_mixed_case("abcde"));
}

TEST(PasswordTest, hasMixedCase_onlyUppercase_returnsFalse)
{
    Password pw;
    ASSERT_FALSE(pw.has_mixed_case("ABCDE"));
}

TEST(PasswordTest, hasMixedCase_upperThenLower_returnsTrue)
{
    Password pw;
    ASSERT_TRUE(pw.has_mixed_case("Aabc"));
}

TEST(PasswordTest, hasMixedCase_lowerThenUpper_returnsFalse)
{
    Password pw;
    ASSERT_TRUE(pw.has_mixed_case("abcA"));
}

//______________________________________________________________________________

TEST(PasswordTest, uniqueCharacters_emptyString_returnsZero)
{
    Password pw;
    ASSERT_EQ(0, pw.unique_characters(""));
}

TEST(PasswordTest, uniqueCharacters_singleCharacter_returnsOne)
{
    Password pw;
    ASSERT_EQ(1, pw.unique_characters("x"));
}

TEST(PasswordTest, uniqueCharacters_allDuplicateCharacters_returnsOne)
{
    Password pw;
    ASSERT_EQ(1, pw.unique_characters("aaaaaa"));
}

TEST(PasswordTest, uniqueCharacters_allUniqueCharacters_returnsLength)
{
    Password pw;
    ASSERT_EQ(6, pw.unique_characters("abcdef"));
}

TEST(PasswordTest, uniqueCharacters_mixedDuplicates_returnsCorrectCount)
{
    Password pw;
    ASSERT_EQ(3, pw.unique_characters("aabcc"));
}

TEST(PasswordTest, uniqueCharacters_caseSensitive_countsSeparately)
{
    Password pw;
    ASSERT_EQ(2, pw.unique_characters("aA"));
}

TEST(PasswordTest, uniqueCharacters_numbersAreCounted)
{
    Password pw;
    ASSERT_EQ(4, pw.unique_characters("1122334"));
}

TEST(PasswordTest, uniqueCharacters_symbolsAreCounted)
{
    Password pw;
    ASSERT_EQ(3, pw.unique_characters("!@!#"));
}

TEST(PasswordTest, uniqueCharacters_mixedTypes_countsAllUnique)
{
    Password pw;
    ASSERT_EQ(4, pw.unique_characters("aA1!aA"));
}