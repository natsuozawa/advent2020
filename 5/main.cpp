#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> grid;
  int i = 0;
  while (true) {
    string s; cin >> s;
    if (s == "-1") break;
    grid.push_back({});
    for (int j = 0; j < s.size(); j++) {
      grid[i].push_back(s.at(j) == '.' ? 0 : 1);
    }
    i++; 
  }

  int dx = 3;
  int dy = 1;

  int r = dy;
  int c = dx;
  
  int rmax = i;
  int cmax = grid[0].size();

  int ans = 0;
  while (r < rmax) {
    if (grid[r][c]) ans++;
    r += dy;
    c += dx;
    c %= cmax; 
  }
  
  cout << ans << endl;
}