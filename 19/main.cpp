#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> a;
  while (!cin.eof()) {
    int n; cin >> n;
    a.push_back(n);
  }

  sort(a.begin(), a.end());

  int prev = 0;
  int cnt[4];
  fill(cnt, cnt + 4, 0);

  for (int i = 0; i < a.size(); i++) {
    int diff = a[i] - prev;
    cnt[diff]++;
    prev = a[i];
  }

  cnt[3]++; // for the last adapter to the device
  
  cout << cnt[1] * cnt[3] << endl;
}