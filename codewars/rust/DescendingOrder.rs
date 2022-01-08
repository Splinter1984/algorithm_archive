/*
Description:
Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. 
Essentially, rearrange the digits to create the highest possible number.
Examples:
Input: 42145 Output: 54421
Input: 145263 Output: 654321
Input: 123456789 Output: 987654321
*/

fn descending_order(x: u64) -> u64 {
    let mut chars: Vec<char> = x.to_string().chars().collect();
    chars.sort_by(|a, b| b.cmp(a));
    chars.into_iter().collect::<String>().parse().unwrap()
}
