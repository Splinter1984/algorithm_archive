#Write a function called LCS that accepts two sequences and returns the longest subsequence common to the passed in sequences.

#Subsequence
#A subsequence is different from a substring. The terms of a subsequence need not be consecutive terms of the original sequence.

#Example subsequence
#Subsequences of "abc" = "a", "b", "c", "ab", "ac", "bc" and "abc".

#LCS examples
#LCS( "abcdef" , "abc" ) => returns "abc"
#LCS( "abcdef" , "acf" ) => returns "acf"
#LCS( "132535365" , "123456789" ) => returns "12356"
#Notes
#Both arguments will be strings
#Return value must be a string
#Return an empty string if there exists no common subsequence
#Both arguments will have one or more characters (in JavaScript)
#All tests will only have a single longest common subsequence. Don't worry about cases such as LCS( "1234", "3412" ), which would have two possible longest common subsequences: "12" and "34".
#Note that the Haskell variant will use randomized testing, but any longest common subsequence will be valid.

#Note that the OCaml variant is using generic lists instead of strings, and will also have randomized tests (any longest common subsequence will be valid).


def fill_dyn_matrix(x, y):
    L = [[0]*(len(y)+1) for _ in range(len(x)+1)]
    for x_i,x_elem in enumerate(x):
        for y_i,y_elem in enumerate(y):
            if x_elem == y_elem:
                L[x_i][y_i] = L[x_i-1][y_i-1] + 1
            else:
                L[x_i][y_i] = max((L[x_i][y_i-1],L[x_i-1][y_i]))
    return L

def lcs(x, y):
    L = fill_dyn_matrix(x, y)
    LCS = []
    x_i,y_i = len(x)-1,len(y)-1
    while x_i >= 0 and y_i >= 0:
        if x[x_i] == y[y_i]:
            LCS.append(x[x_i])
            x_i, y_i = x_i-1, y_i-1
        elif L[x_i-1][y_i] > L[x_i][y_i-1]:
            x_i -= 1
        else:
            y_i -= 1
    LCS.reverse()
    return ''.join(LCS)
  
