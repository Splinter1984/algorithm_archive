/*
Description:
Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.
This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!
All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.
What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.

Examples
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False
*/

use std::collections::HashMap;

fn valid_braces(s: &str) -> bool {
    if s.is_empty() {
        return false;
    }
    let mut heap = Vec::new();
    let braces_lib = HashMap::from([
        (')', '('),
        (']', '['),
        ('}', '{'),
    ]);

    for val in s.chars() {
        if val == '(' || val == '[' || val == '{' {
            heap.push(val);
        } else if val == ')' || val == ']' || val == '}' {
            if heap.is_empty() || heap.pop().unwrap() != braces_lib[&val] {
                return false;
            }
        }
    }

    return heap.is_empty();
}
