#include <vector>

using namespace std;

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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* head = new TreeNode(preorder[0]);
    TreeNode** tmp;

    for (int i = 1; i < preorder.size(); ++i) {
      tmp = &head;

      while (*tmp != nullptr) {
        if ((*tmp)->val > preorder[i]) {
          tmp = &((*tmp)->left);
        } else {
          tmp = &((*tmp)->right);
        }
      }
      *tmp = new TreeNode(preorder[i]);
    }

    return head;
  }
};