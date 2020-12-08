#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<pair<string, int>> inst;
  vector<bool> visited;
  while (!cin.eof()) {
    string k, v; cin >> k >> v;
    inst.push_back(make_pair(k, stoi(v)));
    visited.push_back(false);
  }

  int ans = 0;
  int i = 0;
  while (i < inst.size()) {
    if (visited[i]) break;
    visited[i] = true;
    if (inst[i].first == "acc") {
      ans += inst[i].second;
    }
    if (inst[i].first == "jmp") {
      i += inst[i].second;
      continue;
    }
    i++;
  }

  cout << ans << endl;
}