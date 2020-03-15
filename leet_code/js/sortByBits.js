// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// time: 76ms, memory: 35.9MB

/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = function(arr) {
  function countBits(n) {
    let count = 0;
    while (n > 0) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }

  return arr.sort((a, b) => countBits(a) - countBits(b) || a - b);
};
