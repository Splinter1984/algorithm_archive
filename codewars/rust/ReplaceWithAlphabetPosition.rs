/*
Welcome.
In this kata you are required to, given a string, replace every letter with its position in the alphabet.
If anything in the text isn't a letter, ignore it and don't return it.
"a" = 1, "b" = 2, etc.
Example
alphabet_position("The sunset sets at twelve o' clock.")
Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" (as a string)
*/

fn alphabet_position(text: &str) -> String{
    let mut syms = Vec::new();
    let mut result = String::new();
    for ch in text.chars(){
        if ch.is_alphabetic() == true {
            let code: u32 = ch.to_ascii_uppercase() as u32;
            syms.push(code - 64);
        }
    }
    result = syms.iter().map(|&id| id.to_string() + " ").collect();
    result.pop();
    
    return result;
}
