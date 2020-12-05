#include <iostream>
#include <string>

using namespace std;

int main() {
  bool record[128 * 8];
  fill(record, record + 128 * 8, false);
  while (true) {
    string S; cin >> S;
    if (S == "-1") break;

    int r = 0;
    int c = 0;
    for (int i = 0; i < 7; i++) {
      r <<= 1;
      if (S.at(i) == 'B') r++;
    }
    for (int j = 7; j < 10; j++) {
      c <<= 1;
      if (S.at(j) == 'R') c++;
    }

    record[8 * r + c] = true;
  }

  for (int i = 1; i < 127 * 8; i++) {
    if (record[i - 1] && !record[i] && record[i + 1]) {
      cout << i;
      break;
    }
  }
}