/*
Description:
Everyone knows passphrases. One can choose passphrases from poems, songs, movies names and so on but frequently they can be guessed due to common cultural references. 
You can get your passphrases stronger by different means. One is the following:

choose a text in capital letters including or not digits and non alphabetic characters,

shift each letter by a given number but the transformed letter must be a letter (circular shift),
replace each digit by its complement to 9,
keep such as non alphabetic and non digit characters,
downcase each letter in odd position, upcase each letter in even position (the first character is in position 0),
reverse the whole result.
Example:
your text: "BORN IN 2015!", shift 1

1 + 2 + 3 -> "CPSO JO 7984!"

4 "CpSo jO 7984!"

5 "!4897 Oj oSpC"

With longer passphrases it's better to have a small and easy program. Would you write it?
*/

fn alphabet_shift(c: char, n: u32) -> char {
    let shift = c as u32 + n;
    let bound = if c.is_lowercase() { 122 } else { 90 };
    if shift > bound {
        return std::char::from_u32(if bound == 122 { 'a' } else { 'A' } as u32 + shift - bound - 1).unwrap_or(c);
    }

    std::char::from_u32(shift).unwrap_or(c)
}

fn play_pass(s: &str, n: u32) -> String {
    let mut result: String = "".to_string();
    for (pos, sym) in s.to_lowercase().chars().enumerate() {
        let mut tmp = sym;
        if sym.is_alphabetic() {
            if pos % 2 == 0 {
                tmp = tmp.to_ascii_uppercase();
            }
            tmp = alphabet_shift(tmp, n);
        } else if sym.is_numeric() {
            let ucode = tmp as u32;
            tmp = std::char::from_digit(57 - ucode, 10).unwrap_or(tmp);
        }
        result.push(tmp);
    }

    result.chars().rev().collect()
}
