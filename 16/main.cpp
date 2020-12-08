#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(vector<pair<string, int>>& inst) {
  vector<bool> visited(inst.size());
  fill(visited.begin(), visited.end(), false);

  int ans = 0;
  int i = 0;
  while (i < inst.size()) {
    if (i < 0) break;
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

  if (i != inst.size()) return -1;
  return ans;
}

int main() {
  vector<pair<string, int>> inst;
  while (!cin.eof()) {
    string k, v; cin >> k >> v;
    inst.push_back(make_pair(k, stoi(v)));
  }

  int ans = -1;
  for (int i = 0; i < inst.size(); i++) {
    if (inst[i].first == "jmp") {
      inst[i].first = "nop";
      ans = solve(inst);
      inst[i].first = "jmp";
    } else if (inst[i].first == "nop") {
      inst[i].first = "jmp";
      ans = solve(inst);
      inst[i] .first = "nop";
    }
    if (ans > 0) {
      cout << ans << endl;
      break;
    }
  }
}