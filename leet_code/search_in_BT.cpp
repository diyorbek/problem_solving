// https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/
// time: 44ms, memory: 28.4MB

class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    while (root) {
      if (root->val == val)
        break;
      else if (root->val > val) {
        root = root->left;
        continue;
      } else if (root->val < val) {
        root = root->right;
        continue;
      }
    }

    return root;
  }
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};