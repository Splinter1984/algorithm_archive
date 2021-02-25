/*The vowel substrings in the word codewarriors are o,e,a,io. The longest of these has a length of 2. Given a lowercase string that has alphabetic characters only (both vowels and consonants) and no spaces, return the length of the longest vowel substring. Vowels are any of aeiou.

Good luck!*/

#include <iostream>
#include <string> 

bool is_vowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int solve(std::string s)
{
    int res = 0;
    std::string str;
    for (char ch : s)
    {
        if (is_vowel(ch))
        {
            str+=ch;
            if (str.size() > res)
            {
                res = str.size();
            }
        }else{
            str="";
        }
    }
    return res;
}
