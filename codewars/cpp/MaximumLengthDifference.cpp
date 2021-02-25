/*You are given two arrays a1 and a2 of strings. Each string is composed with letters from a to z. Let x be any string in the first array and y be any string in the second array.

Find max(abs(length(x) − length(y)))

If a1 and/or a2 are empty return -1 in each language except in Haskell (F#) where you will return Nothing (None).

Example:
a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
mxdiflg(a1, a2) --> 13
Bash note:
input : 2 strings with substrings separated by ,
output: number as a string*/

class MaxDiffLength
{
  private:
    static size_t max_line_length(std::vector<std::string> const &lines)
    {
        return std::max_element(lines.begin(), lines.end(), [](const auto& a, const auto& b){return a.size() < b.size();})->size(); 
    }

    static size_t min_line_length(std::vector<std::string> const &lines)
    {
        return std::max_element(lines.begin(), lines.end(), [](const auto& a, const auto& b){return a.size() > b.size();})->size(); 
    }

  public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2)
    {
      if (a1.empty() || a2.empty())
        return -1;
      unsigned int step1 = max_line_length(a1) - min_line_length(a2);
      unsigned int step2 = max_line_length(a2) - min_line_length(a1);
      if (step1 > step2)
        return step1;
      else
        return step2;
    }
};
