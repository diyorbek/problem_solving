// https://leetcode.com/problems/self-crossing/submissions/
// time: 56ms, memory: 36.9MB

/**
 * @param {number[]} x
 * @return {boolean}
 */
var isSelfCrossing = function(x) {
  if (x.length < 4) return false;

  const isCrossing = ([a1, a2], [b1, b2]) => {
    if (a1[0] !== a2[0]) {
      [a1, a2, b1, b2] = [b1, b2, a1, a2];
    }

    let maxX, minX, maxY, minY;
    [maxX, minX] = b1[0] > b2[0] ? [b1[0], b2[0]] : [b2[0], b1[0]];
    [maxY, minY] = a1[1] > a2[1] ? [a1[1], a2[1]] : [a2[1], a1[1]];

    return minY <= b1[1] && b1[1] <= maxY && minX <= a1[0] && a1[0] <= maxX;
  };

  const movePoint = ([x, y], by, direction) => {
    switch (direction) {
      case 0:
        return [x, y + by];
      case 1:
        return [x - by, y];
      case 2:
        return [x, y - by];
      case 3:
        return [x + by, y];
    }
  };

  let currentPos = [0, 0];
  const slopes = [];

  for (let i = 0; i < x.length; i++) {
    const newPos = movePoint(currentPos, x[i], i % 4);
    slopes.unshift([currentPos, newPos]);
    if (slopes.length > 5) slopes.pop();
    currentPos = newPos;
    if (slopes.length > 3 && isCrossing(slopes[0], slopes[3])) {
      return true;
    }
    if (slopes.length > 5 && isCrossing(slopes[0], slopes[5])) {
      return true;
    }
    if (i === 4 && isCrossing(slopes[0], slopes[4])) {
      return true;
    }
  }

  return false;
};
