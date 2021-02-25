/*A new task for you!

You have to create a method, that corrects a given time string.
There was a problem in addition, so many of the time strings are broken.
Time is formatted using the 24-hour clock, so from 00:00:00 to 23:59:59.
Examples
"09:10:01" -> "09:10:01"  
"11:70:10" -> "12:10:10"  
"19:99:99" -> "20:40:39"  
"24:01:01" -> "00:01:01"  
If the input-string is null or empty return exactly this value! (empty string for C++) If the time-string-format is invalid, return null. (empty string for C++)

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have created other katas. Have a look if you like coding and challenges.*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

std::string correct(std::string timeString)
{
    if (timeString.size() != 8){
        return "";
    }

    std::string newTimeString;
    remove_copy(timeString.begin(), timeString.end(), back_inserter(newTimeString), ':');
    std::vector<int> num;
    std::string endTimeString = "";
    int tmp, tmp2, tmp3, tmp4, tmp5;
    int j = 0;
    
    if (newTimeString.size() > 6)
    {
        return "";
    }

    for (int i=0; i < newTimeString.size() - 1; i+=2)
    {
        j+=1;
        tmp4 = (int)newTimeString[i] - (int)'0';
        tmp5 = (int)newTimeString[i+1] - (int)'0';
        if (tmp4 < 0 || tmp4 > 9 || tmp5 < 0 || tmp5 > 9)
        {
            return "";
        }else{
            tmp = tmp4* 10 + (tmp5);
            if(i == 0)
            {
                tmp3 = int(tmp / 24);
                tmp2 = tmp - tmp3 * 24;
            }else{
                tmp3 = int(tmp / 60);
                tmp2 = tmp - tmp3 * 60;
                if (tmp3 > 0)
                {
                    num[i-j]+=1;
                }
            }
            num.push_back(tmp2);
        }
    }
    for (int i = num.size()-1; i >=0;i--){
        if (num[i] >=60){
            num[i]=0;
            num[i-1]+=1;
        }
    }
    if (num[0] >=24){
        num[0]=0;
    }

    for (int n:num)
    {
        if (n < 10)
        {
            endTimeString += '0';
        }
        endTimeString += std::to_string(n);
        endTimeString +=':';
    }
    return endTimeString.substr(0, 8);
}
