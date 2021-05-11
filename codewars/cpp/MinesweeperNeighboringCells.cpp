/*We started implementing the minesweeper game, we already have a module for filling a SIZExSIZE matrix that places the mines (character 'o'), empty cells (character ' '), cells that are not revealed (character 'D') and cells that must be filled with a number that the represents the number of mines in the neighboring cells (character 'R'). For neighboring cells, we assume 8-connectivity.
Design a function compute_number_mines that takes as an input a matrix like the one mentioned above and replaces the cells that contain a character 'R' with the number of bombs (mines) in the neighboring cells.
For example, given the following 5x5 matrix:

---------------------               
|   |   | o | o |   |           8-connectivity       
|   | o |   | D |   |               \ | /   
|   | D | R |   |   |               - R -
|   |   | o | o |   |               / | \     
|   |   |   |   | o |                
---------------------                
The cell that contains the character ‘R’ must be replaced by the character '3'.*/

#define _MINE_SYM 'o'
#define _COUNTER_SYM 'R'

bool is_mines_counter(const char cell)
{
    return cell == _COUNTER_SYM;
}

bool is_mine(const char cell)
{
    return cell == _MINE_SYM;
}

int check_neighbors(char **board, const int row_min, 
                    const int row_max, const int col_min,
                    const int col_max)
{
    int count = 0;
    for (int i = row_min; i < row_max; i++)
        for (int j = col_min; j < col_max; j++)
            if(is_mine(board[i][j]))
                ++count;
    return count;
}

void compute_number_mines(char **board, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        { 
            if (is_mines_counter(board[i][j]))
            {
                int r_min = std::max(0, i-1), r_max = std::min(i+2, rows);
                int c_min = std::max(0, j-1), c_max = std::min(j+2, cols);
                board[i][j] = '0' + check_neighbors(board, r_min, r_max, c_min, c_max);
            }
        }
    } 
}
