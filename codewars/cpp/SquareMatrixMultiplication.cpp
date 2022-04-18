/*
Write a function that accepts two square (NxN) matrices (two dimensional arrays), and returns the product of the two. Only square matrices will be given.
*/

vector<vector<int>> matrix_multiplication(vector<vector<int>> &a, vector<vector<int>> &b, size_t n)
{
    std::vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}
