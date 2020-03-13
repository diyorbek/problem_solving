struct Node {
  Node(int time) { this->time = time; };
  int time;
  Node* next;
};

struct LinkedStack {
  LinkedStack() { this->top = nullptr; }

  Node* top;

  void insert(int time) {
    Node* newTop = new Node(time);
    newTop->next = this->top;
    this->top = newTop;
  }

  int countDive(Node* top, Node* current) {
    if (current && top->time - current->time <= 3000) {
      return 1 + countDive(top, current->next);
    }

    return 0;
  };
};

class RecentCounter {
 public:
  RecentCounter() {}

  LinkedStack* history = new LinkedStack();

  int ping(int t) {
    history->insert(t);
    return history->countDive(history->top, history->top);
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root) {
      if (root->val == val) {
        return root;
      }
      TreeNode* left = searchBST(root->left, val);
      TreeNode* right = searchBST(root->right, val);

      left ? left : right ? right : nullptr;
    }

    return nullptr;
  }
};