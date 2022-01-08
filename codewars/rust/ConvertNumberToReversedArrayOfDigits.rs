/*
Convert number to reversed array of digits

Given a random non-negative number, you have to return the digits of this number within an array in reverse order.
Example:

348597 => [7,9,5,8,4,3]
0 => [0]
*/

fn digitize(n: u64) -> Vec<u8> {
    if n < 10 {
        return [n as u8].to_vec();
    }
    let mut result: Vec<u8> = vec![];
    let mut num: u64 = n;
    while num >= 1 {
        result.push((num%10) as u8);
        num/=10;
    }
    return result;
}
