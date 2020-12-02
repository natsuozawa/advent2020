#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int n;
  while (true) {
    cin >> n;
    if (n == -1) break;
    v.push_back(n);
  }

  int ans;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        if (i != j && j != k && i != k && v[i] + v[j] + v[k] == 2020) {
          ans = v[i] * v[j] * v[k];
          break;
        }
      }
    }
  }
  cout << ans << endl;
}