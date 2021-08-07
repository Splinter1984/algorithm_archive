/*Create a function that interprets code in the esoteric language Poohbear

The Language
Poohbear is a stack-based language largely inspired by Brainfuck. It has a maximum integer value of 255, and 30,000 cells. The original intention of Poohbear was to be able to send messages that would, to most, be completely indecipherable: Poohbear Wiki

For the purposes of this kata, you will make a version of Poohbear that has infinite memory cells in both directions (so you do not need to limit cells to 30,000)
Cells have a default value of 0
Each cell can hold one byte of data. Once a cell's value goes above 255, it wraps around to 0. If a cell's value goes below 0, it wraps to 255.
If the result of an operation isn't an int, round the result down to the nearest one.
Your interpreter should ignore any non-command characters in the code.
If you come to a W in the code and the current cell is equal to 0, jump to the corresponding E.
If you come to an E in the code and the current cell is not 0, jump back to the corresponding W.*/


#include <cstring>
#include <string>
#include <cmath>
#include <vector>

const char *poohbear (const char* sourcecode) 
{
    if (strlen(sourcecode) == 0)
        return "";
    size_t n = 0;
    for (size_t i = 0; i < strlen(sourcecode); i++)
    {
        if (sourcecode[i] == 'P' || sourcecode[i] == 'N')
            n++;
    }
    int * vec = new int[n];
    for (size_t i = 0; i < n; i++)
        vec[i]= 0;
    bool loop = false;
    std::string outStr = "";
    size_t cell(0), count(0), last(0);
    int copy(0);
  
    while (count < strlen(sourcecode))
    {
        switch(sourcecode[count])
        {
            case '>':
                cell++;
                break;
            case '<':
                cell--;
                break;
            case '+':
                vec[cell] = (vec[cell] + 1) % 256;
                break;
            case '-':
                vec[cell] = (vec[cell] - 1) % 256;
                break;
            case 'c':
                copy = vec[cell];
                break;
            case 'p':
                vec[cell] = copy;
                break;
            case 'N':
                outStr += std::to_string(int(vec[cell]));
                break;
            case 'P':
                outStr += char(vec[cell]);
                break;
            case 'T':
                vec[cell] = vec[cell] * 2 % 256;
                break;
            case 'Q':
                vec[cell] = vec[cell] * vec[cell] %256;
                break;
            case 'U':
                vec[cell] = int(sqrt(vec[cell])) % 256;
                break;
            case 'L':
                vec[cell] = (vec[cell] + 2) % 256;
                break;
            case 'I':
                vec[cell] = (vec[cell] - 2) % 256;
                break;
            case 'V':
                vec[cell] = int(vec[cell] / 2) % 256;
                break;
            case 'A':
                vec[cell] = (vec[cell] + copy) % 256;
                break;
            case 'B':
                vec[cell] = (vec[cell] - copy) % 256;
                break;
            case 'Y':
                vec[cell] = (vec[cell] * copy) % 256;
                break;
            case 'D':
                vec[cell] = (vec[cell] / copy) % 256;
                break;
            case 'W':
                last = count;
                if (vec[cell] != 0)
                    loop = true;
                if (vec[cell] == 0)
                {
                    for (size_t i = 0; i < strlen(sourcecode); i++)
                    {
                        if (sourcecode[i] == 'E')
                        {
                            count = i;
                            break;
                        }
                    }
                }
                break;
            case 'E':
                if (loop == true)
                {
                    loop = false;
                    count = last -1;
                }
                break;
        }
        count++;
    }
    char* out = new char[outStr.size() + 1];
    std::copy(outStr.begin(), outStr.end(), out);
    out[outStr.size()] = '\0';
    delete []vec;
    return out;
}
