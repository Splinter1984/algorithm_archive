/*
In this kata, your task is to write a function that returns the smallest and largest integers in an unsorted string. 
In this kata, a range is considered a finite sequence of consecutive integers.
Input
Your function will receive two arguments:

    A string comprised of integers in an unknown range; think of this string as the result when a range of integers is shuffled around in random order then joined together into a string
    An integer value representing the size of the range

Output

Your function should return the starting (minimum) and ending (maximum) numbers of the range in the form of an array/list comprised of two integers.
Test Example

let actual = mystery_range("1568141291110137", 10);

assert_eq!(actual, (6,15));// OK

// The 10 numbers in this string are:
// 15 6 8 14 12 9 11 10 13 7
// Therefore the range of numbers is from 6 to 15

Technical Details

    The maximum size of a range will be 100 integers
    The starting number of a range will be: 0 < n < 100
    Full Test Suite: 21 fixed tests, 100 random tests
    Use Python 3+ for the Python translation
    For JavaScript, require has been disabled and most built-in prototypes have been frozen (prototype methods can be added to Array and Function)
    All test cases will be valid
*/

mod kata_solution {
    use itertools::Itertools;

    pub fn mystery_range(s: &str, n: usize) -> (u32, u32) {
        let counts = s.chars().counts();

        for i in 1..100u32 {
            let j = i + n as u32 - 1;
            if counts == (i..=j).join("").chars().map(|x| x as u8 as char).counts()
                && s.contains(&i.to_string())
                && s.contains(&j.to_string())
            {
                return (i, j);
            }
        }

        unreachable!()
    }
}
