#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> a;
  a.push_back(0);
  while (!cin.eof()) {
    int n; cin >> n;
    a.push_back(n);
  }

  sort(a.begin(), a.end());

  int N = a.size();
  vector<long long> dp(N + 1); // (the source = 0), 1, ..., n - 1, (the adapter=n)
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i - 1]; 
    if (i > 1 && a[i] - a[i - 2] <= 3) dp[i] += dp[i - 2];
    if (i > 2 && a[i] - a[i - 3] <= 3) dp[i] += dp[i - 3];
  }
  dp[N] = dp[N - 1];

  cout << dp[N] << endl;
}