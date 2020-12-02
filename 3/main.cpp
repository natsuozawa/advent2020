#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int ans = 0;
  while (true) {
    string s; cin >> s;
    if (s == "-1") break;

    int lo, hi;
    for (int i = 1; i < s.size(); i++) {
      if (s.at(i) == '-') {
        lo = stoi(s.substr(0, i));
        hi = stoi(s.substr(i + 1, s.size() - i - 1));
      }
    }
    
    string t; cin >> t; 
    string r; cin >> r;

    char l = t.at(0);
    int cnt = 0;
    for (int i = 0; i < r.size(); i++) {
      if (r.at(i) == l) cnt++;
    }

    if (lo <= cnt && cnt <= hi) ans++;
  }

  cout << ans << endl;  
}