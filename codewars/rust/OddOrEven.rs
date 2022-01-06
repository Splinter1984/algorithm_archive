/*
Task:
Given a list of integers, determine whether the sum of its elements is odd or even.
Give your answer as a string matching "odd" or "even".
If the input array is empty consider it as: [0] (array with a zero).

Examples:
Input: [0]
Output: "even"
Input: [0, 1, 4]
Output: "odd"
Input: [0, -1, -5]
Output: "even"
*/

fn odd_or_even(numbers: Vec<i32>) -> String {
    let s: i32 = numbers.iter().sum();
    if s % 2 == 0 {
        return "even".to_string();
    } else {
        return "odd".to_string();
    }
}
