/*Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements with the same value next to each other and preserving the original order of elements.

For example:

uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}*/

#include <string>
#include <vector>

template <typename T> 
std::vector<T> uniqueInOrder(const std::vector<T>& iterable)
{
  std::vector<T> res;
  if (!iterable.empty())
  {
    res.push_back(iterable.front());
    for (size_t i = 1; i < iterable.size(); i++)
    {
      if (res.back() != iterable[i])
      {
        res.push_back(iterable[i]);
      }
    }
  }
  return res;
}
std::vector<char> uniqueInOrder(const std::string& iterable)
{
  std::vector<char> res;
  if (!iterable.empty())
  {
    res.push_back(iterable.front());
    for (size_t i = 1; i < iterable.size(); i++)
    {
      if (res.back() != iterable[i])
      {
        res.push_back(iterable[i]);
      }
    }
  }
  return res;
}
