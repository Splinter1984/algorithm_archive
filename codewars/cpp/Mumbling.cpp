/*This time no story, no theory. The examples below show you how to write function accum:

Examples:

accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z.*/

class Accumul
{
public:
    static std::string accum(const std::string &s)
    {
      std::string res;
      for (int i = 0; i < s.length(); i++)
      {
        res.append("-");
        res.append(std::string(1, toupper(s[i])));
        res.append(std::string(i, tolower(s[i])));
      }
      return res.substr(1, res.length());
    }
};
