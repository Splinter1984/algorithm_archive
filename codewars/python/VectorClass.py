#Create a Vector object that supports addition, subtraction, dot products, and norms. So, for example:

#var a = new Vector([1, 2, 3]);
#var b = new Vector([3, 4, 5]);
#var c = new Vector([5, 6, 7, 8]);

#a.add(b);      // should return a new Vector([4, 6, 8])
#a.subtract(b); // should return a new Vector([-2, -2, -2])
#a.dot(b);      // should return 1*3 + 2*4 + 3*5 = 26
#a.norm();      // should return sqrt(1^2 + 2^2 + 3^2) = sqrt(14)
#a.add(c);      // throws an error
#If you try to add, subtract, or dot two vectors with different lengths, you must throw an error!

#Also provide:

#a toString method, so that using the vectors from above, a.toString() === '(1,2,3)' (in Python, this is a __str__ method, so that str(a) == '(1,2,3)')
#an equals method, to check that two vectors that have the same components are equal
#Note: the test cases will utilize the user-provided equals method.

import math

class Vector:
    def __init__(self, data):
        self.data = data
    
    def __str__(self):
        return "(" + ','.join(map(str,self.data)) + ")"

    def equal_len_check(self, other):
        if len(self.data) == len(other.data):
            return True
        else:
            return False

    def equals(self, other):
        if self.data == other.data:
            return True
        else:
            return False

    def norm(self):
        res = 0
        for x in self.data:
            res+=x**2
        return math.sqrt(res)

    def add(self, other):
        if self.equal_len_check(other):
            return Vector(list(map(lambda x, y: x + y, self.data, other.data)))
        else:
            return "raises an exception"
        
    
    def subtract(self, other):
        if self.equal_len_check(other):
            return Vector(list(map(lambda x, y: x - y, self.data, other.data)))
        else:
            return "raises an exception"

    def dot(self, other):
        if self.equal_len_check(other):
            return sum(list(map(lambda x, y: x * y, self.data, other.data)))
        else:
            return "raises an exception"
            
