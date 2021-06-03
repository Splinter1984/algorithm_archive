/*Format any integer provided into a string with "," (commas) in the correct places.

Example:

numberFormat(100000); // return '100,000'
numberFormat(5678545); // return '5,678,545'
numberFormat(-420902); // return '-420,902'*/

#include <string>
#include <algorithm>

std::string numberFormat(long long n)
{
  if (abs(n) < 1000)
    return std::to_string(n);
  
  std::string res;
  std::string tmp_str = std::to_string(n);
  std::reverse(tmp_str.begin(), tmp_str.end());
  unsigned step_key = 0;
  for (auto it = tmp_str.begin(); it != tmp_str.end(); it++)
  {
    if (step_key == 3 && *it != '-' && *it != '+')
    {
      res+=",";
      step_key=0;
    }
    res+=*it;
    step_key+=1;
  }
  std::reverse(res.begin(), res.end());
  return res;
}
