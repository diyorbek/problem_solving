#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int countNodes(TreeNode* root) {
    int height = getHeight(root);

    if (height < 2) {
      return height;
    }

    int lastLevelNodesCount = countNodesInLevel(root, height - 1, 0);

    return lastLevelNodesCount + pow(2, height - 1) - 1;
  }

  int getHeight(TreeNode* root) {
    if (!root) {
      return 0;
    }

    return 1 + getHeight(root->left);
  }

  int countNodesInLevel(TreeNode* root, int l, int current) {
    if (!root) {
      return 0;
    }

    if (l == current) {
      return 1;
    }

    return countNodesInLevel(root->left, l, current + 1) +
           countNodesInLevel(root->right, l, current + 1);
  }
};