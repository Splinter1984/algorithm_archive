/*Task
Given a string str, reverse it omitting all non-alphabetic characters.

Example
For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".

Input/Output
[input] string str

A string consists of lowercase latin letters, digits and symbols.

[output] a string*/

#include <string>
#include <algorithm> 

std::string reverse_letter(const std::string &str)
{
    if (str == "")
        return "";
    std::string res="";
    for (char ch:str)
    {
        if(ch >= 'a' && ch <= 'z')
            res+=ch;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
