/*
Your task, is to create a NxN spiral with a given size.

For example, spiral with size 5 should look like this:

00000
....0
000.0
0...0
00000
and with the size 10:

0000000000
.........0
00000000.0
0......0.0
0.0000.0.0
0.0..0.0.0
0.0....0.0
0.000000.0
0........0
0000000000
Return value should contain array of arrays, of 0 and 1, with the first row being composed of 1s. For example for given size 5 result should be:

[[1,1,1,1,1],[0,0,0,0,1],[1,1,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Because of the edge-cases for tiny spirals, the size will be at least 5.

General rule-of-a-thumb is, that the snake made with '1' cannot touch to itself.*/

fn draw(size: usize, row: usize, col: usize) -> i8 {
    if col + row <= size - 1 && row <= col {
        return row as i8 % 2 ^ 1;
    }

    if col + row >= size - 1 && row <= col {
        return (size - col) as i8 % 2;
    }
                                         
    if col + row >= size - 1 && row >= col {
        return (size - row) as i8 % 2
            ^ (size % 4 == 2 && (row, col) == (size / 2, size / 2 - 1)) as i8;
    }
      
    if col + row <= size - 1 && row > col {
        return col as i8 % 2 ^ (row != col + 1) as i8;
    }
      
    unreachable!();
}

fn spiralize(size: usize) -> Vec<Vec<i8>> {
    (0..size).map(|row| (0..size).map(|col| draw(size, row, col)).collect()).collect()
}
