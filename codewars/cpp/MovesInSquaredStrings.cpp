/*This kata is the first of a sequence of four about "Squared Strings".

You are given a string of n lines, each substring being n characters long: For example:

s = "abcd\nefgh\nijkl\nmnop"

We will study some transformations of this square of strings.

Vertical mirror: vert_mirror (or vertMirror or vert-mirror)
vert_mirror(s) => "dcba\nhgfe\nlkji\nponm"
Horizontal mirror: hor_mirror (or horMirror or hor-mirror)
hor_mirror(s) => "mnop\nijkl\nefgh\nabcd"
or printed:

vertical mirror   |horizontal mirror   
abcd --> dcba     |abcd --> mnop 
efgh     hgfe     |efgh     ijkl 
ijkl     lkji     |ijkl     efgh 
mnop     ponm     |mnop     abcd 
Task:
Write these two functions
and

high-order function oper(fct, s) where

fct is the function of one variable f to apply to the string s (fct will be one of vertMirror, horMirror)

Examples:
s = "abcd\nefgh\nijkl\nmnop"
oper(vert_mirror, s) => "dcba\nhgfe\nlkji\nponm"
oper(hor_mirror, s) => "mnop\nijkl\nefgh\nabcd"
Note:
The form of the parameter fct in oper changes according to the language. You can see each form according to the language in "Sample Tests".

Bash Note:
The input strings are separated by , instead of \n. The output strings should be separated by \r instead of \n. See "Sample Tests".

Forthcoming katas will study other transformations.*/

#include <string>
#include <vector>
#include <algorithm>

class Opstrings
{
private:
    
    static std::string toStrConvert(const std::vector<std::string> &res)
    {
        std::string str = "";
        for (auto strngg: res)
            str+=strngg + "\n";
        return str.substr(0, str.length()-1);
    }
    
    static void dataAdd(const std::string &strng, std::vector<std::string> &res)
    {
        std::string sym ("\n");
        std::size_t prev = 0;
        std::size_t next = 0;
        while (next != std::string::npos)
        {
            next = strng.find(sym, prev);
            res.push_back(strng.substr(prev, next - prev));
            prev = next + sym.length();
        }   
    }
    
public:
    
    static std::string vertMirror(const std::string &strng)
    {
        std::vector<std::string> res;
        dataAdd(strng, res);
        for (int i = 0;  i < (int)res.size(); i++)
            std::reverse(res[i].begin(), res[i].end());
        return toStrConvert(res);
    }

    static std::string horMirror(const std::string &strng)
    {
        std::vector<std::string> res;
        dataAdd(strng, res);
        std::reverse(res.begin(), res.end());
        return toStrConvert(res);
    }
    
    static std::string oper(std::string (func)(const std::string &), const std::string &s)
    {
      return func(s);  
    }
};
