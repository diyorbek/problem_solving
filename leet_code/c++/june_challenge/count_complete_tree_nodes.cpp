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
  int countHeight(TreeNode* node) {
    int leftHeight = 0;
    int rightHeight = 0;

    TreeNode* temp = node;

    while (temp != NULL) {
      leftHeight++;
      temp = temp->left;
    }

    temp = node;

    while (temp != NULL) {
      rightHeight++;
      temp = temp->right;
    }

    if (leftHeight == rightHeight) {
      return pow(2, leftHeight) - 1;
    }

    return 1 + countHeight(node->left) + countHeight(node->right);
  }

  int countNodes(TreeNode* root) { return countHeight(root); }
};