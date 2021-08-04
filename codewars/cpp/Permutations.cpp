/*Description:

In this kata you have to create all permutations of an input string and remove duplicates, if present. This means, you have to shuffle all letters from the input in all possible orders.

Examples:

permutations("a"); // => vector<string> {"a"}
permutations("ab"); // => vector<string> {"ab", "ba"}
permutations("aabb"); // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}

The order of the permutations doesn't matter.*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
 
void permute(size_t id, std::string &str, std::vector<std::string> *res)
{
    if (id == (str.length() - 1)) {
        res->push_back(str);
        return;
    }
   
    char prev = '*';
   
    for (size_t j = id; j < str.length(); j++) {
        std::string temp = str;
        if (j > id && temp[id] == temp[j])
            continue;
        if (prev != '*' && prev == str[j]) {
            continue;
        }
       
        std::swap(temp[id], temp[j]);
        prev = str[j];
       
        permute(id + 1, temp, res);
    }
}

std::vector<std::string> permutations(std::string str)
{
    if (str.length() == 0)
        return std::vector<std::string> {""};
    std::vector<std::string> res;
    std::sort(str.begin(), str.end());
    permute(0, str, &res);
    return res;
}
