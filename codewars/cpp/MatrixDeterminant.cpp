/*
Write a function that accepts a square matrix (N x N 2D array) and returns the determinant of the matrix.
How to take the determinant of a matrix -- it is simplest to start with the smallest cases:
A 1x1 matrix |a| has determinant a.
A 2x2 matrix [ [a, b], [c, d] ] or

|a  b|
|c  d|
has determinant: a*d - b*c.
The determinant of an n x n sized matrix is calculated by reducing the problem to the calculation of the determinants of n matrices ofn-1 x n-1 size.
For the 3x3 case, [ [a, b, c], [d, e, f], [g, h, i] ] or

|a b c|  
|d e f|  
|g h i|  
the determinant is: a * det(a_minor) - b * det(b_minor) + c * det(c_minor) where det(a_minor) refers to taking the determinant of the 2x2 matrix created by crossing out the row and column in which the element a occurs:

|- - -|
|- e f|
|- h i|  
Note the alternation of signs.
The determinant of larger matrices are calculated analogously, e.g. if M is a 4x4 matrix with first row [a, b, c, d], then:
det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor)
*/

#include <iostream>
#include <vector>

long long determinant(const std::vector<std::vector<long long>>& vec)
{
    /* check if input matrix if not nXn */
    if (vec.empty())
        return 0;
    if (vec.size() != vec.front().size())
        return 0;

    /* get the variable of matrix dimension */
    size_t dim = vec.front().size();
  
    if (dim == 1)
        return vec.front().at(0);

    int minus = 1;
    long long result = 0;
    for (int i = 0; i < vec.front().size(); i++)
    {
        std::vector<std::vector<long long>> subVec;
        for (int j = 1; j < vec.size(); j++)
        {
            std::vector<long long> cof;
            for (int k = 0; k < vec.front().size(); k++)
            {
                if (k == i)
                    continue;
                cof.push_back(vec.at(j).at(k));
            }
            subVec.push_back(cof);
        }
        result += minus * vec.at(0).at(i) * determinant(subVec);
        minus *= -1;
    }

    return result;
}
