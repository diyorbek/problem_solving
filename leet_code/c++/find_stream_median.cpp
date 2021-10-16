#include <queue>

using namespace std;

class MedianFinder {
  priority_queue<int> max_h;
  priority_queue<int, vector<int>, greater<int>> min_h;
  int data_size = 0;

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (!data_size) {
      max_h.push(num);
      min_h.push(num);
      data_size++;
    } else {
      if (num < max_h.top()) {
        max_h.push(num);
      } else {
        min_h.push(num);
      }

      data_size++;

      if (data_size % 2 == 0) {
        if (max_h.size() > min_h.size()) {
          max_h.pop();
        } else {
          min_h.pop();
        }
      } else {
        if (max_h.size() > min_h.size()) {
          min_h.push(max_h.top());
        } else {
          max_h.push(min_h.top());
        }
      }
    }
  }

  double findMedian() { return (max_h.top() + min_h.top()) / 2.; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */