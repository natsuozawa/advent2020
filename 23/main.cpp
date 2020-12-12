#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<char> cmd;
  vector<int> val;
  while (!cin.eof()) {
    string s; cin >> s;
    cmd.push_back(s.at(0));
    val.push_back(stoi(s.substr(1, s.size() - 1)));
  }

  int dir = 0;
  int east = 0;
  int north = 0;
  for (int i = 0; i < cmd.size(); i++) {
    if (cmd[i] == 'N') north += val[i];
    else if (cmd[i] == 'E') east += val[i];
    else if (cmd[i] == 'S') north -= val[i];
    else if (cmd[i] == 'W') east -= val[i];
    else if (cmd[i] == 'L') dir = (dir - val[i] + 360) % 360;
    else if (cmd[i] == 'R') dir = (dir + val[i]) % 360;
    else if (cmd[i] == 'F') {
      if (dir == 0) east += val[i];
      else if (dir == 90) north -= val[i];
      else if (dir == 180) east -= val[i];
      else if (dir == 270) north += val[i];
    }
  }

  int ans = abs(east) + abs(north);
  cout << ans << endl;
}