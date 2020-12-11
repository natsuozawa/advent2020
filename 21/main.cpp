#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> G; // grid
vector<vector<int>> A; // adjacent
int H, W;

int main() {
  while (!cin.eof()) {
    string s; cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
      if (s.at(i) == 'L') v.push_back(1);
      else v.push_back(0);
    }
    G.push_back(v);
  }

  H = G.size();
  W = G[0].size();
  
  A.resize(H);
  for (int i = 0; i < H; i++) A[i].resize(W);

  while (true) {
    bool f = true;

    // update 
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (G[i][j] == 1 && A[i][j] == 0) {
          f = false;
          G[i][j] = 2;
        }
        if (G[i][j] == 2 && A[i][j] >= 4) {
          f = false;
          G[i][j] = 1;
        }
      }
    }
    if (f) break;

    // evaluate adjacency
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        A[i][j] = 0;
        if (i > 0 && G[i - 1][j] > 1) A[i][j]++;
        if (i < H - 1 && G[i + 1][j] > 1) A[i][j]++;
        if (j > 0 && G[i][j - 1] > 1) A[i][j]++;
        if (j < W - 1 && G[i][j + 1] > 1) A[i][j]++;
        if (i > 0 && j > 0 && G[i - 1][j - 1] > 1) A[i][j]++;
        if (i < H - 1 && j > 0 && G[i + 1][j - 1] > 1) A[i][j]++;
        if (i > 0 && j < W - 1 && G[i - 1][j + 1] > 1) A[i][j]++;
        if (i < H - 1 && j < W - 1 && G[i + 1][j + 1] > 1) A[i][j]++;
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (G[i][j] == 2) ans++;
    }
  }
  cout << ans << endl;
}