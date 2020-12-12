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

  int east = 0;
  int north = 0;
  int we = 10;
  int wn = 1;
  auto rot = [&](int deg) {
    if (deg % 180 != 0) swap(we, wn);
    if (deg == 90 || deg == 180) wn *= -1;
    if (deg == 270 || deg == 180) we *= -1;
  };

  for (int i = 0; i < cmd.size(); i++) {
    if (cmd[i] == 'N') wn += val[i];
    else if (cmd[i] == 'E') we += val[i];
    else if (cmd[i] == 'S') wn -= val[i];
    else if (cmd[i] == 'W') we -= val[i];
    else if (cmd[i] == 'L') rot(360 - val[i] % 360);
    else if (cmd[i] == 'R') rot(val[i] % 360);
    else if (cmd[i] == 'F') {
      east += we * val[i];
      north += wn * val[i];
    } 
  }

  int ans = abs(east) + abs(north);
  cout << ans << endl;
}