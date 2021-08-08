/*Description:
We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.

Example
add("123", "321"); -> "444"
add("11", "99");   -> "110"
Notes
The input numbers are big.
The input is a string of only digits
The numbers are positives*/

#include <string>
#include <algorithm>

std::string add(const std::string& str_1, const std::string& str_2)
{
  std::string str1 = str_1, str2 = str_2;
  
  if (str1.size() > str2.size())
    std::swap(str1, str2);
  
  std::string result = "";

  long long len1, len2, diff;
  len1 = str1.size();
  len2 = str2.size();
  diff = len2 - len1;
  int carry = 0;

  for (long long i = len1-1; i >= 0; i--)
  {
    int sum = str1.at(i)- '0' + str2.at(i+diff) - '0' + carry;
    result.push_back(sum%10 + '0');
    carry = sum/10;
  }

  for (long long i = len2-len1-1; i >= 0; i--)
  {
    int sum = str2.at(i) - '0' + carry;
    result.push_back(sum%10 + '0');
    carry = sum/10;
  }

  if (carry)
    result.push_back(carry + '0');

  std::reverse(result.begin(), result.end());
  return result;
}
