/*Given two strings s1 and s2, we want to visualize how different the two strings are. We will only take into account the lowercase letters (a to z). First let us count the frequency of each lowercase letters in s1 and s2.
s1 = "A aaaa bb c"
s2 = "& aaa bbb c d"
s1 has 4 'a', 2 'b', 1 'c'
s2 has 3 'a', 3 'b', 1 'c', 1 'd'

So the maximum for 'a' in s1 and s2 is 4 from s1; the maximum for 'b' is 3 from s2. In the following we will not consider letters when the maximum of their occurrences is less than or equal to 1.
We can resume the differences between s1 and s2 in the following string: "1:aaaa/2:bbb" where 1 in 1:aaaa stands for string s1 and aaaa because the maximum for a is 4. In the same manner 2:bbb stands for string s2 and bbb because the maximum for b is 3.
The task is to produce a string in which each lowercase letters of s1 or s2 appears as many times as its maximum if this maximum is strictly greater than 1; these letters will be prefixed by the number of the string where they appear with their maximum value and :. If the maximum is in s1 as well as in s2 the prefix is =:.
In the result, substrings (a substring is for example 2:nnnnn or 1:hhh; it contains the prefix) will be in decreasing order of their length and when they have the same length sorted in ascending lexicographic order (letters and digits - more precisely sorted by codepoint); the different groups will be separated by '/'. See examples and "Example Tests".
*/

#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2);
  static std::map<char, int> charFrequency(const std::string &str);
};

std::string Mix::mix(const std::string &s1, const std::string &s2)
{
  // Count frequency of characters in each string
  std::map<char, int> s1_counts = charFrequency(s1);
  std::map<char, int> s2_counts = charFrequency(s2);

  // Create substrings array
  std::vector<std::string> results;
  std::string range = "abcdefghijklmnopqrstuvwxyz";

  for (auto &c : range)
  {
    std::map<char, int>::iterator i_s1 = s1_counts.find(c);
    std::map<char, int>::iterator i_s2 = s2_counts.find(c);

    size_t s1_count = (islower(i_s1->first)) ? i_s1->second : 0;
    size_t s2_count = (islower(i_s2->first)) ? i_s2->second : 0;

    if (s1_count > s2_count)
    {
      if (s1_count > 1)
        results.push_back("1:" + std::string(s1_count, c));
    }
    else if (s1_count < s2_count)
    {
      if (s2_count > 1)
        results.push_back("2:" + std::string(s2_count, c));
    }
    else
    {
      if (s1_count > 1)
        results.push_back("=:" + std::string(s1_count, c));
    }
  }

  // Sort substring array by length lexicographically
  std::sort(results.begin(), results.end(), [](const std::string &s1, const std::string &s2) -> bool
  {
    return (s1.length() == s2.length()) ? s1 < s2 : s1.length() > s2.length();
  });

  // Assemble final string
  const char *separator = "";
  std::stringstream ss;

  for (auto &result : results)
  {
    ss << separator << result;
    separator = "/";
  }

  // Return result
  return ss.str();
}

// Count frequency of characters in a given string
std::map<char, int> Mix::charFrequency(const std::string &str)
{
  std::map<char, int> count;

  for (auto &c : str)
  {
    if (islower(c))
      count[c]++;
  }
  return count;
}
