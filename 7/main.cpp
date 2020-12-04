#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct Passport {
  map<string, bool> m;

  Passport() {
    m["byr"] = false;
    m["iyr"] = false;
    m["eyr"] = false;
    m["hgt"] = false;
    m["hcl"] = false;
    m["ecl"] = false;
    m["pid"] = false;
  }

  bool& operator[](string t) {
    return m[t];
  }

  bool validate() {
    bool res = true;
    for (pair<string, bool> b : m) {
      res = res && b.second;
    }
    return res;
  }
};

int main() {
  int ans = 0;
  while (!cin.eof()) {
    vector<string> s;
    int i = 0;

    Passport p;

    while (true) {
      s.push_back("");
      getline(cin, s[i]);
      if (s[i].empty()) break;

      istringstream stream(s[i]);
      while (true) {
        string t;
        stream >> t;
        if (t.empty()) break;
        p[t.substr(0, 3)] = true;
      }

      i++;
    }
    if (p.validate()) ans++;
  }

  cout << ans << endl;
}