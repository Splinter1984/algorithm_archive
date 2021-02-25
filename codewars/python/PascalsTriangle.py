#In mathematics, Pascal's triangle is a triangular array of the binomial coefficients expressed with formula
#where n denotes a row of the triangle, and k is a position of a term in the row.

#Pascal's Triangle

#You can read Wikipedia article on Pascal's Triangle for more information.

#Task
#Write a function that, given a depth n, returns n top rows of Pascal's Triangle flattened into a one-dimensional list/array.

#Example:
#n = 1: [1]
#n = 2: [1,  1, 1]
#n = 4: [1,  1, 1,  1, 2, 1,  1, 3, 3, 1]

def pascals_triangle(n): 
    results = [] 
    tmp = 0
    for i in range(n): 
        row = [1] 
        if results:  
            last_row = results[tmp:] 
            row.extend([sum(pair) for pair in zip(last_row, last_row[1:])]) 
            row.append(1)
        tmp+=i 
        results.extend(row)
    return results
  
