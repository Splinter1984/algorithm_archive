/*
A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more characters. 
The 1st character of a code is a capital letter which defines the book category.
In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.
For example an extract of a stocklist could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or
L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :

M = {"A", "B", "C", "W"} 
or
M = ["A", "B", "C", "W"] or ...
and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.
For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket a list of pairs):

(A : 20) - (B : 114) - (C : 50) - (W : 0)
where A, B, C, W are the categories, 20 is the sum of the unique book of category 
A, 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.
If L or M are empty return string is "" (Clojure and Racket should return an empty array/list instead).

Note:
In the result codes and their values are in the same order as in M.
*/

#include <vector>
#include <map>
#include <string>
#include <sstream>

class StockList
{
protected:
    static unsigned stringToUnsigned(const std::string& str)
    {
        int dim = 1, result = 0;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            result += ((unsigned)str[i] - (unsigned)'0') * dim;
            dim *= 10;
        }

        return result;
    }

public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
    {
        if (categories.empty() || lstOfArt.empty())
        {
            return "";
        }

        const char DIV_SYM = ' ';
        std::map<std::string, unsigned> lib;
        for (std::string str : lstOfArt)
        {
            std::size_t pos = str.find(DIV_SYM);
            std::string tmp_str = str.substr(pos + 1);
            int k = 1, key = 0;
            lib.insert(std::pair<std::string, int>(str.substr(0, pos), stringToUnsigned(tmp_str)));
        }

        std::vector<std::pair<std::string, unsigned>> cat;
        std::ostringstream stre;
        std::string str;
        for (auto sym : categories)
        {
            unsigned tmp = 0;
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->first.find(sym) == 0)
                {
                    tmp += it->second;
                }
            }
            cat.push_back(std::pair<std::string, unsigned>(sym, tmp));
        }
        for (auto it = cat.begin(); it != cat.end(); it++)
            stre << '(' << it->first << " : " << it->second << ") - ";
        str = stre.str();
        return str.substr(0, str.size() - 3);
    }
};
