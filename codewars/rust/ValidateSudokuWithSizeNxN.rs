/*
Given a Sudoku data structure with size NxN, N > 0 and √N == integer, write a method to validate if it has been filled out correctly.
The data structure is a multi-dimensional Array, i.e:

[
  [7,8,4,  1,5,9,  3,2,6],
  [5,3,9,  6,7,2,  8,4,1],
  [6,1,2,  4,3,8,  7,5,9],
  
  [9,2,8,  7,1,5,  4,6,3],
  [3,5,7,  8,4,6,  1,9,2],
  [4,6,1,  9,2,3,  5,8,7],
  
  [8,7,6,  3,9,4,  2,1,5],
  [2,4,3,  5,6,1,  9,7,8],
  [1,9,5,  2,8,7,  6,3,4]
]

Rules for validation

    Data structure dimension: NxN where N > 0 and √N == integer
    Rows may only contain integers: 1..N (N included)
    Columns may only contain integers: 1..N (N included)
    'Little squares' (3x3 in example above) may also only contain integers: 1..N (N included)
*/


struct Sudoku{
    data: Vec<Vec<u32>>,
}

impl Sudoku{
    fn is_valid(&self) -> bool {
        let len = self.data.len();
        let root = (len as f32).sqrt().floor() as usize;
        let checksum = (1u32..=(len as u32)).fold(0u32, |s, x| s ^ x);
        len > 0 && {
            root * root == len
        } && {
            self.data.iter().fold(true, |b, row| {
                b && row.len() == len
            })
        } && {
            self.data.iter().fold(true, |acc, row| {
                acc && row.iter().fold(0u32, |s, x| s ^ x) == checksum
            })
        } && {
            (0usize..len).fold(true, |b, c| {
                b && checksum == (0usize..len).fold(0u32, |s, r| s ^ self.data[r][c])
            })
        } && {
            let mut ans = true;
            for br in (0..len).step_by(root) {
                for bc in (0..len).step_by(root) {
                    let mut sum = 0u32;
                    for r in 0..root {
                        for c in 0..root {
                            sum ^= self.data[br + r][bc + c];
                        }
                    }
                    ans &= sum == checksum;
                }
            }
            ans
        }
    }
}
