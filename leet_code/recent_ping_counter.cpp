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