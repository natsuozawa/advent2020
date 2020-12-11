#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> G; // grid
vector<vector<int>> A; // adjacent
int H, W, N;

int main() {
  while (!cin.eof()) {
    string s; cin >> s;
    if (s == "-1") break;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
      if (s.at(i) == 'L') v.push_back(1);
      else v.push_back(0);
    }
    G.push_back(v);
  }

  H = G.size();
  W = G[0].size();
  N = max(H, W);
  
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
        if (G[i][j] == 2 && A[i][j] >= 5) {
          f = false;
          G[i][j] = 1;
        }
      }
    }
    if (f) break;

    // evaluate adjacency O(HW*max(H, W)) 
    // could be made efficient by making a graph in the beginning but we don't need to optimize prematurely
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        A[i][j] = 0;
        for (int a = i - 1; a >= 0; a--) {
          if (G[a][j] > 1) A[i][j]++;
          if (G[a][j] >= 1) break;
        }
        for (int a = i + 1; a < H; a++) {
          if (G[a][j] > 1) A[i][j]++;
          if (G[a][j] >= 1) break;
        }
        for (int b = j - 1; b >= 0; b--) {
          if (G[i][b] > 1) A[i][j]++;
          if (G[i][b] >= 1) break;
        }
        for (int b = j + 1; b < W; b++) {
          if (G[i][b] > 1) A[i][j]++;
          if (G[i][b] >= 1) break;
        }
        for (int k = 1; k < N; k++) {
          if (i - k < 0 || j - k < 0) break;
          if (G[i - k][j - k] > 1) A[i][j]++;
          if (G[i - k][j - k] >= 1) break;
        }
        for (int k = 1; k < N; k++) {
          if (i + k >= H || j - k < 0) break;
          if (G[i + k][j - k] > 1) A[i][j]++;
          if (G[i + k][j - k] >= 1) break;
        }
        for (int k = 1; k < N; k++) {
          if (i - k < 0 || j + k >= W) break;
          if (G[i - k][j + k] > 1) A[i][j]++;
          if (G[i - k][j + k] >= 1) break;
        }
        for (int k = 1; k < N; k++) {
          if (i + k >= H || j + k >= W) break;
          if (G[i + k][j + k] > 1) A[i][j]++;
          if (G[i + k][j + k] >= 1) break;
        }
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