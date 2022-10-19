/*
Given an array (arr) as an argument complete the function countSmileys that should return the total number of smiling faces.

Rules for a smiling face:

Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
Every smiling face must have a smiling mouth that should be marked with either ) or D
No additional characters are allowed except for those mentioned.

Valid smiley face examples: :) :D ;-D :~)
Invalid smiley faces: ;( :> :} :]
*/

#include <map>

int countSmileys(std::vector<std::string> arr)
{
  std::map<std::string, int> result = {
    {":)", 0}, {":D", 0}, {";-D", 0}, {":~)", 0},
    {";)", 0}, {";D", 0}, {";~D", 0}, {":-)", 0},
                          {":-D", 0}, {";-)", 0},
                          {":~D", 0}, {";~)", 0}
  };
  
  for (const auto& smile: arr)
  {
    auto it = result.find(smile);
    if (it != result.end())
      it->second += 1;
  }
  
  int res = 0;
  for (const auto& smile: result)
    res += smile.second;
  
  return res;
}
