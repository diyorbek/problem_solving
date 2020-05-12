#include <vector>

using namespace std;

typedef vector<vector<int>> vvint;

class Solution {
 public:
  vvint floodFill(vvint& image, int sr, int sc, int newColor) {
    int width = image[0].size();
    int height = image.size();

    changeColor(image, width, height, sr, sc, newColor);

    return image;
  }

  void changeColor(vvint& image,
                   int& width,
                   int& height,
                   int row,
                   int col,
                   int& newColor) {
    unsigned int initColor = image[row][col];
    if (initColor != newColor) {
      image[row][col] = newColor;

      if (row - 1 > -1 && image[row - 1][col] == initColor) {
        changeColor(image, width, height, row - 1, col, newColor);
      }

      if (col + 1 < width && image[row][col + 1] == initColor) {
        changeColor(image, width, height, row, col + 1, newColor);
      }

      if (row + 1 < height && image[row + 1][col] == initColor) {
        changeColor(image, width, height, row + 1, col, newColor);
      }

      if (col - 1 > -1 && image[row][col - 1] == initColor) {
        changeColor(image, width, height, row, col - 1, newColor);
      }
    }
  }
};