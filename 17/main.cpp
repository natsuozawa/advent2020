#include <iostream>

using namespace std;

const int sz = 25;

int main() {
  long long preamble[sz];
  
  for (int i = 0; i < sz; i++) {
    cin >> preamble[i];
  }

  int k = 0;
  while (!cin.eof()) {
    long long n; cin >> n;
    bool valid = false;
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz; j++) {
        if (preamble[i] + preamble[j] == n) {
          valid = true;
          break;
        }
      }
    }
    if (!valid) {
      cout << n << endl;
      return 0;
    }
    preamble[k] = n;
    k++;
    k %= sz;
  }
}