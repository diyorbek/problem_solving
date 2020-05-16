struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    int i = 1;
    ListNode* current = head;
    ListNode* first_even;

    while (current) {
      ListNode* next = current->next;

      if (i == 1) {
        first_even = current->next;
      }

      if (current->next && current->next->next) {
        current->next = current->next->next;
      } else if (i % 2) {
        current->next = first_even;
      } else {
        current->next = nullptr;
      }

      current = next;
      i++;
    }

    return head;
  }
};