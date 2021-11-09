#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b) {
  vector<int> result;
  int al = a.size(),
          bl = b.size(),
          i = 0,
          j = 0;

  while (i < al && j < bl) {
    if (a[i] < b[j]) {
      result.push_back(a[i++]);
    } else {
      result.push_back(b[j++]);
    }
  }

  while (i < al) {
    result.push_back(a[i++]);
  }

  while (j < bl) {
    result.push_back(b[j++]);
  }

  return result;
}

vector<int> mergeSort(vector<int> arr) {
  int l = arr.size();

  if (l == 1 || l == 0)
    return arr;

  auto left = mergeSort(vector<int>(arr.begin(), arr.begin() + l / 2));
  auto right = mergeSort(vector<int>(arr.begin() + l / 2, arr.end()));

  return merge(left, right);
}

void insertion_sort(vector<int> &arr) {
  auto l = arr.size();

  for (int i = 1; i < l; ++i) {
    int j = i;

    while (j > 0 && arr[j] < arr[j - 1]) {
      swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}

void selection_sort(vector<int> &arr) {
  auto l = arr.size();

  for (int i = 0; i < l; ++i) {
    int min_i = i;

    for (int j = i; j < l; ++j) {
      if (arr[min_i] > arr[j])
        min_i = j;
    }

    swap(arr[i], arr[min_i]);
  }
}

void quick_sort(vector<int> &arr, int start, int end) {
  int l = arr.size();

  if (l == 0 || l == 1 || start >= end)
    return;

  int pivot = arr[end];

  auto i = partition(arr.begin() + start, arr.begin() + end, [pivot](int a) {
    return a < pivot;
  });
  int median = i - arr.begin();
  swap(arr[median], arr[end]);

  quick_sort(arr, start, median - 1);
  quick_sort(arr, median, end - 1);
}

int main() {
  vector<int> arr = {5, 2, -1, 7, 9, 3, 55, 6, 7, 3, 23, 34, 57, 8};
  auto sorted = mergeSort(arr);
  insertion_sort(arr);
  selection_sort(arr);
  quick_sort(arr, 0, arr.size() - 1);

  for (int a:arr) {
    cout << a << ", ";
  }
  cout << endl;
  for (int a:sorted) {
    cout << a << ", ";
  }
}