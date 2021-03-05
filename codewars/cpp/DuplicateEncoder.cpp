/*The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" */

#include <string>
#include <algorithm>
std::string duplicate_encoder(const std::string& word){
  if (word == "")
    return "";
  std::string res = "";
  std::string tmp;
  tmp.resize(word.size());
  std::transform(word.begin(), word.end(), tmp.begin(), ::tolower);
  for (char sym: tmp)
  {
    size_t cou=std::count( tmp.begin(), tmp.end(), sym);
    if (cou > 1)
      res+=")";
    else
      res+="(";
  }
  return res;
}
