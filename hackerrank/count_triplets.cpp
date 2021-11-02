#include <unordered_map>
#include <vector>

using namespace std;

long countTriplets(vector<long> arr, long r) {
  int len = arr.size();
  long result = 0;

  unordered_map<long, long> frequencies;

  // here we keep key as the 2nd element
  // and its value means how many ways
  // we can reach to the 3rd element
  unordered_map<long, long> pairs;

  for (int i = len - 1; i >= 0; i--) {
    long n = arr[i];
    long n1 = n * r;  // next element of geometric progression, it can
                      // relatively be 1st, 2nd or 3rd

    // if we can reach to the 3rd element
    // with n1 being the 2nd element,
    // add to the result the number of ways
    // n1 can lead to the 3rd (next) element
    if (pairs.count(n1)) {
      result += pairs[n1];
    }

    // if we have seen n1 in earlier iterations,
    // add/increase the number of ways we can reach
    // to n1 with n
    if (frequencies.count(n1)) {
      pairs[n] += frequencies[n1];
    }

    // increment the occurance of n
    frequencies[n]++;
  }

  return result;
}
