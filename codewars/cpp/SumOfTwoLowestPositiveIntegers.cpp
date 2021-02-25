/*Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.*/

#include <vector>
#include <algorithm>

const int NUM_VAL = 2;

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    long res=0;
    for(int i=0; i < NUM_VAL; i++)
    {
      auto tmp = std::min_element(numbers.begin(), numbers.end());
      res+=*tmp;
      std::iter_swap(tmp, numbers.end() - 1);
      numbers.erase(numbers.end() - 1);
    }
    return res;
}
