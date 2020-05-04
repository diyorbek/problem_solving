#include <cmath>
#include <iostream>

using namespace std;

int findComplement(int num) {
  int coml = 0;
  int i = 0;
  while (num) {
    coml += ((num & 1 ? 0 : 1) * pow(2, i++));
    num >>= 1;
  }
  return coml;
}

int main(int argc, char const* argv[]) {
  int a;
  cin >> a;
  cout << findComplement(a) << endl;
  return 0;
}
