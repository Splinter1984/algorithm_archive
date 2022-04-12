/*
An integer partition of n is a weakly decreasing list of positive integers which sum to n.

For example, there are 7 integer partitions of 5:

[5], [4,1], [3,2], [3,1,1], [2,2,1], [2,1,1,1], [1,1,1,1,1].
Write a function which returns the number of integer partitions of n. 
The function should be able to find the number of integer partitions of n for n at least as large as 100.*/

use std::collections::HashMap;

struct Partition {
    dictionary: HashMap<String, isize>,
}

impl Partition {
    fn part(&mut self, n: isize, k: isize) -> isize {
        if n < k {
            return 0;
        } else if n == k {
            return 1;
        } else if k ==  0 {
            return 0;
        }

        let key = String::from(n.to_string() + ", " + &k.to_string());
        let mut res: isize = 0;

        if self.dictionary.contains_key(&key){
            res = *self.dictionary.get(&key).unwrap();
        } else {
            res = self.part(n-1, k-1) + self.part(n-k, k);
            self.dictionary.insert(key, res);
        }

        return res;
    }
}

fn partitions(n: isize) -> isize {
    let mut result: isize = 0;
    let mut partition = Partition {dictionary: HashMap::new()};
    for k in 0..n+1 {
        result += partition.part(n, k);
    }

    return result;
}
