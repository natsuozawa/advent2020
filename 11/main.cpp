#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int ans = 0;

  while (!cin.eof()) {
    set<char> s;
    while (true) {
      string t;
      getline(cin, t);
      if (t == "") break;
      for (int i = 0; i < t.size(); i++) {
        s.insert(t.at(i));
      }
    }
    ans += s.size();
  }

  cout << ans << endl;
}