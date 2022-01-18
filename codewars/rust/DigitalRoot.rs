/*
Description:
Digital root is the recursive sum of all the digits in a number.
Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. 
The input will be a non-negative integer.
Examples
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/

fn digital_sum(n: i64) -> i64 {
    let mut total: i64 = 0;
    let mut number: i64 = n;

    while number > 0 {
        total += number % 10;
        number /= 10;
    }

    total
}

fn digital_root(n: i64) -> i64 {
   let mut result: i64 = n;
    while result.to_string().len() > 1 {
        result = digital_sum(result);
    }

    result
}
