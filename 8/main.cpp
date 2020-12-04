#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

bool is_int(string s) {
  for (char x : s) {
    if ('0' > x || x > '9') return false;
  }
  return true;
}

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

  void set(string k, string v) {
    bool f = is_int(v);
    if (k == "byr") {
      m[k] = is_int(v) && 1920 <= stoi(v) && stoi(v) <= 2002;
    } else if (k == "iyr") {
      m[k] = is_int(v) && 2010 <= stoi(v) && stoi(v) <= 2020;
    } else if (k == "eyr") {
      m[k] = is_int(v) && 2020 <= stoi(v) && stoi(v) <= 2030;
    } else if (k == "hgt") {
      string h = v.substr(0, v.size() - 2);
      if (!is_int(h) || v.size() < 3) return;
      int height = stoi(h);
      if (v.substr(v.size() - 2, 2) == "cm") {
        m[k] = 150 <= height && height <= 193;
      } else if (v.substr(v.size() - 2, 2) == "in") {
        m[k] = 59 <= height && height <= 76;
      }
    } else if (k == "hcl") {
      bool valid = v.size() == 7 && v.at(0) == '#';
      if (valid) {
        for (int i = 1; i < 7; i++) valid = valid && ('0' <= v.at(i) && v.at(i) <= '9') || ('a' <= v.at(i) && v.at(i) <= 'f');
      }
      m[k] = valid;
    } else if (k == "ecl") {
      m[k] = v == "amb" || v == "blu" || v == "brn" || v == "gry" || v == "grn" || v == "hzl" || v == "oth";
    } else if (k == "pid") {
      m[k] = v.size() == 9 && is_int(v);
    }
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
        p.set(t.substr(0, 3), t.substr(4, t.size() - 4));
      }

      i++;
    }
    if (p.validate()) ans++;
  }

  cout << ans << endl;
}