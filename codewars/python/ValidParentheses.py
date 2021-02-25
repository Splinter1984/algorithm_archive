#Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return true if the string is valid, and false if it's invalid.

#Examples
#"()"              =>  true
#")(()))"          =>  false
#"("               =>  false
#"(())((()())())"  =>  true
#Constraints
#0 <= input.length <= 100

def valid_parentheses(string):
    if not string:
        return True
    string.split()
    brck_list = ['(', ')']
    brck_dict = dict.fromkeys(')','(')
    stc =  []
    for sym in string:
        if  sym in brck_list:
            if sym in brck_dict.values():
                stc.insert(0, sym)
            else:
                if stc:
                    stc.pop()
                else:
                    return False
    if not stc:
        return True
    else:
        return False
      
