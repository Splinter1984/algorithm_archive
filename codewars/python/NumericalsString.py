#You are given an input string.

#For each symbol in the string if it's the first character occurrence, replace it with a '1', else replace it with the amount of times you've already seen it...

#But will your code be performant enough?

#Examples:
#input   =  "Hello, World!"
#result  =  "1112111121311"

#input   =  "aaaaaaaaaaaa"
#result  =  "123456789101112"
#There might be some non-ascii characters in the string.

#Note: there will be no int domain overflow (character occurrences will be less than 2 billion).

def numericals(s):
    history = {}
    result = []
    for char in s:
        if char not in history:
            history[char] = 1
        else:
            history[char] += 1
        result.append(history[char])
    return "".join(map(str, result))
  
