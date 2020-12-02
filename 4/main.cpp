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
    
    if (hi > r.size()) continue;
    bool left = r.at(lo - 1) == l;
    bool right = r.at(hi - 1) == l;

    if (left ^ right) ans++;
  }

  cout << ans << endl;  
}