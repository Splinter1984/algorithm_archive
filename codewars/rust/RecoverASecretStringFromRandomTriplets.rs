/*
There is a secret string which is unknown to you. Given a collection of random triplets from the string, recover the original string.
A triplet here is defined as a sequence of three letters such that each letter occurs somewhere before the next in the given string. 
"whi" is a triplet for the string "whatisup".

As a simplification, you may assume that no letter occurs more than once in the secret string.

You can assume nothing about the triplets given to you other than that they are valid triplets and 
that they contain sufficient information to deduce the original string. 
In particular, this means that the secret string will never contain letters that do not occur in one of the triplets given to you.*/

use std::collections::HashSet;

fn recover_secret(triplets: Vec<[char; 3]>) -> String {
    let mut chars: Vec<char> = vec![];
    for line in &triplets {
        for c in line.iter() {
            chars.push(c.clone());
        }
    }
    let mut counter:HashSet<char> = HashSet::new();
    chars = chars.into_iter().filter(|x| if !counter.contains(x) {  counter.insert(x.clone()); true } else { false } ).collect();
    loop {
        let mut count = 0;
        for line in &triplets {
            for j in 0..line.len()-1 {
                let a = &line[j];
                let b = &line[j+1];
                let index_of_a = chars.iter().position(|p|a==p).unwrap();
                let index_of_b = chars.iter().position(|p|b==p).unwrap();
                if index_of_a > index_of_b {
                    chars.swap(index_of_b,index_of_a);
                    count+=1;
                }
            }
        }
        if count==0 {
            return chars.into_iter().collect();
        }
    }
}
