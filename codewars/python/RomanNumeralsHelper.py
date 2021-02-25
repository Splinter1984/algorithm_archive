#Create a RomanNumerals class that can convert a roman numeral to and from an integer value. It should follow the API demonstrated in the examples below. Multiple roman numeral values will be tested for each helper method.

#Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

#Examples
#RomanNumerals.toRoman(1000); // should return 'M'
#RomanNumerals.fromRoman('M'); // should return 1000

class RomanNumerals:
    @staticmethod
    def from_roman(roman_number):
        roman_number
        rule_add = {'I': 1,'V': 5,'X': 10,'L': 50,'C': 100,'D': 500,'M': 1000,}
        rule_div = {('I', 'V'): 3,('I', 'X'): 8,('X', 'L'): 30,('X', 'C'): 80,('C', 'D'): 300,('C', 'M'): 800,}
        number = 0
        prev_literal = None
        for literal in roman_number:
            if prev_literal and rule_add[prev_literal] < rule_add[literal]:
                number += rule_div[(prev_literal, literal)]
            else:
                number += rule_add[literal]
            prev_literal = literal
        return number
    
    @staticmethod
    def to_roman(n):
        n = n
        result = ''
        for arabic, roman in zip((1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1),
                             'M     CM   D    CD   C    XC  L   XL  X   IX V  IV I'.split()):
            result += n // arabic * roman
            n %= arabic
        return result
      
