/*
Given a string of words, you need to find the highest scoring word.
Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.
You need to return the highest scoring word as a string.
If two words score the same, return the word that appears earliest in the original string.
All letters will be lowercase and all inputs will be valid.
*/

#include <string>
#include <utility>

std::string highestScoringWord(const std::string &str)
{
  auto s = str + " ";
  auto result = std::make_pair<std::string, std::uint64_t>("", 0);
  auto tmp_result = result;
  
  for (auto it = s.begin(); it != s.end(); ++it)
  {
    if (tmp_result.second > result.second)
        result = tmp_result;
    
    if (*it == ' ')
    {
      tmp_result = std::make_pair<std::string, std::uint64_t>("", 0);
    } else {   
      tmp_result.first += *it;
      tmp_result.second += (std::uint64_t)*it - 96;
    }
  }
  
  return result.first;
}
