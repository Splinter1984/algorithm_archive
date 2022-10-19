/*
Welcome. In this kata, you are asked to square every digit of a number and concatenate them.
For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1.
Note: The function accepts an integer and returns an integer
*/

fn square_digits(num: u64) -> u64 {
    let mut v = num
        .to_string()
        .chars()
        .map(|ch| {
            let n: u64 = ch.to_digit(10).unwrap().into();
            n*n
        })
        .collect::<Vec<_>>();
    
    v.iter().fold(0, |acc, elem| acc * if *elem > 10 {100} else {10} + elem)
}
