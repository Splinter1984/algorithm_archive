/*
Task
Given an array of integers , Find the maximum product obtained from multiplying 2 adjacent numbers in the array.
Notes
Array/list size is at least 2.
Array/list numbers could be a mixture of positives, negatives also zeroes .
Input >> Output Examples
adjacentElementsProduct([1, 2, 3]); ==> return 6
*/

fn adjacent_elements_product(xs: &[i32]) -> i32 {
    let mut max = xs[0] * xs[1];
    for pair in xs.windows(2).skip(1) {
        max = i32::max(pair[0] * pair[1], max);
    }
    max
}
