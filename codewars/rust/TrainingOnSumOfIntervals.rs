/*
Write a function called sumIntervals/sum_intervals() that accepts an array of intervals, and returns the sum of all the interval lengths. 
Overlapping intervals should only be counted once.
Intervals
Intervals are represented by a pair of integers in the form of an array.
The first value of the interval will always be less than the second value. Interval example: [1, 5] is an interval from 1 to 5. The length of this interval is 4.
Overlapping Intervals
List containing overlapping intervals:
[
   [1,4],
   [7, 10],
   [3, 5]
]
The sum of the lengths of these intervals is 7. Since [1, 4] and [3, 5] overlap, we can treat the interval as [1, 5], which has a length of 4.

Examples:
sum_intervals(&[(1,5)]) // => 4
sum_intervals(&[(1, 5), (10, 15), (-1, 3)]) // => 11
*/

use std::cmp;

fn sum_intervals(intervals: &[(i32, i32)]) -> i32 { 
    let mut pairs = intervals.to_vec(); 
    pairs.sort_by(|lv, rv| lv.0.cmp(&rv.0));

    let mut over_pairs = vec![pairs[0]];
    for pair in pairs {
        let len = over_pairs.len();
        let last = &mut over_pairs[len-1];
        
        if pair.0 <= last.1 {
            last.1 = cmp::max(pair.1, last.1).to_owned();
        } else {
            over_pairs.push(pair);
        }
    }

    return over_pairs.iter().map(|val| val.1 - val.0).sum();
}
