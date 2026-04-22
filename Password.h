#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>

using std::string;

class Password
{
private:
  

public:
  /*
  The function receives a string and counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
  */
  int count_leading_characters(string word);
  

  /*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
  */
  bool has_mixed_case(string);

  /* Receives a string and returns a count of how many case-sensitive unique characters there are. If there are duplicate instances of the same character it should only count as a single character. Even if characters look similar, as long as they have distinct ASCII values, they should qualify as unique characters. */
  unsigned int unique_characters(string);
};
#endif
