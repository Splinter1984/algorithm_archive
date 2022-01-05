/*
Description:
We all know that any integer number n is divisible by 1 and n. That is why these two numbers are not the actual divisors of any numbers. 
The function SOD(n) (sum of divisors) is defined as the summation of all the actual divisors of an integer number n. For example: SOD(24) = 2+3+4+6+8+12 = 35.
The function CSOD(n) (cumulative SOD) of an integer n, is defined as below:
csod(n) = sum(sod(i)) [i = from 1 to n]
Given the value of n, your job is to find the value of CSOD(n).
*/

#include <cmath>

uint64_t newFunction(const uint64_t n)
{
  uint64_t result = 0;
  for (uint64_t i = 2; i <= sqrt(n); ++i)
  {
    uint64_t j = n / i;
    result += (i + j) * (j - i + 1) / 2;
    result += i * (j - i);
  }
  return result;
}
