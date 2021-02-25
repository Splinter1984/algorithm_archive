#Task
#A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. Its center (the intersection point of its diagonals) coincides with the point (0, 0), but the sides of the rectangle are not parallel to the axes; instead, they are forming 45 degree angles with the axes.

#How many points with integer coordinates are located inside the given rectangle (including on its sides)?

#Example
#For a = 6 and b = 4, the output should be 23

#The following picture illustrates the example, and the 23 points are marked green.

#Input/Output
#[input] integer a
#A positive even integer.
#Constraints: 2 ≤ a ≤ 10000.
#[input] integer b
#A positive even integer.
#Constraints: 2 ≤ b ≤ 10000.
#[output] an integer
#The number of inner points with integer coordinates.

import math
from functools import reduce
def rectangle_rotation(a, b):
    aHalfBisect = (a/math.sqrt(2))/2
    bHalfBisect = (b/math.sqrt(2))/2
    rect1 = [math.floor(aHalfBisect)*2 + 1, math.floor(bHalfBisect)*2 + 1]
    rect2 = []
    
    if aHalfBisect - math.floor(aHalfBisect) < 0.5:
        rect2.append(rect1[0] - 1)
    else: 
        rect2.append(rect1[0] + 1)
    
    
    if bHalfBisect - math.floor(bHalfBisect) < 0.5: 
        rect2.append(rect1[1] - 1)
    else:
        rect2.append(rect1[1] + 1)
    
    return reduce(lambda x, y: x*y, rect1) + reduce(lambda x, y: x*y,rect2)
  
