#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;

long long solve(int dx, int dy) {
  int r = dy;
  int c = dx;
  
  int rmax = grid.size();
  int cmax = grid[0].size();

  int ans = 0;
  while (r < rmax) {
    if (grid[r][c]) ans++;
    r += dy;
    c += dx;
    c %= cmax; 
  }
  
  return ans;
}

int main() {
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

  long long ans = solve(1, 1) * solve(3, 1) * solve(5, 1) * solve(7, 1) * solve(1, 2);
  cout << ans << endl;
}