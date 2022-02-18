/*
Description:
Your task in order to complete this Kata is to write a function which formats a duration, given as a number of seconds, in a human-friendly way.
The function must accept a non-negative integer. If it is zero, it just returns "now". 
Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

* For seconds = 62, your function should return 
    "1 minute and 2 seconds"
* For seconds = 3662, your function should return
    "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.

Detailed rules
The resulting expression is made of components like 4 seconds, 1 year, etc. In general, a positive integer and one of the valid units of time, separated by a space. 
The unit of time is used in plural if the integer is greater than 1.
The components are separated by a comma and a space (", "). Except the last component, which is separated by " and ", just like it would be written in English.
A more significant units of time will occur before than a least significant one. Therefore, 1 second and 1 year is not correct, but 1 year and 1 second is.
Different components have different unit of times. So there is not repeated units like in 5 seconds and 1 second.
A component will not appear at all if its value happens to be zero. Hence, 1 minute and 0 seconds is not valid, but it should be just 1 minute.
A unit of time must be used "as much as possible". It means that the function should not return 61 seconds, but 1 minute and 1 second instead. 
Formally, the duration specified by of a component must not be greater than any valid more significant unit of time.
*/

#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <tuple>

std::pair<std::string, int> format_time_pair(const std::string format, const int& time)
{
        std::string pre_format = format;
        if (time > 1)
        {
                pre_format += 's';
        }

        return std::make_pair(pre_format, time);
}

std::string format_duration(int seconds)
{
        if (seconds == 0)
        {
                return "now";
        }

        std::map<std::string, int> format_time = {
                {"year", 0},
                {"day", 0},
                {"hour", 0},
                {"minute", 0},
                {"second", 0}
        };
        std::vector<std::pair<std::string, int>> keys_format = {
                {"year", 31536000},
                {"day", 86400},
                {"hour", 3600},
                {"minute", 60},
                {"second", 0}
        };

        std::vector<std::pair<std::string, int>> result;

        for (auto key = keys_format.begin(); key != keys_format.end(); key++)
        {
                if (seconds >= key->second)
                {
                        if (key->first ==  "second")
                        {
                                format_time.at(key->first) = seconds;
                        } else {

                                format_time.at(key->first) = std::floor(seconds / key->second);
                                seconds %= key->second;
                        }
                        if (format_time.at(key->first) != 0)
                        {
                                result.push_back(format_time_pair(key->first, format_time.at(key->first)));
                
                        }
        
                }
        }
        std::string res;

        if (result.size() ==  1)
        {
                res = std::to_string(result.back().second) + " " + result.back().first;
        } else if (result.size() ==  2) {
                res = std::to_string(result.front().second) + " " + result.front().first +
                        " and " + std::to_string(result.back().second) + " " + result.back().first;
        } else {
                for (size_t i = 0; i < result.size() - 2; i++)
                {
                        res += std::to_string(result[i].second) + " " + result[i].first + ", ";
                }
                res += std::to_string(result[result.size()-2].second) + " " + result[result.size()-2].first +
                        " and " + std::to_string(result.back().second) + " " + result.back().first;
        }

        return res;
}
