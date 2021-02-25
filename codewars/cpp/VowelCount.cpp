/*Return the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lower case letters and/or spaces.*/

#include <string>

int getCount(const std::string& inputStr){
  if (inputStr == "")
    return 0;
  std::string lib = "aeiou";
  int num_vowels = 0;
  for (char sym: inputStr)
    if(lib.find(sym) != std::string::npos)
      num_vowels++;
  return num_vowels;
}
