/*In this kata you need to build a function to return either true/True or false/False if a string can be seen as the repetition of a simpler/shorter subpattern or not.

For example:

hasSubpattern("a") === false; //no repeated pattern
hasSubpattern("aaaa") === true; //created repeating "a"
hasSubpattern("abcd") === false; //no repeated pattern
hasSubpattern("abababab") === true; //created repeating "ab"
hasSubpattern("ababababa") === false; //cannot be entirely reproduced repeating a pattern
Strings will never be empty and can be composed of any character (just consider upper- and lowercase letters as different entities) and can be pretty long (keep an eye on performances!).*/

#include <string>

bool hasSubpattern(const std::string& str)
{
  unsigned long strLen = str.size();
  unsigned long subLen;
  std::string subStr;
  int count;
  for (std::size_t i = 1; i < strLen; i++)
  {
    if (strLen % i == 0)
    {
      subStr = str.substr(0, i);
      count = 0;
      for (std::size_t pos = 0; pos < strLen; pos+=i)
      {
        pos = str.find(subStr, pos);
        if (pos != std::string::npos)
          ++count;
        else
          break; 
      }
      subLen = subStr.size();
      if (count > 0)
        if (count * (int)subLen == (int)strLen)
          return true;
    }
  }
  return false;
}
