/*
Input
    a string strng of n positive numbers (n = 0 or n >= 2)
Let us call weight of a number the sum of its digits. For example 99 will have "weight" 18, 100 will have "weight" 1.
Two numbers are "close" if the difference of their weights is small.
Task:
For each number in strng calculate its "weight" and then find two numbers of strng that have:
    the smallest difference of weights ie that are the closest
    with the smallest weights
    and with the smallest indices (or ranks, numbered from 0) in strng

Output:
    an array of two arrays, each subarray in the following format:
[number-weight, index in strng of the corresponding number, original corresponding number in strng]
or a pair of two subarrays (Haskell, Clojure, FSharp) or an array of tuples (Elixir, C++)
or a (char*) in C or a string in some other languages mimicking an array of two subarrays or a string
or a matrix in R (2 rows, 3 columns, no columns names)
The two subarrays are sorted in ascending order by their number weights if these weights are different, by their indexes in the string if they have the same weights.
Examples:
Let us call that function closest

strng = "103 123 4444 99 2000"
the weights are 4, 6, 16, 18, 2 (ie 2, 4, 6, 16, 18)

closest should return [[2, 4, 2000], [4, 0, 103]] (or ([2, 4, 2000], [4, 0, 103])
or [{2, 4, 2000}, {4, 0, 103}] or ... depending on the language)
because 2000 and 103 have for weight 2 and 4, their indexes in strng are 4 and 0.
The smallest difference is 2.
4 (for 103) and 6 (for 123) have a difference of 2 too but they are not 
the smallest ones with a difference of 2 between their weights.
....................

strng = "80 71 62 53"
All the weights are 8.
closest should return [[8, 0, 80], [8, 1, 71]]
71 and 62 have also:
- the smallest weights (which is 8 for all)
- the smallest difference of weights (which is 0 for all pairs)
- but not the smallest indices in strng.
....................
*/

#include <vector>
#include <string>
#include <regex>
#include <cmath>

namespace Closest
{
    std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string& str)
    {
      if (str.empty())
        return {{0, 0, 0}, {0, 0, 0}};

      static const std::regex rdelim{" "};
      std::vector<std::string> numbers{ std::sregex_token_iterator(str.begin(), str.end(), rdelim, -1), std::sregex_token_iterator() };

      std::vector<std::tuple<int, unsigned int, long long>> numbers_lib;

      int count = 0;
      for (const auto num: numbers)
      {
        int weight = 0;
        std::for_each( num.begin(), num.end(), [&weight](const char ch) { weight+=ch - '0'; });

        long long number = std::stoll(num);
        auto item = std::make_tuple(weight,count, number);
        numbers_lib.insert( std::upper_bound(numbers_lib.begin(), numbers_lib.end(), item, [](auto val1, const auto &val2){ 
          return std::get<0>(val1) < std::get<0>(val2);}),
          item
        );
        count++;
      }

      auto res_pair = std::make_pair(numbers_lib.at(0), numbers_lib.at(1));
      for (const auto& it1: numbers_lib)
      {
        for (const auto& it2: numbers_lib)
        {
            if (it1 != it2 && std::abs(std::get<0>(it1) - std::get<0>(it2)) < std::abs(std::get<0>(res_pair.first) - std::get<0>(res_pair.second)))
              res_pair = std::make_pair(it1, it2);
        }
      }
      return std::vector<std::tuple<int, unsigned int, long long>>{res_pair.first, res_pair.second};
    }
}
