/*"A divisibility rule is a shorthand way of determining whether a given integer is divisible by a fixed divisor without performing the division, usually by examining its digits."

When you divide the successive powers of 10 by 13 you get the following remainders of the integer divisions:

1, 10, 9, 12, 3, 4 because:

10 ^ 0 ->  1 (mod 13)
10 ^ 1 -> 10 (mod 13)
10 ^ 2 ->  9 (mod 13)
10 ^ 3 -> 12 (mod 13)
10 ^ 4 ->  3 (mod 13)
10 ^ 5 ->  4 (mod 13)
(For "mod" you can see: https://en.wikipedia.org/wiki/Modulo_operation)

Then the whole pattern repeats. Hence the following method:

Multiply

the right most digit of the number with the left most number in the sequence shown above,
the second right most digit with the second left most digit of the number in the sequence.
The cycle goes on and you sum all these products. Repeat this process until the sequence of sums is stationary.*/

#include <cassert>
class Thirteen
{
public:
    static const std::vector<int> nums;
    static long long thirt(long long n);
};

const std::vector<int> Thirteen::nums = {1, 10, 9, 12, 3, 4};

long long Thirteen::thirt (long long n)
{
  const long long orig = n;
  long long result = 0;
  std::size_t set_pose = 0;
  
  while (n > 0)
  {
    const auto qr = std::lldiv(n, 10);
    result+= qr.rem * nums[set_pose];
    set_pose = (set_pose + 1) % nums.size();
    n = qr.quot;
  }
  return result == orig ? result : thirt(result);
}
