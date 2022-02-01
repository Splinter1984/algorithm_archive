/*
Description:
Define a function that takes in two non-negative integers aaa and bbb and returns the last decimal digit of aba^bab. 
Note that aaa and bbb may be very large!
For example, the last decimal digit of 979^797 is 999, since 97=47829699^7 = 478296997 = 4782969. 
The last decimal digit of (2200)2300({2^{200}})^{2^{300}}(2200)2300, which has over 109210^{92}1092 decimal digits, is 666. Also, please take 000^000 to be 111.
You may assume that the input will always be valid.

Examples
last_digit("4", "1")            // returns 4
last_digit("4", "2")            // returns 6
last_digit("9", "7")            // returns 9    
last_digit("10","10000000000")  // returns 0
*/

fn modulo(base: u32, exp: &str) -> u32 {
    let mut res = 0;
    for ch in exp.chars() {
        res = (res*10 + ch.to_digit(10).unwrap()) % base;
    }

    res
}

fn last_digit(str1: &str, str2: &str) -> i32 {
    if str1.len() == 1 && str2.len() == 1 && str1 == "0" && str2 == "0" {
        return 0;
    } else if str2 == "0" && str2.len() == 1 {
        return 1;
    } else if str1 == "0" && str1.len() == 1 {
        return 0;
    }
    
    let n1 = str1.chars().last().unwrap().to_digit(10).unwrap();
    let e = modulo(4, str2);

    (n1.pow(if e == 0 { 4 } else { e }) % 10) as i32
}
