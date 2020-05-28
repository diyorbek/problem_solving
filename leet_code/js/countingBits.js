/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function (num) {
  const res = [0];

  if (num === 0) return res;

  for (let i = 0; i <= num; i++) {
    const np2 = 2 ** Math.floor(Math.log2(i));
    res.push(res[i - np2] + 1);
  }

  return res;
};
