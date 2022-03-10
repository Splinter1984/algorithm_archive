/*
Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

Examples
pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !
*/

#include <string>
#include <vector>
#include <iterator>
#include <sstream>

std::string pig_it(const std::string& s)
{
        std::string div = "ay";
        std::istringstream iss(s);
        std::vector<std::string> str_lib(std::istream_iterator<std::string>{iss},
                                                                         std::istream_iterator<std::string>());

        std::string result = "";
        for (auto word = str_lib.begin(); word != str_lib.end(); ++word)
        {
                if (std::isalpha(word->at(0)))
                {
                      size_t len = word->size();
                      result += word->substr(1, len-1) + word->at(0);
                      result += div;
                } else {
                      result += *word;
                }

                if (word+1 != str_lib.end())
                        result += " ";
        }

        return result;
}
