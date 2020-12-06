#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int ans = 0;

  while (!cin.eof()) {
    unordered_map<char, int> s;
    int cnt = 0;
    while (true) {
      string t;
      getline(cin, t);
      if (t == "") break;
      for (int i = 0; i < t.size(); i++) {
        s[t.at(i)]++;
      }
      cnt++;
    }
    
    for (char i = 'a'; i <= 'z'; i++) {
      if (s[i] == cnt) ans++;
    }
  }

  cout << ans << endl;
}