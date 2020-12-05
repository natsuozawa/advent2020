#include <iostream>
#include <string>

using namespace std;

int main() {
  int ans = 0;
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

    ans = max(ans, 8 * r + c);
  }

  cout << ans << endl;
}