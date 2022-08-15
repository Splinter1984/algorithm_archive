/*
This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!

The arguments are passed as strings.
The numbers may be way very large
Answer should be returned as a string
The returned "number" should not start with zeros e.g. 0123 is invalid
*/

#include <iostream>
#include <algorithm>
#include <string>

std::string multiply(const std::string &a, const std::string &b) 
{
  return a.size() > b.size() ? multiply_longer_by_shorter(a, b)
                             : multiply_longer_by_shorter(b, a);
}

std::string add(std::string a, std::string b) 
{
  unsigned max_size = std::max(a.size(), b.size());
  a = std::string(max_size - a.size(), '0') + a;
  b = std::string(max_size - b.size(), '0') + b;
  std::string result;
  int buffer = 0;
  for (unsigned i = 1; i <= max_size; i++) 
  {
    buffer += char_to_int(a.at(max_size - i)) + char_to_int(b.at(max_size - i));
    result.insert(0, to_string(buffer % 10));
    buffer /= 10;
  }
  if (buffer > 0)
    result.insert(0, to_string(buffer));
  
  return result;
}

std::string multiply_longer_by_shorter(const std::string &longer, const std::string &shorter) 
{
  std::string result = "0";
  for (unsigned i = 0; i < shorter.size(); i++) 
  {
    char digit = shorter.at(shorter.size() - i - 1);
    std::string subresult =
        multiply_by_power_of_ten(multiply_by_single_digit(longer, digit), i);
    result = add(result, subresult);
  }
  
  return result;
}

std::string multiply_by_power_of_ten(const std::string &number, unsigned n) 
{
  return number + std::string(n, '0');
}

std::string multiply_by_single_digit(const std::string &number, char single_digit) 
{
  int right_factor = char_to_int(single_digit);
  std::string result;
  int buffer = 0;
  
  for (auto it = std::rbegin(number); it != std::rend(number); it++) 
  {
    int left_factor = char_to_int(*it);
    buffer += left_factor * right_factor;
    result.insert(0, to_string(buffer % 10));
    buffer /= 10;
  }
  
  if (buffer > 0)
    result.insert(0, to_string(buffer));

  result = strip_leading_zeros(result);

  return result;
}

std::string strip_leading_zeros(std::string number) 
{
  while (number.at(0) == '0' and number.size() > 1) 
    number.erase(std::begin(number));
  return number;
}

int char_to_int(char single_digit) 
{ 
  return single_digit - '0'; 
}
