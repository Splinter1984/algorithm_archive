/*
Description:
Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.
If you want to know more: http://en.wikipedia.org/wiki/DNA
In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". 
You have function with one side of the DNA (string, except for Haskell); you need to get the other complementary side. 
DNA strand is never empty or there is no DNA at all (again, except for Haskell).
More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)

Example: (input --> output)
"ATTGC" --> "TAACG"
"GTAT" --> "CATA"
*/

use std::collections::HashMap;

fn dna_strand(dna: &str) -> String {
    let mut dna_lib = HashMap::new();
    dna_lib.insert(String::from("A"), String::from("T"));
    dna_lib.insert(String::from("T"), String::from("A"));
    dna_lib.insert(String::from("C"), String::from("G"));
    dna_lib.insert(String::from("G"), String::from("C"));

    let mut result = String::new();
    for ch in dna.chars(){
        let new_ch = dna_lib.get(&String::from(ch));
        result += &new_ch.unwrap();
    }
    return result;
}
